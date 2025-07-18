include(FetchContent)

macro(import_qt)
    # Use find_package with vcpkg integration
    find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets)
endmacro()

macro(importDependencies)
    import_qt()

    message(STATUS "End of importDependencies.")
endmacro()