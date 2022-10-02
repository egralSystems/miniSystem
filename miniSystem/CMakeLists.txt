# Add miniSystem library target
project(miniSystem)

# Insert you features below this line



# The core
add_subdirectory(core)

target_include_directories(miniSystem PUBLIC src duk_src)
target_link_libraries(miniSystem PUBLIC duktape)
