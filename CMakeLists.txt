cmake_minimum_required(VERSION 3.6)

project(otusPrintIp)

set(SOURCE 
        my_ctype.cpp
        printtIP.cpp
)

set(HEADERS
        my_ctype.hpp
        printIp.cpp
)

add_executable(printIP ${SOURCES} ${HEADERS})

set_target_properties(printIP 
PROPERTIES
CXX_STANDARD 17
CXX_STANDARD_REQUIRED ON
)