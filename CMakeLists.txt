cmake_minimum_required(VERSION 3.16)

# Setup duktape
execute_process(
  COMMAND git submodule init
  COMMAND git submodule update 
  WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}  
)

# Add duktape library target
project(duktape)

add_library(duktape
  duk_src/duktape.c
)

target_include_directories(duktape PUBLIC duk_src)

# miniSystem library src
add_subdirectory(src)