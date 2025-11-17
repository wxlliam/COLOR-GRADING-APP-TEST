#include "ofxUtilities.h"

namespace ofx {

// Global suite pointers - initialized in setHost
OfxHost *gHost = nullptr;
OfxPropertySuiteV1 *gPropertySuite = nullptr;
OfxImageEffectSuiteV1 *gImageEffectSuite = nullptr;
OfxParameterSuiteV1 *gParameterSuite = nullptr;

} // namespace ofx
