# OFX Utilities Library
add_library(ofxUtilities STATIC
    ofxUtilities.cpp
    ofxUtilities.h
)

target_include_directories(ofxUtilities PUBLIC
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/include/ofx
)
