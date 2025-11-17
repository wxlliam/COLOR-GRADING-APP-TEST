#ifndef _ofxProperty_h_
#define _ofxProperty_h_

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

/** @file ofxProperty.h
Contains the API for manipulating properties on OFX objects.
*/

/** @brief The name of the standard OFX property suite */
#define kOfxPropertySuite "OfxPropertySuite"

/** @brief OFX Property Suite V1
 *
 * This is the suite of functions that a host must implement to support
 * properties on OFX objects.
 */
typedef struct OfxPropertySuiteV1 {
  /** @brief Set a single value in a property */
  OfxStatus (*propSetPointer)(OfxPropertySetHandle properties, const char *property, int index, void *value);
  OfxStatus (*propSetString)(OfxPropertySetHandle properties, const char *property, int index, const char *value);
  OfxStatus (*propSetDouble)(OfxPropertySetHandle properties, const char *property, int index, double value);
  OfxStatus (*propSetInt)(OfxPropertySetHandle properties, const char *property, int index, int value);

  /** @brief Set multiple values of a property */
  OfxStatus (*propSetPointerN)(OfxPropertySetHandle properties, const char *property, int count, void *const*value);
  OfxStatus (*propSetStringN)(OfxPropertySetHandle properties, const char *property, int count, const char *const*value);
  OfxStatus (*propSetDoubleN)(OfxPropertySetHandle properties, const char *property, int count, const double *value);
  OfxStatus (*propSetIntN)(OfxPropertySetHandle properties, const char *property, int count, const int *value);

  /** @brief Get a single value from a property */
  OfxStatus (*propGetPointer)(OfxPropertySetHandle properties, const char *property, int index, void **value);
  OfxStatus (*propGetString)(OfxPropertySetHandle properties, const char *property, int index, char **value);
  OfxStatus (*propGetDouble)(OfxPropertySetHandle properties, const char *property, int index, double *value);
  OfxStatus (*propGetInt)(OfxPropertySetHandle properties, const char *property, int index, int *value);

  /** @brief Get multiple values of a property */
  OfxStatus (*propGetPointerN)(OfxPropertySetHandle properties, const char *property, int count, void **value);
  OfxStatus (*propGetStringN)(OfxPropertySetHandle properties, const char *property, int count, char **value);
  OfxStatus (*propGetDoubleN)(OfxPropertySetHandle properties, const char *property, int count, double *value);
  OfxStatus (*propGetIntN)(OfxPropertySetHandle properties, const char *property, int count, int *value);

  /** @brief Reset a property to its default value */
  OfxStatus (*propReset)(OfxPropertySetHandle properties, const char *property);

  /** @brief Get the dimension of a property */
  OfxStatus (*propGetDimension)(OfxPropertySetHandle properties, const char *property, int *count);

} OfxPropertySuiteV1;

#ifdef __cplusplus
}
#endif

#endif
