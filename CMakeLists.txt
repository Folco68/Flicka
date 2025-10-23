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
    TODO

    # UI
    FileDrop/DropLabel.hpp
    FileDrop/DropLabel.cpp
    FileDrop/DropWindow.hpp FileDrop/DropWindow.cpp FileDrop/DropWindow.ui



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
