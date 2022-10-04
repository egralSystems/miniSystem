# The core
add_subdirectory(core)

# Insert you features below this line

# Stream interface
add_subdirectory(stream)

target_include_directories(miniSystem PUBLIC 
    src 
    ../wren/src/include
)
target_link_libraries(miniSystem PUBLIC 
    ../wren/lib/libwren.a    

    stream
    console
)
