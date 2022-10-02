# Add miniSystem library target
project(miniSystem)

# The core
add_subdirectory(core)

# Insert you features below this line

# Console interface
add_subdirectory(console)

target_include_directories(miniSystem PUBLIC src duk_src)
target_link_libraries(miniSystem PUBLIC duktape)
