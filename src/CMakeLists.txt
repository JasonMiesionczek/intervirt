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
    DEPENDS ${PROJECT_SOURCE_DIR}/src/daemon/server.spec
)

add_custom_target(
    GenerateStubServer ALL
    DEPENDS ${PROJECT_SOURCE_DIR}/src/daemon/abstractstubserver.h
)

add_custom_command(
    OUTPUT rpcclient.h
    COMMAND jsonrpcstub ${PROJECT_SOURCE_DIR}/src/daemon/server.spec --cpp-client=RpcClient
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/src/shell
    DEPENDS ${PROJECT_SOURCE_DIR}/src/daemon/server.spec
)

add_custom_target(
    GenerateRpcClient ALL
    DEPENDS ${PROJECT_SOURCE_DIR}/src/shell/rpcclient.h
)

set(JSONRPC jsoncpp microhttpd jsonrpccpp-common jsonrpccpp-server jsonrpccpp-client)
set(WSMAN wsman wsman_client wsman_clientpp wsman_curl_client_transport)
set(LIBS ${LIBS} ${LIBXML2_LIBRARIES} ${LibXML++_LIBRARIES} ${JSONRPC} ${WSMAN} crypto pthread docopt curl)
file (GLOB_RECURSE DAEMON_SOURCES daemon/*.cpp)
file (GLOB_RECURSE DRIVER_SOURCES drivers/*.cpp)
file (GLOB_RECURSE OBJECT_SOURCES objects/*.cpp)
add_executable (intervirtd ${DAEMON_SOURCES} ${DRIVER_SOURCES} ${OBJECT_SOURCES})
add_dependencies(intervirtd GenerateStubServer)
target_link_libraries (intervirtd ${LIBS})

file (GLOB_RECURSE SHELL_SOURCES shell/*.cpp)
add_executable (ivsh ${SHELL_SOURCES} ${OBJECT_SOURCES})
add_dependencies(ivsh GenerateRpcClient)
target_link_libraries (ivsh ${LIBS})

file (GLOB TEST_SOURCES test.cpp)
add_executable (esxtest ${TEST_SOURCES})
target_link_libraries (esxtest ${LIBXML2_LIBRARIES} ${LibXML++_LIBRARIES} curl)

file (GLOB KVMTEST_SOURCES kvmtest.cpp)
add_executable(kvmtest ${KVMTEST_SOURCES})
target_link_libraries(kvmtest sqlite3)
