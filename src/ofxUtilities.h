#ifndef _ofxUtilities_h_
#define _ofxUtilities_h_

#include "ofxCore.h"
#include "ofxImageEffect.h"
#include "ofxProperty.h"
#include "ofxParam.h"

#include <string>
#include <cstring>
#include <cstdlib>

/**
 * @file ofxUtilities.h
 * @brief Utility functions and helpers for creating OFX plugins
 */

namespace ofx {

// Global pointers to the suites
extern OfxHost *gHost;
extern OfxPropertySuiteV1 *gPropertySuite;
extern OfxImageEffectSuiteV1 *gImageEffectSuite;
extern OfxParameterSuiteV1 *gParameterSuite;

/**
 * @brief Initialize the OFX suites from the host
 * @param host The host structure passed to setHost
 */
inline void initializeSuites(OfxHost *host) {
    gHost = host;
    gPropertySuite = (OfxPropertySuiteV1*)host->fetchSuite(host->host, kOfxPropertySuite, 1);
    gImageEffectSuite = (OfxImageEffectSuiteV1*)host->fetchSuite(host->host, kOfxImageEffectSuite, 1);
    gParameterSuite = (OfxParameterSuiteV1*)host->fetchSuite(host->host, kOfxParameterSuite, 1);
}

/**
 * @brief Property helper class for easier property manipulation
 */
class PropertySet {
private:
    OfxPropertySetHandle propHandle;

public:
    PropertySet(OfxPropertySetHandle handle) : propHandle(handle) {}

    // Getters
    int getInt(const char* name, int index = 0) {
        int value = 0;
        gPropertySuite->propGetInt(propHandle, name, index, &value);
        return value;
    }

    double getDouble(const char* name, int index = 0) {
        double value = 0.0;
        gPropertySuite->propGetDouble(propHandle, name, index, &value);
        return value;
    }

    const char* getString(const char* name, int index = 0) {
        char* value = nullptr;
        gPropertySuite->propGetString(propHandle, name, index, &value);
        return value;
    }

    void* getPointer(const char* name, int index = 0) {
        void* value = nullptr;
        gPropertySuite->propGetPointer(propHandle, name, index, &value);
        return value;
    }

    // Setters
    void setInt(const char* name, int value, int index = 0) {
        gPropertySuite->propSetInt(propHandle, name, index, value);
    }

    void setDouble(const char* name, double value, int index = 0) {
        gPropertySuite->propSetDouble(propHandle, name, index, value);
    }

    void setString(const char* name, const char* value, int index = 0) {
        gPropertySuite->propSetString(propHandle, name, index, value);
    }

    void setPointer(const char* name, void* value, int index = 0) {
        gPropertySuite->propSetPointer(propHandle, name, index, value);
    }

    // Multi-value setters
    void setIntN(const char* name, int count, const int* values) {
        gPropertySuite->propSetIntN(propHandle, name, count, values);
    }

    void setDoubleN(const char* name, int count, const double* values) {
        gPropertySuite->propSetDoubleN(propHandle, name, count, values);
    }

    void setStringN(const char* name, int count, const char* const* values) {
        gPropertySuite->propSetStringN(propHandle, name, count, values);
    }

    OfxPropertySetHandle handle() const { return propHandle; }
};

/**
 * @brief Image helper class for easier image manipulation
 */
class Image {
private:
    OfxPropertySetHandle imageHandle;
    void* pixelData;
    OfxRectI bounds;
    int rowBytes;
    int pixelDepth;

public:
    Image(OfxPropertySetHandle handle) : imageHandle(handle), pixelData(nullptr), rowBytes(0), pixelDepth(0) {
        PropertySet props(imageHandle);

        // Get pixel data pointer
        pixelData = props.getPointer(kOfxImagePropData);

        // Get bounds
        bounds.x1 = props.getInt(kOfxImagePropBounds, 0);
        bounds.y1 = props.getInt(kOfxImagePropBounds, 1);
        bounds.x2 = props.getInt(kOfxImagePropBounds, 2);
        bounds.y2 = props.getInt(kOfxImagePropBounds, 3);

        // Get row bytes
        rowBytes = props.getInt(kOfxImagePropRowBytes);

        // Determine pixel depth
        const char* bitDepth = props.getString(kOfxImageEffectPropPixelDepth);
        if (strcmp(bitDepth, kOfxBitDepthByte) == 0) {
            pixelDepth = 1;
        } else if (strcmp(bitDepth, kOfxBitDepthShort) == 0) {
            pixelDepth = 2;
        } else if (strcmp(bitDepth, kOfxBitDepthFloat) == 0) {
            pixelDepth = 4;
        }
    }

    void* data() const { return pixelData; }
    const OfxRectI& getBounds() const { return bounds; }
    int getRowBytes() const { return rowBytes; }
    int getPixelDepth() const { return pixelDepth; }
    int getWidth() const { return bounds.x2 - bounds.x1; }
    int getHeight() const { return bounds.y2 - bounds.y1; }

    // Get pixel pointer at specific coordinates
    template<typename T>
    T* pixelAt(int x, int y) {
        int yOffset = (y - bounds.y1) * rowBytes;
        int xOffset = (x - bounds.x1) * pixelDepth * 4; // Assuming RGBA
        return (T*)((char*)pixelData + yOffset + xOffset);
    }
};

/**
 * @brief Parameter helper class
 */
class Param {
private:
    OfxParamHandle paramHandle;

public:
    Param(OfxParamHandle handle) : paramHandle(handle) {}

    // Get values
    void getValue(int& value) {
        gParameterSuite->paramGetValue(paramHandle, &value);
    }

    void getValue(double& value) {
        gParameterSuite->paramGetValue(paramHandle, &value);
    }

    void getValue(double& r, double& g, double& b) {
        gParameterSuite->paramGetValue(paramHandle, &r, &g, &b);
    }

    void getValue(double& r, double& g, double& b, double& a) {
        gParameterSuite->paramGetValue(paramHandle, &r, &g, &b, &a);
    }

    void getValue(char** value) {
        gParameterSuite->paramGetValue(paramHandle, value);
    }

    // Get values at time
    void getValueAtTime(double time, double& value) {
        gParameterSuite->paramGetValueAtTime(paramHandle, time, &value);
    }

    void getValueAtTime(double time, int& value) {
        gParameterSuite->paramGetValueAtTime(paramHandle, time, &value);
    }

    void getValueAtTime(double time, double& r, double& g, double& b) {
        gParameterSuite->paramGetValueAtTime(paramHandle, time, &r, &g, &b);
    }

    void getValueAtTime(double time, double& r, double& g, double& b, double& a) {
        gParameterSuite->paramGetValueAtTime(paramHandle, time, &r, &g, &b, &a);
    }

    OfxParamHandle handle() const { return paramHandle; }
};

} // namespace ofx

#endif // _ofxUtilities_h_
