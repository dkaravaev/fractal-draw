cmake_minimum_required(VERSION 2.8.4)
project(FractalRender)

# FIND BOOST
FIND_PACKAGE(Boost)
IF (Boost_FOUND)
    INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})
    ADD_DEFINITIONS( "-DHAS_BOOST" )
ENDIF()

# FIND GLUT
find_package(GLUT REQUIRED)
include_directories(${GLUT_INCLUDE_DIRS})
link_directories(${GLUT_LIBRARY_DIRS})
add_definitions(${GLUT_DEFINITIONS})
if(NOT GLUT_FOUND)
    message(ERROR "GLUT not found!")
endif(NOT GLUT_FOUND)

# FIND OPENGL
find_package(OpenGL REQUIRED)
include_directories(${OpenGL_INCLUDE_DIRS})
link_directories(${OpenGL_LIBRARY_DIRS})
add_definitions(${OpenGL_DEFINITIONS})
if(NOT OPENGL_FOUND)
    message(ERROR "OpenGL not found!")
endif(NOT OPENGL_FOUND)

#compiler flags
set(CMAKE_CXX_FLAGS "-Wall -fexceptions -O2 -g -std=c++11")

# create the executable file
set(SOURCE_FILES main.cpp
                 utils/util.cpp
                 FractalDFS/FractalDFS.cpp
                 FractalRecipes/FractalRecipe.cpp
                 FractalRecipes/Classic/Classic.cpp
                 FractalRecipes/Yourgens/Yourgens.cpp
                 FractalRecipes/Reily/Reily.cpp
                 FractalRecipes/Maskit/Maskit.cpp)

set(HEADER_FILES utils/util.hpp
                 FractalDFS/FractalDFS.hpp
                 FractalRecipes/FractalRecipe.hpp
                 FractalRecipes/Classic/Classic.hpp
                 FractalRecipes/Yourgens/Yourgens.hpp
                 FractalRecipes/Reily/Reily.hpp
                 FractalRecipes/Maskit/Maskit.hpp)

#adding compiler options -DNDEBUG -DBOOST_UBLAS_NDEBUG
set(CMAKE_CXX_FLAGS "-Wall -fexceptions -O2 -g -std=c++11 ")

add_executable(FractalRender ${SOURCE_FILES} ${HEADER_FILES})

# Linking & stuff
target_link_libraries(FractalRender ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} ${Boost_LIBRARIES})
