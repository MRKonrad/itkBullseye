cmake_minimum_required(VERSION 3.6)

project(itkBullseye)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_INSTALL_RPATH "@executable_path")
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

#delete!!!
set(CMAKE_INSTALL_PREFIX install)
#delete!!!

include(cmake/itkTensorFlow.cmake)

find_package(ITK REQUIRED HINTS ${ITK_DIR_HINTS})
include(${ITK_USE_FILE})

file(GLOB_RECURSE SRC_FILES
        src/*.c*
        src/*.h*
        src/*.t*)

add_library(itkBullseyeLib SHARED ${SRC_FILES})

include_directories(${CMAKE_SOURCE_DIR}/src)
include_directories(${PROJECT_BINARY_DIR})
target_link_libraries (itkBullseyeLib PUBLIC ${ITK_LIBRARIES})

target_link_libraries (itkBullseyeLib PUBLIC itkTensorFlowLib)

include(GenerateExportHeader)
generate_export_header(itkBullseyeLib)

install (TARGETS itkBullseyeLib DESTINATION lib)


set(itkBullseye_BUILD_TESTING ON CACHE BOOL "Do you want to build itkBullseye tests?")
add_subdirectory(tests)
