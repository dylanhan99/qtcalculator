# ======================= Project Configuration =========================
cmake_minimum_required(VERSION 3.21)
cmake_policy(VERSION 3.5)

set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_LIST_DIR}/../vcpkg/scripts/buildsystems/vcpkg.cmake")
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake") # Directory where custom CMake modules are stored
set(PROJECT_NAME "qtcalculator")
set(SRC_PATH "${CMAKE_CURRENT_LIST_DIR}/src")

# Enable auto-MOC/UIC for Qt
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

project(${PROJECT_NAME})

# Disabling all install directories to avoid clashes
#set(CMAKE_SKIP_INSTALL_ALL_DEPENDENCY TRUE CACHE BOOL "" FORCE)

# Include project-wide utility and dependency modules
include(ImportDependencies)
importDependencies()

# List of external libraries
set(ALL_LIBS
    PRIVATE Qt5::Core Qt5::Gui Qt5::Widgets 
)

# ======================= Auto Project Discovery =========================
file(GLOB_RECURSE ${PROJECT_NAME}_source_files
    ${SRC_PATH}/*.h
    ${SRC_PATH}/*.hpp
    ${SRC_PATH}/*.cpp
)

add_executable(${PROJECT_NAME}
    ${${PROJECT_NAME}_source_files}
)

target_link_libraries(${PROJECT_NAME}
    ${ALL_LIBS}
)
target_include_directories(${PROJECT_NAME} PRIVATE
    ${SRC_PATH}
)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)

# Warnings based on compiler
if (MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W3 /WX-)
    target_precompile_headers(${PROJECT_NAME} PRIVATE ${SRC_PATH}/pch.h)
endif()
