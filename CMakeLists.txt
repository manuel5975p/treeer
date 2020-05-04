cmake_minimum_required(VERSION 3.14)
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
	Catch2
	GIT_REPOSITORY https://github.com/catchorg/Catch2.git
	GIT_TAG        v2.11.3
)
FetchContent_MakeAvailable(Catch2)

add_executable(treeer_test
	test/test.cpp
	test/treeer.cpp
)
target_link_libraries(treeer_test
	treeer
	Catch2::Catch2
)
