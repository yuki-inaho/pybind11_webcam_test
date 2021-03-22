cmake_minimum_required(VERSION 2.8)

set(PROJ_NAME pybind_webcam_test)
project(${PROJ_NAME})

set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_FLAGS "-O3 -std=c++11")

# Use -fPIC even if statically compiled
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

find_package(PkgConfig REQUIRED)
find_package(PythonLibs 3 REQUIRED)
# Find Python3 and NumPy
find_package(Python3 COMPONENTS Interpreter Development NumPy REQUIRED)
MESSAGE("PYTHON_INCLUDE_DIRS : " ${PYTHON_INCLUDE_DIRS})
MESSAGE("PYTHON_LIBRARIES : " ${PYTHON_LIBRARIES})
add_subdirectory(extern/pybind11)

pybind11_add_module(
    ${PROJ_NAME}
    ${PYTHON_INCLUDE_DIRS}
    src/bindings.cpp 
    src/ndarray_converter.cpp
    src/webcam.cpp
)

include_directories(
    include
    extern/pybind11/include
)

pkg_check_modules(OpenCV REQUIRED opencv)
include_directories(${OpenCV_CFLAGS})
target_link_libraries(${PROJ_NAME} ${OpenCV_LDFLAGS})
target_link_libraries(${PROJ_NAME} ${PYTHON_LIBRARIES})
target_link_libraries(${PROJ_NAME} PUBLIC Python3::NumPy)