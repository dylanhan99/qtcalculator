include(FetchContent)

macro(import_qt)
    # Enable auto-MOC/UIC for Qt
    set(CMAKE_AUTOMOC ON)
    set(CMAKE_AUTOUIC ON)
    set(CMAKE_AUTORCC ON)

    # Use find_package with vcpkg integration
    find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets)
endmacro()

macro(importDependencies)
    import_qt()

    message(STATUS "End of importDependencies.")
endmacro()