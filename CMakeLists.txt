cmake_minimum_required(VERSION 3.20)

project(MerStal_OS C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

find_package(SDL3 REQUIRED)
find_package(SDL3_image REQUIRED)
find_package(SDL3_ttf REQUIRED)
add_executable(merstal_os
  src/main.c
  src/screens/main_menu.c
)

target_include_directories(merstal_os PRIVATE src)

target_link_libraries(merstal_os PRIVATE
SDL3::SDL3
SDL3_image::SDL3_image
SDL3_ttf::SDL3_ttf
)
