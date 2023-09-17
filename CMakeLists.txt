cmake_minimum_required(VERSION 3.5)

project(LinuxEmbarque LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(LinuxEmbarque main.cpp)
find_package(CURL REQUIRED)
target_link_libraries(LinuxEmbarque CURL::libcurl)
