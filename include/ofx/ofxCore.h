#ifndef _ofxCore_h_
#define _ofxCore_h_

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

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifdef __cplusplus
extern "C" {
#endif

/** @file ofxCore.h
Contains the core OFX architectural struct and function definitions.
*/

/** @brief Platform independent export macro.
 *
 * This macro should be used on any external entry point to the plugin.
 */
#if defined(WIN32) || defined(WIN64)
  #define OfxExport extern __declspec(dllexport)
#else
  #define OfxExport extern
#endif

/** @brief Blind data structure to manipulate sets of properties through */
typedef struct OfxPropertySetStruct *OfxPropertySetHandle;

/** @brief OFX status return type */
typedef int OfxStatus;

/** @name OFX Status Codes
 *
 * These are the return codes for OFX functions.
 */
/*@{*/

/** @brief Status error code for a successful operation. */
#define kOfxStatOK 0

/** @brief Status error code for a failed operation. */
#define kOfxStatFailed 1

/** @brief Status error code for a fatal error in a plug-in. */
#define kOfxStatErrFatal 2

/** @brief Status error code for an unknown error. */
#define kOfxStatErrUnknown 3

/** @brief Status error code for missing host feature */
#define kOfxStatErrMissingHostFeature 4

/** @brief Status error code for an unsupported feature */
#define kOfxStatErrUnsupported 5

/** @brief Status error code for an object being in an inappropriate state */
#define kOfxStatErrExists 6

/** @brief Status error code for an invalid handle */
#define kOfxStatErrBadHandle 7

/** @brief Status error code for an out of memory error */
#define kOfxStatErrMemory 8

/** @brief Status error code for an invalid property value */
#define kOfxStatErrValue 9

/** @brief Status error code for an action being called after it should be */
#define kOfxStatReplyYes 10

/** @brief Status error code for an action being called before it should be */
#define kOfxStatReplyNo 11

/** @brief Status error code for an action that has not been trapped by a plug-in */
#define kOfxStatReplyDefault 12

/** @brief Status error code for an invalid index value */
#define kOfxStatErrBadIndex 13

/*@}*/

/** @name OFX Property types
 */
/*@{*/
/** @brief Property type */
typedef const char *OfxPropertyTypeEnum;

/** @brief String property type */
#define kOfxTypeString "OfxTypeString"

/** @brief Integer property type */
#define kOfxTypeInt "OfxTypeInt"

/** @brief Double property type */
#define kOfxTypeDouble "OfxTypeDouble"

/** @brief Pointer property type */
#define kOfxTypePointer "OfxTypePointer"

/*@}*/

/** @name Common Property Names
 */
/*@{*/

/** @brief General property, giving the version of a host or plugin */
#define kOfxPropType "OfxPropType"

/** @brief General property, giving the name of an object */
#define kOfxPropName "OfxPropName"

/** @brief General property, giving the label of an object */
#define kOfxPropLabel "OfxPropLabel"

/** @brief General property, giving the short label of an object */
#define kOfxPropShortLabel "OfxPropShortLabel"

/** @brief General property, giving the long label of an object */
#define kOfxPropLongLabel "OfxPropLongLabel"

/** @brief General property, giving the version of a host or plugin */
#define kOfxPropVersion "OfxPropVersion"

/** @brief General property, giving the version of a host or plugin as a string */
#define kOfxPropVersionLabel "OfxPropVersionLabel"

/** @brief General property, giving the API version */
#define kOfxPropAPIVersion "OfxPropAPIVersion"

/** @brief General property to flag a feature as optional */
#define kOfxPropIsOptional "OfxPropIsOptional"

/*@}*/

/** @name Property Suite Function types
 */
/*@{*/

/** @brief The property suite fetch function type */
typedef OfxStatus (*OfxPropertySuiteV1_t)(const void *properties, int count, ...);

/*@}*/

/** @brief Forward declaration of OfxHost struct */
typedef struct OfxHost OfxHost;

/** @brief Forward declaration of OfxPlugin struct */
typedef struct OfxPlugin OfxPlugin;

/** @brief Entry point for plug-ins to fetch suites from the host.
 *
 * This is the way a plugin gets access to suites from the host.
 * A plugin uses this in the mainEntry function and during actions.
 */
typedef const void *(*OfxGetPropertySetFunc)(const void *host, const char *property);

/** @brief OFX Host struct
 *
 * This is the structure that the host passes to a plugin's setHost function.
 * It contains data about the host and how to fetch host suites.
 */
struct OfxHost {
  /** @brief Global host properties */
  OfxPropertySetHandle host;

  /** @brief The function which the plugin uses to fetch suites from the host */
  const void *(*fetchSuite)(OfxPropertySetHandle host, const char *suiteName, int suiteVersion);
};

/** @brief OFX Plugin struct
 *
 * This structure is returned by the OfxGetPlugin function, and
 * contains all the information about a plugin.
 */
struct OfxPlugin {
  /** @brief Defines the type of the plugin, this must be one of the strings in \ref kOfxPluginTypes */
  const char *pluginApi;

  /** @brief Defines the version of the pluginAPI used by this plugin */
  int apiVersion;

  /** @brief String that uniquely identifies the plugin to a human. */
  const char *pluginIdentifier;

  /** @brief Major version of this plugin */
  unsigned int pluginVersionMajor;

  /** @brief Minor version of this plugin */
  unsigned int pluginVersionMinor;

  /** @brief Function the host calls when it wants to initialize the plugin. */
  void (*setHost)(OfxHost *host);

  /** @brief Main entry point for the plugin */
  OfxStatus (*mainEntry)(const char *action,
                         const void *handle,
                         OfxPropertySetHandle inArgs,
                         OfxPropertySetHandle outArgs);
};

/** @name Plugin Entry Points
 */
/*@{*/

/** @brief Function to get the number of plugins in a binary. */
OfxExport int OfxGetNumberOfPlugins(void);

/** @brief Function to get the nth plugin in a binary. */
OfxExport OfxPlugin *OfxGetPlugin(int nth);

/*@}*/

/** @name Common action strings
 */
/*@{*/

/** @brief Action called after the setHost function has been called */
#define kOfxActionLoad "OfxActionLoad"

/** @brief Action called before a plugin is released and destroyed */
#define kOfxActionUnload "OfxActionUnload"

/** @brief Action called to describe the plugin */
#define kOfxActionDescribe "OfxActionDescribe"

/** @brief Action called to create an instance of a plugin */
#define kOfxActionCreateInstance "OfxActionCreateInstance"

/** @brief Action called to destroy an instance of a plugin */
#define kOfxActionDestroyInstance "OfxActionDestroyInstance"

/** @brief Action called to describe an instance of a plugin */
#define kOfxActionDescribeInContext "OfxActionDescribeInContext"

/** @brief Action called to begin a render sequence */
#define kOfxActionBeginInstanceChanged "OfxActionBeginInstanceChanged"

/** @brief Action called when a parameter value has changed */
#define kOfxActionInstanceChanged "OfxActionInstanceChanged"

/** @brief Action called to end a render sequence */
#define kOfxActionEndInstanceChanged "OfxActionEndInstanceChanged"

/** @brief Action called to purge any cached data */
#define kOfxActionPurgeCaches "OfxActionPurgeCaches"

/** @brief Action called to sync private data structures to parameters */
#define kOfxActionSyncPrivateData "OfxActionSyncPrivateData"

/** @brief Action called to begin a sequence of rendering */
#define kOfxActionBeginInstanceEdit "OfxActionBeginInstanceEdit"

/** @brief Action called to end a sequence of rendering */
#define kOfxActionEndInstanceEdit "OfxActionEndInstanceEdit"

/*@}*/

#ifdef __cplusplus
}
#endif

#endif
