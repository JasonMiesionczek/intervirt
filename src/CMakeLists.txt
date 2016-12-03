include_directories(
    ${PROJECT_SOURCE_DIR}/src
    ${LibXML++_INCLUDE_DIRS}
    ${LIBXML2_INCLUDE_DIR}
    /usr/include/openwsman
)
add_custom_command(
    OUTPUT abstractstubserver.h
    COMMAND jsonrpcstub server.spec --cpp-server=AbstractStubServer
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/src/daemon
)

add_custom_command(
    OUTPUT RpcClient.h
    COMMAND jsonrpcstub ${PROJECT_SOURCE_DIR}/src/daemon/server.spec --cpp-client=RpcClient
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/src/shell
)

set(JSONRPC jsoncpp microhttpd jsonrpccpp-common jsonrpccpp-server jsonrpccpp-client)
set(WSMAN wsman wsman_client wsman_clientpp wsman_curl_client_transport)
set(LIBS ${LIBS} ${LIBXML2_LIBRARIES} ${LibXML++_LIBRARIES} ${JSONRPC} ${WSMAN} crypto pthread docopt)
file (GLOB_RECURSE DAEMON_SOURCES daemon/*.cpp)
file (GLOB_RECURSE DRIVER_SOURCES drivers/*.cpp)
file (GLOB_RECURSE OBJECT_SOURCES objects/*.cpp)
add_executable (intervirtd ${DAEMON_SOURCES} ${DRIVER_SOURCES} ${OBJECT_SOURCES} abstractstubserver.h)
target_link_libraries (intervirtd ${LIBS})

file (GLOB_RECURSE SHELL_SOURCES shell/*.cpp)
add_executable (ivsh ${SHELL_SOURCES} ${OBJECT_SOURCES} RpcClient.h)
target_link_libraries (ivsh ${LIBS})
