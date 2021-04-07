cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)

project( curve LANGUAGES CXX )

string( REGEX MATCH "cxx_std_11" HAS_CXX_11 ${CMAKE_CXX_COMPILE_FEATURES} )
if ( NOT HAS_CXX_11 )
	message( FATAL_ERROR "C++11 standard is minimum required." )
endif()

list( APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake )
include( StringUtils )

set( INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include )
set( SRC_DIR ${CMAKE_SOURCE_DIR}/src )
set( OUTPUT_DIR ${CMAKE_SOURCE_DIR}/bin )

file( GLOB HEADERS "${INCLUDE_DIR}/*.h" "${INCLUDE_DIR}/*.hpp" )
file( GLOB SOURCES "${SRC_DIR}/*.c" "${SRC_DIR}/*.cpp" )

set( LIB_HEADERS ${HEADERS} )
set( TEST_SOURCES "${SRC_DIR}/main.cpp" )
filter_regex( EXCLUDE "main" LIB_SOURCES ${SOURCES} )

set( PROJECT_SOURCES ${SOURCES} ${HEADERS} )

add_library( curve SHARED ${LIB_HEADERS} ${LIB_SOURCES} )
add_executable( test_task ${TEST_SOURCES} )

install( TARGETS test_task RUNTIME DESTINATION ${OUTPUT_DIR} )
if ( WIN32 )
    install( TARGETS curve RUNTIME DESTINATION ${OUTPUT_DIR} )
else()
    install( TARGETS curve LIBRARY DESTINATION ${OUTPUT_DIR} )
endif()


include_directories( ${INCLUDE_DIR} )

target_include_directories( test_task PRIVATE ${INCLUDE_DIR} )
target_link_libraries( test_task PRIVATE curve )

if ( WIN32 )
    target_compile_definitions( curve PRIVATE _USE_MATH_DEFINES )
    target_compile_definitions( test_task PRIVATE _USE_MATH_DEFINES )
endif()

target_compile_definitions( curve PRIVATE CURVE_EXPORT )

find_package(OpenMP)
if (OPENMP_FOUND)
	set( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}" )
    set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}" )
endif()

