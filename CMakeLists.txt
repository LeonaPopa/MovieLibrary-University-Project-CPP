cmake_minimum_required(VERSION 3.25)
project(a10_LeonaPopa)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(a10_LeonaPopa
        domain.cpp
        domain.h
        exeptions.h
        gui.cpp
        gui.h
        repository.cpp
        repository.h
        service.cpp
        service.h
        ui.cpp
        ui.h
        validator.cpp
        validator.h
        watch_list.cpp
        watch_list.h)
