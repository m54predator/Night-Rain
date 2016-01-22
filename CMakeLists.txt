cmake_minimum_required(VERSION 3.3)
project(Night_Rain)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")


find_package(OpenGL REQUIRED)

set(Night_Rain_SOURCE_FILES
        Coordinates.cpp Coordinates.h
        Core.cpp  Core.h
        Function_2D.cpp Function_2D.h
        Graphic_2D.cpp Graphic_2D.h
        Object_Static_2D.cpp Object_Static_2D.h
        Point_2D.cpp Point_2D.h
        RGBA.cpp RGBA.h
        Scene.cpp Scene.h
        Scene_Object.cpp Scene_Object.h
        Simple_win.cpp Simple_win.h
        Win_err.cpp Win_err.h
        Window.cpp Window.h)


SET(DIRECTX OFF CACHE BOOL "disable directx for sdl2")
SET(FORCE_STATIC_VCRT ON CACHE BOOL "Force /MT for static VC runtimes")


add_subdirectory(../SDL/ SDL2)

add_library(Night_Rain ${Night_Rain_SOURCE_FILES})

set_property(TARGET Night_Rain PROPERTY CXX_STANDARD 11)

target_include_directories(Night_Rain PUBLIC ../SDL/include)
target_include_directories(Night_Rain PUBLIC ${CMAKE_SOURCE_DIR})
target_link_libraries(Night_Rain PUBLIC SDL2-static ${OPENGL_LIBRARIES})