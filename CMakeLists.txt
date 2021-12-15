cmake_minimum_required(VERSION 3.17)
project(SubView C)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c)
add_executable(SubView ${SOURCE_FILES})

INCLUDE_DIRECTORIES(  /usr/local/Cellar/allegro/5.2.7.0/include )
LINK_DIRECTORIES(  /usr/local/Cellar/allegro/5.2.7.0/lib )

file(GLOB LIBRARIES "/usr/local/Cellar/allegro/5.2.7.0/lib/*.dylib")
message("LIBRARIES = ${LIBRARIES}")

TARGET_LINK_LIBRARIES(SubView  ${LIBRARIES})