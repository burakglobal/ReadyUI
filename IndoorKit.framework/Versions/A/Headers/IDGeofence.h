//
//  IDGeofence.h
//  IndoorKit
//
//  Copyright (c) 2016 Spreo LLC. All rights reserved.
//

#import "IDGeofenceDelegate.h"

@class IDLocation, IDUserLocation;

////////////////////////////////////////////////////////////////////////////////////////////
// IDGeofence
/*!
 * The Indoor Kit Geofence Class.
 */

@interface IDGeofence : NSObject

/*!
 * @brief The Geofence identifier.
 */
@property (nonatomic, strong) NSString *identifier;

/*!
 * @brief The Geofence name.
 */
@property (nonatomic, strong) NSString *name;

/*!
 * @brief The Geofence type.
 */
@property (nonatomic, strong) NSString *type;

/*!
 * @brief An IDLocation representation, The Geofence location.
 */
@property (nonatomic, strong) IDLocation *location;

/*!
 * @brief The Geofence radius.
 */
@property (nonatomic, assign) CGFloat radius;

/*!
 * @brief The Geofence region Rect.
 */
@property (nonatomic, assign) CGRect regionRect;

/*!
 * @brief The Geofence notifyOnIn BOOL. Notifies when User enterd Geofence.
 */
@property (nonatomic, assign) BOOL notifyOnIn;

/*!
 * @brief The Geofence notifyOnOut BOOL. Notifies when User exits Geofence.
 */
@property (nonatomic, assign) BOOL notifyOnOut;

/*!
 * @brief The Geofence notifyDuringIn BOOL. Notifies During User is In Geofence.
 */
@property (nonatomic, assign) BOOL notifyDuringIn;


/*!
 * @brief The Geofence Object reference.
 */
@property (nonatomic, strong) id reference;


- (instancetype)initWithName:(NSString *)aName
                        type:(NSString *)aType
                    location:(IDLocation *)aLocation
                      radius:(CGFloat)radius NS_DESIGNATED_INITIALIZER;

@end

////////////////////////////////////////////////////////////////////////////////////////////
//
// IDUserLocation
 
/*!
 * The Indoor Kit Beacon Geofence Class.
 */

@interface IDBeaconGeofence : IDGeofence

/*!
 * @brief The Beacon Geofence enterLevel.
 */
@property (nonatomic, assign) int enterLevel;

/*!
 * @brief The Beacon Geofence exitLevel.
 */
@property (nonatomic, assign) int exitLevel;

/*!
 * @brief The Beacon Geofence beacons Dicts Array.
 */
@property (nonatomic, strong) NSArray<NSDictionary *>* beacons;

- (instancetype)initWithName:(NSString *)aName
                        type:(NSString *)aType
                  enterLevel:(int)anEnterLevel
                   exitLevel:(int)anExitLevel NS_DESIGNATED_INITIALIZER;

@end

