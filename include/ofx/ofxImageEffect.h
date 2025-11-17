#ifndef _ofxImageEffect_h_
#define _ofxImageEffect_h_

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
#include "ofxParam.h"

#include <stddef.h>  /* For size_t */

#ifdef __cplusplus
extern "C" {
#endif

/** @file ofxImageEffect.h
Contains the definitions for the Image Effect API.
*/

/** @brief String used to label OFX Image Effect Plug-ins */
#define kOfxImageEffectPluginApi "OfxImageEffectPluginAPI"

/** @brief The current version of the Image Effect API */
#define kOfxImageEffectPluginApiVersion 1

/** @brief Blind declaration of an OFX image effect instance */
typedef struct OfxImageEffectStruct *OfxImageEffectHandle;

/** @brief Blind declaration of an OFX image effect clip */
typedef struct OfxImageClipStruct *OfxImageClipHandle;

/** @name Image Effect Contexts
 *
 * Different hosts support different contexts. A plugin can be used in a
 * context only if the host supports it.
 */
/*@{*/

/** @brief Image effect context - general */
#define kOfxImageEffectContextGenerator "OfxImageEffectContextGenerator"

/** @brief Image effect context - filter */
#define kOfxImageEffectContextFilter "OfxImageEffectContextFilter"

/** @brief Image effect context - transition */
#define kOfxImageEffectContextTransition "OfxImageEffectContextTransition"

/** @brief Image effect context - paint */
#define kOfxImageEffectContextPaint "OfxImageEffectContextPaint"

/** @brief Image effect context - general */
#define kOfxImageEffectContextGeneral "OfxImageEffectContextGeneral"

/** @brief Image effect context - retimer */
#define kOfxImageEffectContextRetimer "OfxImageEffectContextRetimer"

/*@}*/

/** @name Clip Component Types
 *
 * These are the types of image components.
 */
/*@{*/

/** @brief RGBA components */
#define kOfxImageComponentRGBA "OfxImageComponentRGBA"

/** @brief RGB components */
#define kOfxImageComponentRGB "OfxImageComponentRGB"

/** @brief Alpha components */
#define kOfxImageComponentAlpha "OfxImageComponentAlpha"

/** @brief Single component (e.g., luminance) */
#define kOfxImageComponentNone "OfxImageComponentNone"

/*@}*/

/** @name Pixel Depths
 *
 * These are the bit depths supported by the OFX image effect API.
 */
/*@{*/

/** @brief Pixel data is 8 bit per component */
#define kOfxBitDepthByte "OfxBitDepthByte"

/** @brief Pixel data is 16 bit per component */
#define kOfxBitDepthShort "OfxBitDepthShort"

/** @brief Pixel data is 32 bit floating point per component */
#define kOfxBitDepthFloat "OfxBitDepthFloat"

/** @brief Pixel data is of unknown type */
#define kOfxBitDepthNone "OfxBitDepthNone"

/*@}*/

/** @name Image Effect Properties
 */
/*@{*/

/** @brief Property on the image effect descriptor or instance, the contexts it is designed for */
#define kOfxImageEffectPropSupportedContexts "OfxImageEffectPropSupportedContexts"

/** @brief Property on the image effect descriptor or instance - the pixel depths it supports */
#define kOfxImageEffectPropSupportedPixelDepths "OfxImageEffectPropSupportedPixelDepths"

/** @brief Property on the image effect instance - the current context */
#define kOfxImageEffectPropContext "OfxImageEffectPropContext"

/** @brief Property on the host descriptor, what pixel depths does it support */
#define kOfxImageEffectPropPixelDepth "OfxImageEffectPropPixelDepth"

/** @brief Property that indicates which components are supported */
#define kOfxImageEffectPropComponents "OfxImageEffectPropComponents"

/** @brief Property to indicate whether the effect can handle tiles */
#define kOfxImageEffectPropSupportsTiles "OfxImageEffectPropSupportsTiles"

/** @brief Property to indicate whether the effect is temporal */
#define kOfxImageEffectPropTemporalClipAccess "OfxImageEffectPropTemporalClipAccess"

/** @brief Property to indicate whether the effect supports multiple clip depths */
#define kOfxImageEffectPropSupportsMultipleClipDepths "OfxImageEffectPropSupportsMultipleClipDepths"

/** @brief Property to indicate whether the effect supports multiple clip PARs */
#define kOfxImageEffectPropSupportsMultipleClipPARs "OfxImageEffectPropSupportsMultipleClipPARs"

/** @brief Property to indicate whether the effect supports multi-resolution */
#define kOfxImageEffectPropSupportsMultiResolution "OfxImageEffectPropSupportsMultiResolution"

/** @brief Property to indicate the render thread safety of the effect */
#define kOfxImageEffectPropRenderThreadSafety "OfxImageEffectPropRenderThreadSafety"

/** @brief Property to indicate the current render time */
#define kOfxPropTime "OfxPropTime"

/** @brief Property for plugin grouping (category) */
#define kOfxImageEffectPluginPropGrouping "OfxImageEffectPluginPropGrouping"

/** @brief Property to flag that an effect is a transition */
#define kOfxImageEffectPropTransition "OfxImageEffectPropTransition"

/** @brief Property to indicate the frame rate of a clip */
#define kOfxImageEffectPropFrameRate "OfxImageEffectPropFrameRate"

/** @brief Property to indicate the frame range of a clip */
#define kOfxImageEffectPropFrameRange "OfxImageEffectPropFrameRange"

/** @brief Property to indicate the unmapped frame rate */
#define kOfxImageEffectPropUnmappedFrameRate "OfxImageEffectPropUnmappedFrameRate"

/** @brief Property to indicate the unmapped frame range */
#define kOfxImageEffectPropUnmappedFrameRange "OfxImageEffectPropUnmappedFrameRange"

/** @brief Property on the image effect host descriptor, the project size */
#define kOfxImageEffectPropProjectSize "OfxImageEffectPropProjectSize"

/** @brief Property on the image effect host descriptor, the project offset */
#define kOfxImageEffectPropProjectOffset "OfxImageEffectPropProjectOffset"

/** @brief Property on the image effect host descriptor, the project extent */
#define kOfxImageEffectPropProjectExtent "OfxImageEffectPropProjectExtent"

/** @brief Property on the image effect host descriptor, the project pixel aspect ratio */
#define kOfxImageEffectPropProjectPixelAspectRatio "OfxImageEffectPropProjectPixelAspectRatio"

/** @brief Property to indicate the region of definition of a clip */
#define kOfxImageEffectPropRegionOfDefinition "OfxImageEffectPropRegionOfDefinition"

/** @brief Property to indicate the region of interest of a clip */
#define kOfxImageEffectPropRegionOfInterest "OfxImageEffectPropRegionOfInterest"

/** @brief Property to get the current render scale */
#define kOfxImageEffectPropRenderScale "OfxImageEffectPropRenderScale"

/** @brief Property on an image, the actual rect of the image data */
#define kOfxImagePropBounds "OfxImagePropBounds"

/** @brief Property on an image, the full region of the image */
#define kOfxImagePropRegionOfDefinition "OfxImagePropRegionOfDefinition"

/** @brief Property on an image, the row distance in bytes */
#define kOfxImagePropRowBytes "OfxImagePropRowBytes"

/** @brief Property on an image, the pointer to the image data */
#define kOfxImagePropData "OfxImagePropData"

/** @brief Property on an image, the unique identifier of an image */
#define kOfxImagePropUniqueIdentifier "OfxImagePropUniqueIdentifier"

/** @brief Property on an image, the pixel aspect ratio */
#define kOfxImagePropPixelAspectRatio "OfxImagePropPixelAspectRatio"

/** @brief Property on an image, indicates whether the image has premultiplied alpha */
#define kOfxImageEffectPropPreMultiplication "OfxImageEffectPropPreMultiplication"

/** @brief Property on a clip, is the clip optional */
#define kOfxImageClipPropOptional "OfxImageClipPropOptional"

/** @brief Property on a clip, what are the supported components */
#define kOfxImageClipPropSupportedComponents "OfxImageClipPropSupportedComponents"

/** @brief Property on a clip, does the clip support tiles */
#define kOfxImageClipPropIsMask "OfxImageClipPropIsMask"

/** @brief Property on a clip - what is the name of the connected clip */
#define kOfxImageClipPropConnected "OfxImageClipPropConnected"

/** @brief Property on a clip - the unmapped frame rate of a clip */
#define kOfxImageClipPropUnmappedFrameRate "OfxImageClipPropUnmappedFrameRate"

/** @brief Property on a clip - the unmapped frame range */
#define kOfxImageClipPropUnmappedFrameRange "OfxImageClipPropUnmappedFrameRange"

/** @brief Property on a clip or image - what are the components */
#define kOfxImageEffectPropComponentsPresent "kOfxImageEffectPropComponentsPresent"

/** @brief Property to indicate the render window */
#define kOfxImageEffectPropRenderWindow "OfxImageEffectPropRenderWindow"

/** @brief Property to indicate whether to render in sequential order */
#define kOfxImageEffectPropSequentialRender "OfxImageEffectPropSequentialRender"

/** @brief Property on effect instance - whether the instance can be interactively rendered */
#define kOfxImageEffectInstancePropEffectDuration "OfxImageEffectInstancePropEffectDuration"

/** @brief Property on effect instance - whether the instance can be interactively rendered */
#define kOfxImageEffectInstancePropSequentialRender "OfxImageEffectInstancePropSequentialRender"

/*@}*/

/** @name Premultiplication State
 */
/*@{*/

/** @brief Image is opaque */
#define kOfxImageOpaque "OfxImageOpaque"

/** @brief Image is premultiplied */
#define kOfxImagePreMultiplied "OfxImagePreMultiplied"

/** @brief Image is unpremultiplied */
#define kOfxImageUnPreMultiplied "OfxImageUnPreMultiplied"

/*@}*/

/** @name Render Thread Safety
 */
/*@{*/

/** @brief Indicates that a plugin is not thread safe */
#define kOfxImageEffectRenderUnsafe "OfxImageEffectRenderUnsafe"

/** @brief Indicates that a plugin instance is thread safe */
#define kOfxImageEffectRenderInstanceSafe "OfxImageEffectRenderInstanceSafe"

/** @brief Indicates that a plugin is fully thread safe */
#define kOfxImageEffectRenderFullySafe "OfxImageEffectRenderFullySafe"

/*@}*/

/** @name Standard Clip Names
 */
/*@{*/

/** @brief Name of the source clip */
#define kOfxImageEffectSimpleSourceClipName "Source"

/** @brief Name of the output clip */
#define kOfxImageEffectOutputClipName "Output"

/** @brief Name of the transition source from clip */
#define kOfxImageEffectTransitionSourceFromClipName "SourceFrom"

/** @brief Name of the transition source to clip */
#define kOfxImageEffectTransitionSourceToClipName "SourceTo"

/*@}*/

/** @name Image Effect Actions
 */
/*@{*/

/** @brief Action to get a region of definition */
#define kOfxImageEffectActionGetRegionOfDefinition "OfxImageEffectActionGetRegionOfDefinition"

/** @brief Action to get regions of interest */
#define kOfxImageEffectActionGetRegionsOfInterest "OfxImageEffectActionGetRegionsOfInterest"

/** @brief Action to get frames needed */
#define kOfxImageEffectActionGetFramesNeeded "OfxImageEffectActionGetFramesNeeded"

/** @brief Action to get the clip preferences */
#define kOfxImageEffectActionGetClipPreferences "OfxImageEffectActionGetClipPreferences"

/** @brief Action to check if an instance is performing an identity operation */
#define kOfxImageEffectActionIsIdentity "OfxImageEffectActionIsIdentity"

/** @brief Action to render an image */
#define kOfxImageEffectActionRender "OfxImageEffectActionRender"

/** @brief Action called when begin sequence render */
#define kOfxImageEffectActionBeginSequenceRender "OfxImageEffectActionBeginSequenceRender"

/** @brief Action called when end sequence render */
#define kOfxImageEffectActionEndSequenceRender "OfxImageEffectActionEndSequenceRender"

/** @brief Action to get the time domain */
#define kOfxImageEffectActionGetTimeDomain "OfxImageEffectActionGetTimeDomain"

/*@}*/

/** @name Image Effect Suite Name and Version
 */
/*@{*/

/** @brief Name of the image effect suite */
#define kOfxImageEffectSuite "OfxImageEffectSuite"

/*@}*/

/** @name Forward Type Declarations
 */
/*@{*/

/** @brief OFX rectangle in doubles */
typedef struct OfxRectD {
  double x1, y1, x2, y2;
} OfxRectD;

/** @brief OFX rectangle in integers */
typedef struct OfxRectI {
  int x1, y1, x2, y2;
} OfxRectI;

/** @brief Blind declaration of OFX image memory handle */
typedef struct OfxImageMemoryStruct *OfxImageMemoryHandle;

/*@}*/

/** @brief OFX Image Effect Suite V1
 *
 * This is the suite of functions that a host must implement to support
 * image effect plugins.
 */
typedef struct OfxImageEffectSuiteV1 {
  /** @brief Retrieves the property set handle for the given image effect */
  OfxStatus (*getPropertySet)(OfxImageEffectHandle imageEffect,
                               OfxPropertySetHandle *propHandle);

  /** @brief Retrieves the parameter set for the given image effect */
  OfxStatus (*getParamSet)(OfxImageEffectHandle imageEffect,
                           OfxParamSetHandle *paramSet);

  /** @brief Define a clip on an image effect descriptor */
  OfxStatus (*clipDefine)(OfxImageEffectHandle imageEffect,
                          const char *name,
                          OfxPropertySetHandle *propertySet);

  /** @brief Retrieves a clip from the image effect */
  OfxStatus (*clipGetHandle)(OfxImageEffectHandle imageEffect,
                             const char *name,
                             OfxImageClipHandle *clip,
                             OfxPropertySetHandle *propertySet);

  /** @brief Retrieves the property set for the given clip */
  OfxStatus (*clipGetPropertySet)(OfxImageClipHandle clip,
                                  OfxPropertySetHandle *propHandle);

  /** @brief Get an image from a clip at the given time */
  OfxStatus (*clipGetImage)(OfxImageClipHandle clip,
                            double time,
                            const OfxRectD *region,
                            OfxPropertySetHandle *imageHandle);

  /** @brief Releases an image */
  OfxStatus (*clipReleaseImage)(OfxPropertySetHandle imageHandle);

  /** @brief Get the region of definition for a clip at the given time */
  OfxStatus (*clipGetRegionOfDefinition)(OfxImageClipHandle clip,
                                        double time,
                                        OfxRectD *bounds);

  /** @brief Aborts rendering */
  int (*abort)(OfxImageEffectHandle imageEffect);

  /** @brief Allocates memory */
  OfxStatus (*imageMemoryAlloc)(OfxImageEffectHandle instanceHandle,
                                size_t nBytes,
                                OfxImageMemoryHandle *memoryHandle);

  /** @brief Locks memory */
  OfxStatus (*imageMemoryLock)(OfxImageMemoryHandle memoryHandle,
                               void **returnedPtr);

  /** @brief Unlocks memory */
  OfxStatus (*imageMemoryUnlock)(OfxImageMemoryHandle memoryHandle);

  /** @brief Frees memory */
  OfxStatus (*imageMemoryFree)(OfxImageMemoryHandle memoryHandle);

} OfxImageEffectSuiteV1;

#ifdef __cplusplus
}
#endif

#endif
