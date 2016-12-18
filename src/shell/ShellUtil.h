#ifndef SHELLUTIL_H
#define SHELLUTIL_H

class ShellUtil {
public:
  static std::string capturePassword(std::string prompt) {
    termios oldt;
    tcgetattr(STDIN_FILENO, &oldt);
    termios newt = oldt;
    newt.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    std::cout << std::endl << prompt;
    std::string s;
    std::getline(std::cin, s);
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return s;
  }
};

#endif /* SHELLUTIL_H */
