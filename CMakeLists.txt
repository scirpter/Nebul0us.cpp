cmake_minimum_required(VERSION 3.20)
project(Nebul0us
    VERSION 0.1.0
    LANGUAGES CXX
)

set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

# git commit embed
include(scripts/git.cmake)

file(GLOB_RECURSE SRC_MAIN
    "${SRC_DIR}/**.hpp"
    "${SRC_DIR}/**.h"
    "${SRC_DIR}/**.cpp"
    "${SRC_DIR}/**.cc"
    "${SRC_DIR}/**.cxx"
    "${SRC_DIR}/**.asm"
)

add_executable(${PROJECT_NAME} ${SRC_MAIN})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)
set_property(TARGET ${PROJECT_NAME} PROPERTY COMPILE_WARNING_AS_ERROR ON)

source_group(TREE ${SRC_DIR} PREFIX "src" FILES ${SRC_MAIN})

target_include_directories(${PROJECT_NAME} PRIVATE ${SRC_DIR})

target_precompile_headers(${PROJECT_NAME} PRIVATE "${SRC_DIR}/common.h")

include(CTest)
enable_testing()
include(CPack)
