cmake_minimum_required(VERSION 3.10.0)

project(math_problem)

# For Debug
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
	set(CMAKE_CXX_FLAGS_DEBUG "-g")
endif()

# For Release
if(CMAKE_BUILD_TYPE STREQUAL "Release")
	set(CMAKE_CXX_FLAGS_RELEASE "-O2")
endif()

add_library(
	lib_mymath_static STATIC
	mymath.cpp
	mymath.h
)

add_library(
	lib_mymath_dynamic SHARED
	mymath.cpp
	mymath.h
)

# For dynamic exec
add_executable(dynamic_exec main.cpp)
target_link_libraries(dynamic_exec lib_mymath_dynamic)

# For static exec
add_executable(static_exec main.cpp)
target_link_libraries(static_exec lib_mymath_static)
