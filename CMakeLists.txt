cmake_minimum_required(VERSION 3.16)

# Setup duktape
execute_process(
  COMMAND sh ${CMAKE_CURRENT_LIST_DIR}/setup.sh
  WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}  
)

# Add duktape library target
project(duktape)

add_library(duktape
  duk_src/duktape.c
)

target_include_directories(duktape PUBLIC duk_src)

# Add miniSystem library target
project(miniSystem)

add_library(miniSystem
  src/miniSystem.cpp
)

target_include_directories(miniSystem PUBLIC src duk_src)
target_link_libraries(miniSystem PUBLIC duktape)

# ports
add_subdirectory(ports)