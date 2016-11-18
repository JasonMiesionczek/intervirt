
# link_directories(
#     ${GTKMM_LIBRARY_DIRS} ${CAF_LIBRARY_DIRS})

# include_directories(
# ${GTKMM_INCLUDE_DIRS} "." ${CAF_INCLUDE_DIRS})

# message(STATUS ${CAF_LIBRARY_DIRS})

# file(GLOB_RECURSE LIB_COMMON_SOURCES common/*.cpp)
# file(GLOB_RECURSE LIB_COMMON_HEADERS common/*.h)
# file(STRINGS ${PROJECT_SOURCE_DIR}/src/filelist.txt GENERATED_FILES)
# add_library(common ${LIB_COMMON_SOURCES} ${LIB_COMMON_HEADERS} ${GENERATED_FILES}
#         common/data/repositories/custom/server_repository.cpp common/data/repositories/custom/server_repository.h
#         common/data/connection.cpp
#         common/data/repository.cpp
#         common/services/heartbeat.cpp
#         common/services/register.cpp
#         common/util/string.cpp
#         common/util/system.cpp
#         common/services/world_service.cpp common/services/world_service.h)
# set_target_properties(common PROPERTIES LINKER_LANGUAGE CXX)
#add_custom_command(TARGET common PRE_BUILD COMMAND ${PROJECT_SOURCE_DIR}/tools/devctl/devctl.py)
#add_dependencies(common generate)
#target_link_libraries(common pqxx pq caf_core_static caf_io_static pthread jsoncpp curl jsonrpccpp-common jsonrpccpp-client)

# file(GLOB_RECURSE APP_CORE_SOURCES core/*.cpp)
# file(GLOB APP_CORE_HEADERS core/*.h)
# add_library(core_lib ${APP_CORE_SOURCES} ${APP_CORE_HEADERS} core/process/proc_heartbeat.cpp core/process/proc_heartbeat.h core/process/proc_worldtimer.cpp core/process/proc_worldtimer.h)
# target_link_libraries(common)

# file(GLOB APP_NODE_SOURCES node/*.cc)
# file(GLOB APP_NODE_HEADERS node/*.h)
# add_library(node_lib ${APP_NODE_SOURCES} ${APP_NODE_HEADERS})
# target_link_libraries(common)

# file(GLOB ADMIN_SOURCES admin/*.cc)
# file(GLOB ADMIN_HEADERS admin/*.h)
# add_executable(admin ${ADMIN_SOURCES} ${ADMIN_HEADERS})
# target_link_libraries(admin ${GTKMM_LIBRARIES} common)

# add_executable(core core.cxx)
# target_link_libraries(core ${Boost_SYSTEM_LIBRARY} common core_lib caf_core_static caf_io_static pthread)

# add_executable(node node.cxx)
# target_link_libraries(node ${Boost_SYSTEM_LIBRARY} common node_lib)

# MESSAGE( STATUS "PROJECT_SOURCE_DIR is: " ${PROJECT_SOURCE_DIR} )
# file(GLOB APP_SOURCES  src/*.cxx)
# foreach(sourcefile ${APP_SOURCES})
#     MESSAGE( STATUS "sourcefile is: " ${sourcefile} )
#     string(REPLACE ".cxx" "" name ${sourcefile})
#     string(REPLACE ${PROJECT_SOURCE_DIR}"/" "" srcname ${sourcefile})
#     add_executable(${name} ${srcname})
#     target_link_libraries(${name} ${name}_lib)
# endforeach(sourcefile ${APP_SOURCES})
add_custom_command(
    OUTPUT abstractstubserver.h
    COMMAND jsonrpcstub server.spec --cpp-server=AbstractStubServer
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/src/daemon
)
file (GLOB_RECURSE DAEMON_SOURCES daemon/*.cpp)
# include_directories("lib")
add_executable (intervirtd ${DAEMON_SOURCES} abstractstubserver.h)
target_link_libraries (intervirtd jsoncpp microhttpd jsonrpccpp-common jsonrpccpp-server)
