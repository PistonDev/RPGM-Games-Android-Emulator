cmake_minimum_required(VERSION 3.20)

project(
	RPGMAndroidEmulator
	VERSION 0.1.0
	LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(
	RPGMAndroidEmulator
	src/main.cpp
)

target_include_directories(
	RPGMAndroidEmulator
	PRIVATE
	external/raylib/include
)

target_link_directories(
	RPGMAndroidEmulator
	PRIVATE
	external/raylib/lib
)

target_link_libraries(
	RPGMAndroidEmulator
	PRIVATE
	raylib
	opengl32
	gdi32
	winmm
)

target_compile_options(
	RPGMAndroidEmulator
	PRIVATE
	-Wall
	-Wextra
)