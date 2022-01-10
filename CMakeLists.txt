cmake_minimum_required(VERSION 3.17)
project(SubView C)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c)
add_executable(SubView ${SOURCE_FILES})


#link allegro
INCLUDE_DIRECTORIES(  /opt/homebrew/Cellar/allegro/5.2.7.0/include )
LINK_DIRECTORIES(  /opt/homebrew/Cellar/allegro/5.2.7.0/lib )

file(GLOB LIBRARIES "/opt/homebrew/Cellar/allegro/5.2.7.0/lib/*.dylib")
message("LIBRARIES = ${LIBRARIES}")

TARGET_LINK_LIBRARIES(SubView  ${LIBRARIES})


#link curl
include_directories(/usr/local/Cellar/curl/7.80.0_1/include)
set(CURL_LIBRARY "-lcurl")
find_package(CURL REQUIRED)

include_directories(${CURL_INCLUDE_DIR})
TARGET_LINK_LIBRARIES(SubView ${CURL_LIBRARIES})


#link json-c
INCLUDE_DIRECTORIES(  /opt/homebrew/Cellar/json-c/0.15/include )
LINK_DIRECTORIES(  /opt/homebrew/Cellar/json-c/0.15/lib )

file(GLOB LIBRARIES "/opt/homebrew/Cellar/json-c/0.15/lib/*.dylib")
message("LIBRARIES = ${LIBRARIES}")

TARGET_LINK_LIBRARIES(SubView  ${LIBRARIES})
