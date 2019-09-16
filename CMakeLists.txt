cmake_minimum_required(VERSION 3.0.0)
project(udpdrop VERSION 0.1.0)

include(CTest)
enable_testing()

set (CMAKE_CXX_STANDARD 17)


file(GLOB_RECURSE lib_headers 
    ${PROJECT_SOURCE_DIR}/include/udpdrop/*.hpp
    )

file(GLOB_RECURSE lib_sources 
    ${PROJECT_SOURCE_DIR}/src/udpdrop/*.cpp)

set(include_dir ${PROJECT_SOURCE_DIR}/include/)

add_library(udpdrop SHARED ${lib_headers} ${lib_sources})
set_target_properties(udpdrop  PROPERTIES INCLUDE_DIRECTORIES ${include_dir})



set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
