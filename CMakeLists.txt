cmake_minimum_required(VERSION 3.19)
project(Flicka LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

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

    # Drop window
    DropWindow/DropBox.cpp
    DropWindow/DropBox.hpp
    DropWindow/DropWindow.cpp
    DropWindow/DropWindow.hpp
    DropWindow/DropWindow.ui

    # Compare
    Compare/CompareWindow.cpp
    Compare/CompareWindow.hpp
    Compare/CompareWindow.ui

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
