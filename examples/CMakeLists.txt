# Color Correction Example Plugin

# Create the plugin as a shared library
add_library(ColorCorrection MODULE
    ColorCorrectionPlugin.cpp
)

# Link with OFX utilities
target_link_libraries(ColorCorrection PRIVATE
    ofxUtilities
)

target_include_directories(ColorCorrection PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/include/ofx
    ${CMAKE_SOURCE_DIR}/src
)

# Set output properties for OFX bundle structure
set_target_properties(ColorCorrection PROPERTIES
    PREFIX ""
    SUFFIX ".ofx"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/Plugins/ColorCorrection.ofx.bundle/Contents/${OFX_ARCH}"
)

# Platform-specific settings
if(APPLE)
    set_target_properties(ColorCorrection PROPERTIES
        BUNDLE TRUE
        BUNDLE_EXTENSION "ofx"
    )
endif()

if(UNIX AND NOT APPLE)
    set_target_properties(ColorCorrection PROPERTIES
        COMPILE_FLAGS "-fPIC -fvisibility=hidden"
    )
endif()

# Install the plugin
install(TARGETS ColorCorrection
    LIBRARY DESTINATION "${OFX_INSTALL_PATH}/ColorCorrection.ofx.bundle/Contents/${OFX_ARCH}"
)

# Create Info.plist for macOS
if(APPLE)
    configure_file(
        "${CMAKE_CURRENT_SOURCE_DIR}/Info.plist.in"
        "${CMAKE_BINARY_DIR}/Plugins/ColorCorrection.ofx.bundle/Contents/Info.plist"
        @ONLY
    )

    install(FILES "${CMAKE_BINARY_DIR}/Plugins/ColorCorrection.ofx.bundle/Contents/Info.plist"
        DESTINATION "${OFX_INSTALL_PATH}/ColorCorrection.ofx.bundle/Contents"
    )
endif()
