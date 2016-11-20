include_directories(
    ${PROJECT_SOURCE_DIR}/src
)
add_custom_command(
    OUTPUT abstractstubserver.h
    COMMAND jsonrpcstub server.spec --cpp-server=AbstractStubServer
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/src/daemon
)
file (GLOB_RECURSE DAEMON_SOURCES daemon/*.cpp)
file (GLOB_RECURSE DRIVER_SOURCES drivers/*.cpp)
add_executable (intervirtd ${DAEMON_SOURCES} ${DRIVER_SOURCES} abstractstubserver.h)
target_link_libraries (intervirtd jsoncpp microhttpd jsonrpccpp-common jsonrpccpp-server)
