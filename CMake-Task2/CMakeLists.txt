cmake_minimum_required(VERSION 3.10.7)

set(CMAKE_CXX_STANDARD 17)

project(validate_time)

include(ExternalProject)

set(boost_URL "http://sourceforge.net/projects/boost/files/boost/1.63.0/boost_1_63_0.tar.bz2")
set(boost_SHA1 "9f1dd4fa364a3e3156a77dc17aa562ef06404ff6")
set(boost_INSTALL ${CMAKE_CURRENT_BINARY_DIR}/third_party/boost)
set(boost_INCLUDE_DIR ${boost_INSTALL}/include)
set(boost_LIB_DIR ${boost_INSTALL}/lib)

ExternalProject_Add(external_boost
	PREFIX boost
	URL ${boost_URL}
	URL_HASH SHA1=${boost_SHA1}
	BUILD_IN_SOURCE 1
	CONFIGURE_COMMAND ./bootstrap.sh
	--with-libraries=filesystem
	--with-libraries=system
	--with-libraries=date_time
	--prefix=<INSTALL_DIR>
	BUILD_COMMAND
	./b2 install link=static variant=release threading=multi runtime-link=static
	INSTALL_COMMAND ""
	INSTALL_DIR ${boost_INSTALL})

file(GLOB SOURCES *.cpp *.h)
add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} PRIVATE pthread)

set(SOURCES
	main.cpp
	validate_hardware_timestamp.cpp
	validate_hardware_timestamp.h
)
