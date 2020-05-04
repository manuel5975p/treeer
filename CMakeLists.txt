cmake_minimum_required(VERSION 3.11)
project(treeer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(treeer src/treeer.cpp)
target_include_directories(treeer
	PUBLIC
		"${CMAKE_CURRENT_LIST_DIR}/include"
)


include(FetchContent)

FetchContent_Declare(
	catch2
	GIT_REPOSITORY https://github.com/catchorg/Catch2.git
	GIT_TAG        v2.11.3
)
FetchContent_GetProperties(catch2)
if(NOT catch2_POPULATED)
  FetchContent_Populate(catch2)
  add_subdirectory(${catch2_SOURCE_DIR} ${catch2_BINARY_DIR})
endif()

add_executable(treeer_test
	test/test.cpp
	test/treeer.cpp
)
target_link_libraries(treeer_test
	treeer
	Catch2::Catch2
)
