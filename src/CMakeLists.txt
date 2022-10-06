project(wren)

add_library(wren INTERFACE)

target_include_directories(wren INTERFACE ${WREN_DIR}/src/include)
target_link_libraries(wren INTERFACE ${WREN_DIR}/lib/libwren.a)

# The core
add_library(miniSystem 
    miniSystem.cpp
    fs.cpp
    stream.cpp
)

target_include_directories(miniSystem PUBLIC 
    .
)
target_link_libraries(miniSystem PUBLIC 
    wren
)
