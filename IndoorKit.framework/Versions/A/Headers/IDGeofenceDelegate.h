//
//  IDGeofenceDelegate.h
//  IndoorKit
//
//  Copyright (c) 2016 Spreo LLC. All rights reserved.
//

#import "IDNavigationType.h"

@class IDGeofence;

////////////////////////////////////////////////////////////////////////////////////////////
// IDGeofenceDelegate
//
/*!
 * The IDGeofenceDelegate protocol provides feedback on the geofence events.
 */

@protocol IDGeofenceDelegate <NSObject>

////////////////////////////////////////////////////////////////////////////////////////
// - geofenceRegion:withEvent
/*!
 * This method is to be called when you have an Enterprise Permission of API KEY
 * to get the raw events when user did enter region or not
 * The method is called each time that an enabled geofence event occurred.
 * User enters a geofence region, user exits a geofence region
 * or receive events while in the geofence region
 * @note THIS METHOD CALLED IN A BACKGROUND THREAD
 * @param aGeoFence IDGeofence object
 * @param anEventType IDGeofence object
 */

- (void)geofenceRegion:(IDGeofence *)aGeoFence withEvent:(IDRegionEventType)anEventType;

@end
