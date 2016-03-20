cmake_minimum_required(VERSION 2.8)

project(Projet-Neuroleptic)

set(CMAKE_CXX_FLAGS "-std=c++0x")

#Qt inclusion
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(QT_USE_QTOPENGL TRUE)

find_package(Qt5 COMPONENTS Widgets OpenGL)

#VRPN Inclusion
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib/VRPN/src)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib/VRPN)

#GLM Inclusion
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib/glm/)

#executable Configuration
file(GLOB_RECURSE SRCS src/*)
file(GLOB SHDR shader/*)

add_executable(projet_N ${SRCS} ${SHDR})
QT5_USE_MODULES(projet_N Widgets Declarative OpenGL)


target_link_libraries(projet_N libvrpn.a libvrpnserver.a)