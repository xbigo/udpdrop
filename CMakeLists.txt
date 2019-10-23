cmake_minimum_required(VERSION 3.0.0)
project(udpdrop VERSION 0.1.0)

include(CTest)
enable_testing()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set (CMAKE_CXX_STANDARD 17)

find_package(Boost REQUIRED COMPONENTS 
    unit_test_framework
)

file(GLOB_RECURSE lib_headers  CONFIGURE_DEPENDS
    ${PROJECT_SOURCE_DIR}/include/udpdrop/*.hpp
    )

file(GLOB_RECURSE lib_sources  CONFIGURE_DEPENDS
    ${PROJECT_SOURCE_DIR}/src/udpdrop/*.cpp)

set(include_dir ${PROJECT_SOURCE_DIR}/include/)

add_library(udpdrop SHARED ${lib_headers} ${lib_sources})
target_include_directories(udpdrop  PRIVATE ${include_dir})

file(GLOB_RECURSE test_sources CONFIGURE_DEPENDS
    ${PROJECT_SOURCE_DIR}/test/udpdrop/*.cpp
    ${PROJECT_SOURCE_DIR}/test/udpdrop/*.hpp
)

add_executable(udpdrop_ut ${test_sources})

target_include_directories(udpdrop_ut PRIVATE ${BOOST_INCLUDE_DIRS} ${include_dir})
target_compile_definitions(udpdrop_ut PRIVATE "BOOST_TEST_DYN_LINK=1")
target_link_libraries(udpdrop_ut ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

add_test(NAME unit_test COMMAND udpdrop_ut --run_test=*/case_*)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
