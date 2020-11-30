cmake_minimum_required(VERSION 3.6)

project(otusPrintIp)

add_executable(ip_filter main.cpp)

target_include_directories(ip_filter 
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/ctype
    ${CMAKE_CURRENT_SOURCE_DIR}/print
)

set_target_properties(ip_filter 
    PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)