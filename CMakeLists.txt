cmake_minimum_required(VERSION 3.3)
project(night_rain)

find_package(OpenGL REQUIRED)

set(night_rain_SOURCE_FILES
        Coordinates.cpp Coordinates.h
        Core.cpp Core.h
        CoreBase.cpp CoreBase.h
        Function_2D.cpp Function_2D.h
        Graphic_2D.cpp Graphic_2D.h
        Object_Static_2D.cpp Object_Static_2D.h
        Point_2D.cpp Point_2D.h
        RGBA.cpp RGBA.h
        Scene.cpp Scene.h
        Scene_Object.cpp Scene_Object.h
        Simple_win.cpp Simple_win.h
        Win_err.cpp Win_err.h
        Window.cpp Window.h
        Callback.h
        NR_event.cpp NR_event.h
        EventManager.cpp EventManager.h
        Data.cpp Data.h
        Polygon_3D.cpp Polygon_3D.h
        lodepng/lodepng.cpp lodepng/lodepng.h
        LookAt.cpp LookAt.h
        Camera.cpp Camera.h
		Texture.cpp Texture.h)


SET(DIRECTX OFF CACHE BOOL "disable directx for sdl2")
SET(FORCE_STATIC_VCRT ON CACHE BOOL "Force /MT for static VC runtimes")


add_subdirectory(../SDL/ SDL)

add_library(night_rain ${night_rain_SOURCE_FILES})

set_property(TARGET night_rain PROPERTY CXX_STANDARD 14)

target_include_directories(night_rain PUBLIC ../SDL/include)
target_include_directories(night_rain PUBLIC ${night_rain_SOURCE_DIR})
target_link_libraries(night_rain PUBLIC SDL2-static ${OPENGL_LIBRARIES})
