#include <common/util.h>
#include <cstdio>
#include <cstdlib>
#include <fcntl.h>
#include <glob.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/wait.h>
#include <sqlite3.h>


/*

how to deal with existing libvirt VMs:
option 1: incorporate libvirt into intervirt, only to control existing VMs.
            this could be as simple as running virsh from the command line and
sending commands
            to the VM.

 */

std::vector<std::string>
glob(const std::string& pat)
{
  using namespace std;
  glob_t glob_result;
  glob(pat.c_str(), GLOB_TILDE, NULL, &glob_result);
  vector<string> ret;
  for (unsigned int i = 0; i < glob_result.gl_pathc; ++i) {
    ret.push_back(string(glob_result.gl_pathv[i]));
  }
  globfree(&glob_result);
  return ret;
}

static int callback(void *NotUsed, int argc, char **argv, char **azColName){
   int i;
   for(i=0; i<argc; i++){
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

int
main(int argc, char* argv[])
{
  sqlite3 *db;
  auto rc = sqlite3_open("test.db", &db);
  if (rc) {
      std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
  }
  char *zErrMsg = 0;
  auto sql = "CREATE TABLE VirtualMachines (" \
      "NAME CHAR(100) NOT NULL," \
      "UUID CHAR(36) NOT NULL," \
      "STATE CHAR(50) NOT NULL);";
  rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
  sql = "INSERT INTO VirtualMachines (NAME, UUID, STATE) VALUES ('test vm', '9e22fd32-ce2b-11e6-be4a-68f7284e7bac', 'on');";
  rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
  if (rc != SQLITE_OK) {
      std::cerr << zErrMsg << std::endl;
      sqlite3_free(zErrMsg);
  }
  sql = "SELECT * FROM VirtualMachines";
  const char *data = "Callback function called";
  rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);
  if (rc != SQLITE_OK) {
      std::cerr << zErrMsg << std::endl;
      sqlite3_free(zErrMsg);
  }
  // get inactive vms
  auto vms = glob("/etc/libvirt/qemu/*.xml");
  for (auto& vm : vms) {
    std::cout << vm << "\n";
  }

  // get active (running) vms
  auto activeVms = glob("/var/run/libvirt/qemu/*.xml");
  for (auto& vm : activeVms) {
    std::cout << vm << "\n";
  }

  std::string cmd = "/usr/bin/virsh";
  // virsh -c qemu:///system list --all
  pid_t pid = fork();
  int status;
  switch (pid) {
    case -1:
      perror("fork");
      exit(1);
    case 0:
      execl(cmd.c_str(), cmd.c_str(), "-c", "qemu:///system", "list", "--all",
            (char*)0);
      perror("execl");
      exit(1);
    default:
      while (-1 == waitpid(pid, &status, 0))
        ;
      if (!WIFEXITED(status) || WEXITSTATUS(status) != 0) {
        std::cerr << "process " << cmd << " (pid=" << pid << ") failed"
                  << "\n";
      }
      break;
  }

  sqlite3_close(db);

  return 0;
}
