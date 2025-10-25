cmake_minimum_required(VERSION 3.19)
project(Flicka LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

qt_standard_project_setup()

qt_add_executable(Flicka
    WIN32 MACOSX_BUNDLE

    # General
    main.cpp
    Global.hpp
    BeforeRelease.hpp

    # DOCS
    Docs/LICENSE
    Docs/README.md
    Docs/TODO

    # UI
    UI/CompareWindow.cpp
    UI/CompareWindow.hpp
    UI/CompareWindow.ui
    UI/DropBox.cpp
    UI/DropBox.hpp
    UI/DropWindow.cpp
    UI/DropWindow.hpp
    UI/DropWindow.ui

    # Resources
    Resources/Icon/IconBase.ico
    Resources/Icon/IconBase.png
    Resources/Icon/Icons.qrc
    Resources/Icon/Icons.rc
)

target_link_libraries(Flicka
    PRIVATE
        Qt::Core
        Qt::Widgets
)

include(GNUInstallDirs)

install(TARGETS Flicka
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET Flicka
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
