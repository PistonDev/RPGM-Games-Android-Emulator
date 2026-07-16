cmake_minimum_required(VERSION 3.20)

project(
	RPGMAndroidEmulator
	VERSION 0.1.0
	LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set (
	SOURCES
	src/main.cpp
	src/system/extractor.cpp
)

add_executable(
	RPGMAndroidEmulator
	${SOURCES}
)

find_package(libzip CONFIG REQUIRED)

target_include_directories(
	RPGMAndroidEmulator
	PRIVATE
	external/raylib/include
)

target_link_directories(
	RPGMAndroidEmulator
	PRIVATE
	external/raylib/lib
	libzip::zip
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