#ifndef _ofxParam_h_
#define _ofxParam_h_

/*
Software License :

Copyright (c) 2003-2015, The Open Effects Association Ltd.  All Rights Reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

    * Redistributions of source code must retain the above copyright notice,
      this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright notice,
      this list of conditions and the following disclaimer in the documentation
      and/or other materials provided with the distribution.
    * Neither the name The Open Effects Association Ltd, nor the names of its
      contributors may be used to endorse or promote products derived from this
      software without specific prior written permission.
*/

#include "ofxCore.h"

#ifdef __cplusplus
extern "C" {
#endif

/** @file ofxParam.h
Contains the definitions for the Parameter Suite.
*/

/** @brief Blind declaration of an OFX param */
typedef struct OfxParamStruct *OfxParamHandle;

/** @brief Blind declaration of an OFX parameter set */
typedef struct OfxParamSetStruct *OfxParamSetHandle;

/** @name Parameter Types
 */
/*@{*/

/** @brief Integer parameter type */
#define kOfxParamTypeInteger "OfxParamTypeInteger"

/** @brief Double parameter type */
#define kOfxParamTypeDouble "OfxParamTypeDouble"

/** @brief Boolean parameter type */
#define kOfxParamTypeBoolean "OfxParamTypeBoolean"

/** @brief Choice parameter type */
#define kOfxParamTypeChoice "OfxParamTypeChoice"

/** @brief RGBA color parameter type */
#define kOfxParamTypeRGBA "OfxParamTypeRGBA"

/** @brief RGB color parameter type */
#define kOfxParamTypeRGB "OfxParamTypeRGB"

/** @brief 2D double parameter type */
#define kOfxParamTypeDouble2D "OfxParamTypeDouble2D"

/** @brief 2D integer parameter type */
#define kOfxParamTypeInteger2D "OfxParamTypeInteger2D"

/** @brief 3D double parameter type */
#define kOfxParamTypeDouble3D "OfxParamTypeDouble3D"

/** @brief 3D integer parameter type */
#define kOfxParamTypeInteger3D "OfxParamTypeInteger3D"

/** @brief String parameter type */
#define kOfxParamTypeString "OfxParamTypeString"

/** @brief Custom parameter type */
#define kOfxParamTypeCustom "OfxParamTypeCustom"

/** @brief Group parameter type */
#define kOfxParamTypeGroup "OfxParamTypeGroup"

/** @brief Page parameter type */
#define kOfxParamTypePage "OfxParamTypePage"

/** @brief Pushbutton parameter type */
#define kOfxParamTypePushButton "OfxParamTypePushButton"

/*@}*/

/** @name Parameter Properties
 */
/*@{*/

/** @brief Property on a parameter - the type of the parameter */
#define kOfxParamPropType "OfxParamPropType"

/** @brief Property on a parameter - the scriptable name of the parameter */
#define kOfxParamPropScriptName "OfxParamPropScriptName"

/** @brief Property on a parameter - a user visible hint for the parameter */
#define kOfxParamPropHint "OfxParamPropHint"

/** @brief Property on a parameter - the default value of the parameter */
#define kOfxParamPropDefault "OfxParamPropDefault"

/** @brief Property on a parameter - the minimum value for the parameter */
#define kOfxParamPropMin "OfxParamPropMin"

/** @brief Property on a parameter - the maximum value for the parameter */
#define kOfxParamPropMax "OfxParamPropMax"

/** @brief Property on a parameter - the display minimum value */
#define kOfxParamPropDisplayMin "OfxParamPropDisplayMin"

/** @brief Property on a parameter - the display maximum value */
#define kOfxParamPropDisplayMax "OfxParamPropDisplayMax"

/** @brief Property on a parameter - the increment for the parameter */
#define kOfxParamPropIncrement "OfxParamPropIncrement"

/** @brief Property on a parameter - the number of digits after decimal point */
#define kOfxParamPropDigits "OfxParamPropDigits"

/** @brief Property on a parameter - is the parameter enabled */
#define kOfxParamPropEnabled "OfxParamPropEnabled"

/** @brief Property on a parameter - is the parameter secret */
#define kOfxParamPropSecret "OfxParamPropSecret"

/** @brief Property on a parameter - can the parameter animate */
#define kOfxParamPropAnimates "OfxParamPropAnimates"

/** @brief Property on a parameter - is the parameter animating */
#define kOfxParamPropIsAnimating "OfxParamPropIsAnimating"

/** @brief Property on a parameter - is the parameter auto keying */
#define kOfxParamPropIsAutoKeying "OfxParamPropIsAutoKeying"

/** @brief Property on a parameter - should the UI be persisted */
#define kOfxParamPropPersistant "OfxParamPropPersistant"

/** @brief Property on a parameter - should we evaluate on change */
#define kOfxParamPropEvaluateOnChange "OfxParamPropEvaluateOnChange"

/** @brief Property on a parameter - should we purge caches after this changes */
#define kOfxParamPropPluginMayWrite "OfxParamPropPluginMayWrite"

/** @brief Property on a parameter - does the parameter represent a cache key */
#define kOfxParamPropCacheInvalidation "OfxParamPropCacheInvalidation"

/** @brief Property on a parameter - can the parameter slave other parameters */
#define kOfxParamPropCanUndo "OfxParamPropCanUndo"

/** @brief Property on choice param - list of choice labels */
#define kOfxParamPropChoiceOption "OfxParamPropChoiceOption"

/** @brief Property on string param - is the string a file path */
#define kOfxParamPropStringMode "OfxParamPropStringMode"

/** @brief Property on string param - default file path */
#define kOfxParamPropStringFilePathExists "OfxParamPropStringFilePathExists"

/** @brief Property on a parameter - the parent of a parameter */
#define kOfxParamPropParent "OfxParamPropParent"

/** @brief Property on group param - is the group currently open */
#define kOfxParamPropGroupOpen "OfxParamPropGroupOpen"

/** @brief Property on page param - child parameters */
#define kOfxParamPropPageChild "OfxParamPropPageChild"

/** @brief Property on a parameter - interaction hint for sliders */
#define kOfxParamPropDoubleType "OfxParamPropDoubleType"

/** @brief Property on a parameter - show time marker */
#define kOfxParamPropShowTimeMarker "OfxParamPropShowTimeMarker"

/** @brief Property on a parameter - use host's overlay handle */
#define kOfxParamPropUseHostOverlayHandle "OfxParamPropUseHostOverlayHandle"

/*@}*/

/** @name String Parameter Modes
 */
/*@{*/

/** @brief Standard string parameter */
#define kOfxParamStringIsSingleLine "OfxParamStringIsSingleLine"

/** @brief Multi-line string parameter */
#define kOfxParamStringIsMultiLine "OfxParamStringIsMultiLine"

/** @brief String is a file path */
#define kOfxParamStringIsFilePath "OfxParamStringIsFilePath"

/** @brief String is a directory path */
#define kOfxParamStringIsDirectoryPath "OfxParamStringIsDirectoryPath"

/** @brief String is a label */
#define kOfxParamStringIsLabel "OfxParamStringIsLabel"

/*@}*/

/** @name Double Parameter Types
 */
/*@{*/

/** @brief Standard double slider */
#define kOfxParamDoubleTypePlain "OfxParamDoubleTypePlain"

/** @brief Angle parameter (in degrees) */
#define kOfxParamDoubleTypeAngle "OfxParamDoubleTypeAngle"

/** @brief Scale parameter */
#define kOfxParamDoubleTypeScale "OfxParamDoubleTypeScale"

/** @brief Time parameter */
#define kOfxParamDoubleTypeTime "OfxParamDoubleTypeTime"

/** @brief Absolute time parameter */
#define kOfxParamDoubleTypeAbsoluteTime "OfxParamDoubleTypeAbsoluteTime"

/*@}*/

/** @name Cache Invalidation
 */
/*@{*/

/** @brief Value changes invalidate the cache */
#define kOfxParamInvalidateValueChange "OfxParamInvalidateValueChange"

/** @brief Value changes invalidate at a specific time */
#define kOfxParamInvalidateValueChangeToEnd "OfxParamInvalidateValueChangeToEnd"

/** @brief Value changes do not invalidate */
#define kOfxParamInvalidateAll "OfxParamInvalidateAll"

/*@}*/

/** @brief Parameter Suite Name and Version
 */
/*@{*/

/** @brief Name of the parameter suite */
#define kOfxParameterSuite "OfxParameterSuite"

/*@}*/

/** @name Forward Type Declarations
 */
/*@{*/

/** @brief OFX range in doubles */
typedef struct OfxRangeD {
  double min, max;
} OfxRangeD;

/** @brief OFX range in integers */
typedef struct OfxRangeI {
  int min, max;
} OfxRangeI;

/*@}*/

/** @brief OFX Parameter Suite V1
 *
 * This is the suite of functions that a host must implement to support
 * parameters in image effect plugins.
 */
typedef struct OfxParameterSuiteV1 {
  /** @brief Define a parameter on an effect */
  OfxStatus (*paramDefine)(OfxParamSetHandle paramSet,
                          const char *paramType,
                          const char *name,
                          OfxPropertySetHandle *propertySet);

  /** @brief Get a parameter handle from a parameter set */
  OfxStatus (*paramGetHandle)(OfxParamSetHandle paramSet,
                             const char *name,
                             OfxParamHandle *param,
                             OfxPropertySetHandle *propertySet);

  /** @brief Set a parameter's value */
  OfxStatus (*paramSetValue)(OfxParamHandle paramHandle, ...);

  /** @brief Set a parameter's value at a specific time */
  OfxStatus (*paramSetValueAtTime)(OfxParamHandle paramHandle, double time, ...);

  /** @brief Get a parameter's value */
  OfxStatus (*paramGetValue)(OfxParamHandle paramHandle, ...);

  /** @brief Get a parameter's value at a specific time */
  OfxStatus (*paramGetValueAtTime)(OfxParamHandle paramHandle, double time, ...);

  /** @brief Get a parameter's derivative */
  OfxStatus (*paramGetDerivative)(OfxParamHandle paramHandle, double time, ...);

  /** @brief Get a parameter's integral */
  OfxStatus (*paramGetIntegral)(OfxParamHandle paramHandle, double time1, double time2, ...);

  /** @brief Set a parameter to its default value */
  OfxStatus (*paramSetToDefault)(OfxParamHandle paramHandle);

  /** @brief Get the number of keys in a parameter */
  OfxStatus (*paramGetNumKeys)(OfxParamHandle paramHandle, unsigned int *numberOfKeys);

  /** @brief Get the time of the nth key */
  OfxStatus (*paramGetKeyTime)(OfxParamHandle paramHandle, unsigned int nthKey, double *time);

  /** @brief Get the index of a key at/before a given time */
  OfxStatus (*paramGetKeyIndex)(OfxParamHandle paramHandle, double time, int direction, int *index);

  /** @brief Delete a key */
  OfxStatus (*paramDeleteKey)(OfxParamHandle paramHandle, double time);

  /** @brief Delete all keys */
  OfxStatus (*paramDeleteAllKeys)(OfxParamHandle paramHandle);

  /** @brief Copy parameter values and keys */
  OfxStatus (*paramCopy)(OfxParamHandle paramTo, OfxParamHandle paramFrom, double dstOffset, const OfxRangeD *frameRange);

  /** @brief Trigger a custom parameter action */
  OfxStatus (*paramEditBegin)(OfxParamSetHandle paramSet, const char *name);

  /** @brief End a custom parameter action */
  OfxStatus (*paramEditEnd)(OfxParamSetHandle paramSet);

} OfxParameterSuiteV1;

#ifdef __cplusplus
}
#endif

#endif
