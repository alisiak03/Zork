cmake_minimum_required(VERSION 3.28)
project(Zork)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(Zork main.cpp
        Room.cpp
        Room.h
        main.h
        RoomNav.cpp
        RoomNav.h
        MainWindow.cpp
        MainWindow.h
        MainWindow.ui
        MainWindow.cpp
        MainWindow.h
        MainWindow.ui
        TextAnimation.cpp
        TextAnimation.h)
target_link_libraries(Zork
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)

