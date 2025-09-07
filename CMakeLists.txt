cmake_minimum_required(VERSION 3.16)

project(TodoPP_GUI VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.8)

qt_add_executable(appTodoPP_GUI
    main.cpp
    # todopp_interface.cpp
    todo_model.cpp
    todo_model.h

)

qt_add_qml_module(appTodoPP_GUI
    URI TodoPP_GUI
    VERSION 1.0
    QML_FILES
        Main.qml
        QML_FILES TaskList.qml
        # SOURCES todo_model.h
        # SOURCES todopp_interface.h todopp_interface.cpp
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appTodoPP_GUI PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appTodoPP_GUI
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)
add_subdirectory(todopp todopp)

target_link_libraries(appTodoPP_GUI
    PRIVATE
        Qt6::Quick
        TodoPP
)
target_include_directories(appTodoPP_GUI PUBLIC todopp/include)

include(GNUInstallDirs)
install(TARGETS appTodoPP_GUI
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
