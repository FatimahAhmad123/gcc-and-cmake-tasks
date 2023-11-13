cmake_minimum_required(VERSION 3.12)

project(validate_time)

include(ExternalProject)

ExternalProject_Add(
	boost
	PREFIX ${CMAKE_CURRENT_BINARY_DIR}/boost
	GIT_REPOSITORY https://github.com/boostorg/boost.git
	GIT_TAG "boost-1.78.0"
	CONFIGURE_COMMAND ""
	BUILD_COMMAND bjam --with-date_time --with-system toolset=gcc variant=debug link=static install --prefix=${CMAKE_CURRENT_BINARY_DIR}/boostinstall
	BUILD_IN_SOURCE 1
	INSTALL_COMMAND ""
)

set(Boost_INCLUDE_DIRS ${CMAKE_CURRENT_BINARY_DIR}/boostinstall/include)
set(Boost_LIBRARIES
	${CMAKE_CURRENT_BINARY_DIR}/boostinstall/lib/libboost_date_time.a
	${CMAKE_CURRENT_BINARY_DIR}/boostinstall/lib/libboost_system.a
)

file(GLOB SOURCES *.cpp *.h)
add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ${Boost_INCLUDE_DIRS})
target_link_libraries(validate_time ${Boost_LIBRARIES}
	pthread)