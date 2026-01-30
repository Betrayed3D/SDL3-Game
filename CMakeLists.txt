cmake_minimum_required(VERSION 3.10.0)

project(SDLGame VERSION 1.0.0)

include_directories("./includes" "C:/Users/Marcus/Documents/Linking/SDL3/x86_64-w64-mingw32/include")
link_directories("C:/Users/Marcus/Documents/Linking/SDL3/x86_64-w64-mingw32/lib")

set(SDL3_DIR "C:/Users/Marcus/Documents/Linking/SDL3/cmake")

find_package(SDL3 REQUIRED)

add_executable(SDLGame "./source/main.cpp" "./source/Screen.cpp" "./source/Game.cpp")

target_link_libraries(SDLGame PRIVATE SDL3::SDL3)