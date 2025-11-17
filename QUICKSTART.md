# Quick Start Guide

Get started with the OFX Plugin Framework in 5 minutes!

## Prerequisites

- CMake 3.15+
- C++ compiler (GCC, Clang, or Visual Studio)
- DaVinci Resolve 20.x

## Build & Install

### Linux/macOS

```bash
# Make build script executable
chmod +x build.sh

# Build
./build.sh

# Install (optional)
cd build
sudo make install
```

### Windows

```cmd
REM Run build script
build.bat

REM Install (as Administrator)
cd build
cmake --install . --config Release
```

## Test in DaVinci Resolve

1. Launch DaVinci Resolve
2. Open any project
3. Go to the **Color** page
4. In the **Effects** panel, expand **OFX**
5. Look for **ColorCorrection** under the **Color** category
6. Drag the effect onto a clip
7. Adjust parameters in the inspector

## Create Your First Plugin

### 1. Copy the Example

```bash
cd examples
cp ColorCorrectionPlugin.cpp MyPlugin.cpp
```

### 2. Edit the Plugin

Open `MyPlugin.cpp` and change:

```cpp
// Change these identifiers
#define kPluginName "MyPlugin"
#define kPluginIdentifier "com.yourname.MyPlugin"

// Modify the render function to implement your effect
```

### 3. Update CMakeLists.txt

Edit `examples/CMakeLists.txt` and add:

```cmake
# Add your plugin
add_library(MyPlugin MODULE MyPlugin.cpp)
target_link_libraries(MyPlugin PRIVATE ofxUtilities)
set_target_properties(MyPlugin PROPERTIES
    PREFIX ""
    SUFFIX ".ofx"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/Plugins/MyPlugin.ofx.bundle/Contents/${OFX_ARCH}"
)
```

### 4. Rebuild

```bash
./build.sh
```

### 5. Install & Test

```bash
cd build
sudo make install
```

Restart DaVinci Resolve and your plugin will appear!

## Common Parameters

### Add a Slider

```cpp
// In describeInContext()
gParameterSuite->paramDefine(paramSet, kOfxParamTypeDouble, "myParam", &paramProps);
PropertySet paramP(paramProps);
paramP.setString(kOfxParamPropLabel, "My Parameter");
paramP.setDouble(kOfxParamPropDefault, 1.0);
paramP.setDouble(kOfxParamPropMin, 0.0);
paramP.setDouble(kOfxParamPropMax, 2.0);
```

### Add an RGB Color Picker

```cpp
gParameterSuite->paramDefine(paramSet, kOfxParamTypeRGB, "color", &paramProps);
PropertySet colorP(paramProps);
colorP.setString(kOfxParamPropLabel, "Color");
double defaultColor[] = {1.0, 1.0, 1.0};
colorP.setDoubleN(kOfxParamPropDefault, 3, defaultColor);
```

### Add a Checkbox

```cpp
gParameterSuite->paramDefine(paramSet, kOfxParamTypeBoolean, "enable", &paramProps);
PropertySet enableP(paramProps);
enableP.setString(kOfxParamPropLabel, "Enable Effect");
enableP.setInt(kOfxParamPropDefault, 1);
```

## Processing Pixels

### Basic Template

```cpp
template<typename T>
void processPixels(T* dst, const T* src,
                   const OfxRectI& renderWindow,
                   int dstRowBytes, int srcRowBytes,
                   double maxValue)
{
    int width = renderWindow.x2 - renderWindow.x1;
    int height = renderWindow.y2 - renderWindow.y1;

    for (int y = 0; y < height; y++) {
        T* dstRow = (T*)((char*)dst + y * dstRowBytes);
        const T* srcRow = (const T*)((const char*)src + y * srcRowBytes);

        for (int x = 0; x < width; x++) {
            int pixelIndex = x * 4; // RGBA

            // Read
            double r = srcRow[pixelIndex + 0] / maxValue;
            double g = srcRow[pixelIndex + 1] / maxValue;
            double b = srcRow[pixelIndex + 2] / maxValue;
            double a = srcRow[pixelIndex + 3] / maxValue;

            // Process
            // ... your effect here ...

            // Write
            dstRow[pixelIndex + 0] = (T)(r * maxValue);
            dstRow[pixelIndex + 1] = (T)(g * maxValue);
            dstRow[pixelIndex + 2] = (T)(b * maxValue);
            dstRow[pixelIndex + 3] = (T)(a * maxValue);
        }
    }
}
```

### Call from Render

```cpp
if (strcmp(pixelDepth, kOfxBitDepthFloat) == 0) {
    processPixels<float>((float*)dstData, (const float*)srcData,
                        renderWindow, dstRowBytes, srcRowBytes, 1.0);
}
else if (strcmp(pixelDepth, kOfxBitDepthShort) == 0) {
    processPixels<unsigned short>((unsigned short*)dstData,
                                 (const unsigned short*)srcData,
                                 renderWindow, dstRowBytes, srcRowBytes, 65535.0);
}
else if (strcmp(pixelDepth, kOfxBitDepthByte) == 0) {
    processPixels<unsigned char>((unsigned char*)dstData,
                                (const unsigned char*)srcData,
                                renderWindow, dstRowBytes, srcRowBytes, 255.0);
}
```

## Debugging Tips

### Print Debug Messages

Use stderr for debugging (visible in DaVinci Resolve console):

```cpp
#include <cstdio>

fprintf(stderr, "MyPlugin: Rendering at time %f\n", time);
fprintf(stderr, "MyPlugin: Parameter value = %f\n", value);
```

### Check Return Values

Always check OFX function returns:

```cpp
OfxStatus status = gParameterSuite->paramGetValue(paramHandle, &value);
if (status != kOfxStatOK) {
    fprintf(stderr, "Error getting parameter value: %d\n", status);
}
```

### Validate Pointers

```cpp
if (!srcData || !dstData) {
    fprintf(stderr, "Error: NULL image data\n");
    return kOfxStatFailed;
}
```

## Next Steps

1. Read the full [README.md](README.md) for comprehensive documentation
2. Study the [ColorCorrectionPlugin.cpp](examples/ColorCorrectionPlugin.cpp) example
3. Check the [OFX Specification](http://openfx.sourceforge.net/)
4. Experiment with different effects!

## Common Issues

### Plugin doesn't appear in DaVinci Resolve

- Check the plugin is in the correct directory
- Ensure the bundle structure is correct
- Restart DaVinci Resolve
- Check the DaVinci Resolve console for errors

### Build errors

- Verify CMake version: `cmake --version`
- Check compiler is installed: `gcc --version` or `clang --version`
- Clean build directory: `rm -rf build`

### Crashes

- Check for null pointers
- Verify array bounds
- Ensure thread safety
- Check parameter values are in valid ranges

## Getting Help

- Check the troubleshooting section in [README.md](README.md)
- Review example code in `examples/`
- Consult OFX documentation

Happy plugin development!
