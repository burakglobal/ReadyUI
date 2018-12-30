//
//  IDMapType.h
//  IndoorKit
//
//  Copyright (c) 2016 Spreo LLC. All rights reserved.
//


#ifndef NS_ENUM
@import Foundation;
#endif

////////////////////////////////////////////////////////////////////////////////////////////
// IDMapType
//

/*!
 * @typedef IDMapType
 * @discussion The outdoor map types.
 */

typedef NS_ENUM(NSInteger, IDMapType) {
    kIDMapTypeStandard,
    kIDMapTypeSatellite,
    kIDMapTypeHybrid
};


////////////////////////////////////////////////////////////////////////////////////////////
// IDMapRotationType
//
/*! 
 * @typedef IDMapRotationType
 * @discussion The map rotation types.
 */

typedef NS_ENUM(NSInteger, IDMapRotationType) {
    kIDMapRotationStatic,
    kIDMapRotationCompass,
    kIDMapRotationOrientation, // NOT IMPLEMENTED YET
    KIDMapRotationNavigation

};


////////////////////////////////////////////////////////////////////////////////////////////
// IDMapLayerType
//
/*! 
 * @typedef IDMapLayerType
 * @discussion The map layers types.
 */

typedef NS_ENUM(NSInteger, IDMapLayerType) {
    kIDMapLayerLabels,
    kIDMapLayerPOIs,
    kIDMapLayerPaths,
    kIDMapLayerRoute,
    kIDMapLayerParking,
    kIDMapLayerUser
};


////////////////////////////////////////////////////////////////////////////////////////////
// IDMapViewId
//
/*!
 * @typedef IDMapViewId
 * @discussion The map view type.
 */

typedef NS_ENUM(NSInteger, IDMapViewId) {
    kIDMapViewUnknown,
    kIDMapViewIndoor,
    kIDMapViewOutdoor
};
