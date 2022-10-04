cmake_minimum_required(VERSION 3.16)

# Setup duktape
execute_process(
  COMMAND git submodule init
  COMMAND git submodule update 
  WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}  
)

execute_process(
  COMMAND make -C projects/make
  WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/wren
)

set(WREN_DIR ${CMAKE_CURRENT_LIST_DIR}/wren)

# Add miniSystem library target
project(miniSystem)

# miniSystem library src
add_subdirectory(src)