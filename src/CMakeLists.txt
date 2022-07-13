cmake_minimum_required(VERSION 3.5)

project(opencv LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(opencv main.cpp Persona.hpp Persona.cpp Detector.hpp Detector.cpp Nodo.hpp Nodo.cpp ListaEnlazada.hpp ListaEnlazada.cpp BinarySearchTree.hpp BinarySearchTree.cpp BinarySearchTreeNode.hpp)

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
target_link_libraries( opencv ${OpenCV_LIBS} )