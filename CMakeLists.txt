cmake_minimum_required(VERSION 3.17)

project(c_http_server)
set(CMAKE_C_STANDARD 99)
add_executable(httpServer http_server.c utils.c)