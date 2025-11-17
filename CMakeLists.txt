cmake_minimum_required(VERSION 3.15)

project(OFX_DaVinci_Framework VERSION 1.0.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Platform-specific settings
if(WIN32)
    set(OFX_PLUGIN_EXTENSION ".ofx.bundle")
    set(OFX_ARCH "Win64")
elseif(APPLE)
    set(OFX_PLUGIN_EXTENSION ".ofx.bundle")
    set(OFX_ARCH "MacOS")
else()
    set(OFX_PLUGIN_EXTENSION ".ofx.bundle")
    set(OFX_ARCH "Linux-x86-64")
endif()

# Include directories
include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/include/ofx
)

# Add subdirectories
add_subdirectory(src)
add_subdirectory(examples)

# Installation settings
if(WIN32)
    set(OFX_INSTALL_PATH "$ENV{PROGRAMFILES}/Common Files/OFX/Plugins")
elseif(APPLE)
    set(OFX_INSTALL_PATH "/Library/OFX/Plugins")
else()
    set(OFX_INSTALL_PATH "/usr/OFX/Plugins")
endif()

message(STATUS "OFX plugins will be installed to: ${OFX_INSTALL_PATH}")
message(STATUS "Platform architecture: ${OFX_ARCH}")
