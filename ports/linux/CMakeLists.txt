project(miniSystem_Linux)

add_executable(miniSystem_Linux
  src/main.cpp
)

target_include_directories(miniSystem_Linux PUBLIC src)
target_link_libraries(miniSystem_Linux PUBLIC miniSystem)