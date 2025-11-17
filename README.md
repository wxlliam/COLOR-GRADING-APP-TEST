# OFX Plugin Framework for DaVinci Resolve

A comprehensive framework for creating OpenFX (OFX) plugins for DaVinci Resolve 20.x color page. This framework provides all the necessary headers, utilities, and example code to develop custom color grading effects.

## Features

- **Complete OFX Headers**: Full implementation of OFX Core, Image Effect, Parameter, and Property APIs
- **C++ Utility Classes**: Easy-to-use wrappers for OFX suites and common operations
- **Example Color Correction Plugin**: Fully functional color grading effect with gain, gamma, and saturation controls
- **Cross-Platform Support**: Build on Linux, macOS, and Windows
- **DaVinci Resolve Optimized**: Specifically designed for DaVinci Resolve 20.x color page
- **CMake Build System**: Modern build configuration with easy customization

## Project Structure

```
.
├── include/
│   └── ofx/                    # OFX API headers
│       ├── ofxCore.h           # Core OFX definitions
│       ├── ofxImageEffect.h    # Image effect API
│       ├── ofxParam.h          # Parameter API
│       └── ofxProperty.h       # Property suite API
├── src/
│   ├── ofxUtilities.h          # C++ utility classes
│   └── ofxUtilities.cpp        # Utility implementations
├── examples/
│   └── ColorCorrectionPlugin.cpp  # Example plugin
├── cmake/                      # CMake modules
└── build/                      # Build output (generated)
```

## Requirements

### Build Tools
- **CMake** 3.15 or higher
- **C++ Compiler** with C++11 support:
  - Linux: GCC 5.0+ or Clang 3.4+
  - macOS: Xcode 7.0+ (Apple Clang)
  - Windows: Visual Studio 2015 or higher

### DaVinci Resolve
- **DaVinci Resolve 20.x** or higher
- Supports both Studio and free versions

## Building the Framework

### Linux

```bash
# Create build directory
mkdir build
cd build

# Configure with CMake
cmake ..

# Build
make

# Install (optional - requires sudo for system-wide installation)
sudo make install
```

### macOS

```bash
# Create build directory
mkdir build
cd build

# Configure with CMake
cmake ..

# Build
make

# Install (optional - installs to /Library/OFX/Plugins)
sudo make install
```

### Windows

```cmd
# Create build directory
mkdir build
cd build

# Configure with CMake (for Visual Studio 2019)
cmake .. -G "Visual Studio 16 2019" -A x64

# Build
cmake --build . --config Release

# Install (optional - requires administrator privileges)
cmake --install . --config Release
```

## Manual Installation

If you prefer not to use the install target, you can manually copy the plugin bundles:

### Linux
```bash
cp -r build/Plugins/*.ofx.bundle /usr/OFX/Plugins/
```

### macOS
```bash
cp -r build/Plugins/*.ofx.bundle /Library/OFX/Plugins/
```

### Windows
```cmd
xcopy /E /I build\Plugins\*.ofx.bundle "C:\Program Files\Common Files\OFX\Plugins\"
```

## Using the Framework to Create Your Own Plugin

### 1. Create Your Plugin File

Create a new `.cpp` file in the `examples/` directory:

```cpp
#include "ofxCore.h"
#include "ofxImageEffect.h"
#include "ofxProperty.h"
#include "ofxParam.h"
#include "ofxUtilities.h"

// Define your plugin identifier
#define kPluginIdentifier "com.yourcompany.YourPlugin"
#define kPluginName "YourPlugin"

using namespace ofx;

// Implement render function
static OfxStatus render(OfxImageEffectHandle instance,
                       OfxPropertySetHandle inArgs,
                       OfxPropertySetHandle outArgs)
{
    // Your rendering code here
    return kOfxStatOK;
}

// Implement describe function
static OfxStatus describe(OfxImageEffectHandle descriptor)
{
    OfxPropertySetHandle effectProps;
    gImageEffectSuite->getPropertySet(descriptor, &effectProps);
    PropertySet props(effectProps);

    // Set plugin properties
    props.setString(kOfxPropLabel, kPluginName);

    // Define supported contexts
    const char* contexts[] = { kOfxImageEffectContextFilter };
    props.setStringN(kOfxImageEffectPropSupportedContexts, 1, contexts);

    // Define supported pixel depths
    const char* pixelDepths[] = {
        kOfxBitDepthByte,
        kOfxBitDepthShort,
        kOfxBitDepthFloat
    };
    props.setStringN(kOfxImageEffectPropSupportedPixelDepths, 3, pixelDepths);

    return kOfxStatOK;
}

// Main entry point
static OfxStatus mainEntry(const char *action, const void *handle,
                          OfxPropertySetHandle inArgs,
                          OfxPropertySetHandle outArgs)
{
    // Handle actions
    if (strcmp(action, kOfxActionDescribe) == 0) {
        return describe((OfxImageEffectHandle)handle);
    }
    else if (strcmp(action, kOfxImageEffectActionRender) == 0) {
        return render((OfxImageEffectHandle)handle, inArgs, outArgs);
    }

    return kOfxStatReplyDefault;
}

// Plugin definition
static OfxPlugin yourPlugin = {
    kOfxImageEffectPluginApi,
    kOfxImageEffectPluginApiVersion,
    kPluginIdentifier,
    1, // major version
    0, // minor version
    setHostFunc,
    mainEntry
};

// Export functions
OfxExport int OfxGetNumberOfPlugins(void) { return 1; }
OfxExport OfxPlugin *OfxGetPlugin(int nth) {
    return (nth == 0) ? &yourPlugin : nullptr;
}
```

### 2. Update CMakeLists.txt

Add your plugin to `examples/CMakeLists.txt`:

```cmake
add_library(YourPlugin MODULE
    YourPlugin.cpp
)

target_link_libraries(YourPlugin PRIVATE ofxUtilities)

set_target_properties(YourPlugin PROPERTIES
    PREFIX ""
    SUFFIX ".ofx"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/Plugins/YourPlugin.ofx.bundle/Contents/${OFX_ARCH}"
)
```

### 3. Build and Install

```bash
cd build
cmake ..
make
sudo make install
```

## Example Plugin: Color Correction

The included ColorCorrection plugin demonstrates:

- **Multiple Parameters**: Gain, Gamma, Saturation, RGB Gain
- **Multiple Pixel Depths**: 8-bit, 16-bit, and 32-bit float processing
- **Proper Color Science**: Rec. 709 luminance calculation
- **Thread Safety**: Fully reentrant rendering code

### Parameters

| Parameter | Type | Range | Description |
|-----------|------|-------|-------------|
| Gain | Double | 0.0 - 4.0 | Overall image brightness multiplier |
| Gamma | Double | 0.1 - 4.0 | Gamma correction (power function) |
| Saturation | Double | 0.0 - 4.0 | Color saturation (0 = grayscale, 1 = normal) |
| RGB Gain | RGB | 0.0 - 4.0 | Individual channel gain controls |

## API Reference

### Utility Classes

#### `PropertySet`
Wrapper for OFX property manipulation:

```cpp
PropertySet props(propertySetHandle);
props.setString("name", "value");
props.setInt("count", 10);
double val = props.getDouble("number");
```

#### `Image`
Helper for accessing image data:

```cpp
Image img(imageHandle);
int width = img.getWidth();
int height = img.getHeight();
float* pixel = img.pixelAt<float>(x, y);
```

#### `Param`
Simplified parameter access:

```cpp
Param gain(gainParamHandle);
double value;
gain.getValueAtTime(time, value);
```

## OFX Contexts

This framework supports the following OFX contexts:

- **Filter**: Apply effect to a single source clip
- **General**: Full-featured context with multiple clips
- **Generator**: Create images from scratch (no input)
- **Transition**: Blend between two clips

The example plugin uses the **Filter** context, which is ideal for color grading effects in DaVinci Resolve.

## Color Processing Best Practices

### 1. Support Multiple Bit Depths

Always support 8-bit, 16-bit, and 32-bit float:

```cpp
const char* pixelDepths[] = {
    kOfxBitDepthByte,
    kOfxBitDepthShort,
    kOfxBitDepthFloat
};
props.setStringN(kOfxImageEffectPropSupportedPixelDepths, 3, pixelDepths);
```

### 2. Use Proper Color Space

For luminance calculations, use Rec. 709 coefficients:

```cpp
double luma = 0.2126 * r + 0.7152 * g + 0.0722 * b;
```

### 3. Clamp Values Appropriately

- 8-bit: 0-255
- 16-bit: 0-65535
- Float: 0.0-1.0 (or allow HDR values > 1.0)

### 4. Thread Safety

Ensure your render function is thread-safe:

```cpp
props.setString(kOfxImageEffectPropRenderThreadSafety,
                kOfxImageEffectRenderFullySafe);
```

## DaVinci Resolve Integration

### Loading Plugins in DaVinci Resolve

1. Copy your `.ofx.bundle` to the OFX plugins directory
2. Launch DaVinci Resolve
3. Open a project and go to the Color page
4. Your plugin will appear in the Effects panel under "OFX"

### Plugin Categories

Use the grouping property to organize plugins:

```cpp
props.setString(kOfxImageEffectPropGrouping, "Color");
```

Common categories:
- **Color**: Color correction and grading
- **Image**: General image processing
- **Filter**: Artistic filters
- **Transform**: Geometric transformations

## Troubleshooting

### Plugin Not Appearing in DaVinci Resolve

1. Check plugin is in correct directory:
   - Linux: `/usr/OFX/Plugins/`
   - macOS: `/Library/OFX/Plugins/`
   - Windows: `C:\Program Files\Common Files\OFX\Plugins\`

2. Verify bundle structure:
   ```
   YourPlugin.ofx.bundle/
   └── Contents/
       ├── Linux-x86-64/    (on Linux)
       │   └── YourPlugin.ofx
       ├── MacOS/           (on macOS)
       │   └── YourPlugin.ofx
       └── Win64/           (on Windows)
           └── YourPlugin.ofx
   ```

3. Check DaVinci Resolve console for errors

### Build Errors

- Ensure C++11 support is enabled
- Check that all include paths are correct
- Verify CMake version is 3.15 or higher

### Runtime Crashes

- Verify all suite pointers are initialized in `setHost()`
- Check array bounds when accessing pixels
- Ensure proper null checking for all pointers

## Advanced Topics

### GPU Acceleration

For GPU-accelerated plugins, you'll need to:
1. Implement CUDA or Metal compute kernels
2. Handle GPU memory allocation
3. Use the OFX OpenGL/CUDA rendering extensions

### Multi-Clip Effects

For transitions or compositing:

```cpp
// Define additional clips
gImageEffectSuite->clipDefine(descriptor, "Source2", &clipProps);
```

### Custom Parameters

Create advanced parameter types:

```cpp
// Custom parameter with custom UI
gParameterSuite->paramDefine(paramSet, kOfxParamTypeCustom,
                             "myCustomParam", &paramProps);
```

## Resources

- [OpenFX Specification](http://openfx.sourceforge.net/)
- [DaVinci Resolve OFX SDK](https://www.blackmagicdesign.com/developer/product/resolve)
- [OFX Plugin Examples](https://github.com/ofxa/openfx)

## License

This framework is provided as-is for educational and commercial use. The OFX API headers are licensed under the BSD license by The Open Effects Association Ltd.

## Contributing

To add new examples or improve the framework:

1. Fork the repository
2. Create your feature branch
3. Test with DaVinci Resolve 20.x
4. Submit a pull request

## Support

For issues specific to:
- **This framework**: Open an issue in the repository
- **OFX API**: Consult the OpenFX documentation
- **DaVinci Resolve**: Contact Blackmagic Design support

## Version History

### 1.0.0 (Current)
- Initial release
- Complete OFX headers
- C++ utility classes
- Color Correction example plugin
- Cross-platform CMake build system
- DaVinci Resolve 20.x compatibility
