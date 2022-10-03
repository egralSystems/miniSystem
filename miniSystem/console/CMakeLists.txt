project(console)

add_library(console 
    console.cpp
)

target_include_directories(console PUBLIC .)
target_link_libraries(console PUBLIC duktape stream)