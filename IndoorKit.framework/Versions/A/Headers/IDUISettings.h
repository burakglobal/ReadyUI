//
//  IDUISettings.h
//  IOSSpreoSDK
//
//  Created by Hasan Sa on 06/10/2015.
//  Copyright © 2015 Spreo LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface IDUISettings : NSObject

/**
 * Enables (default) or disables the indoor floor picker. If enabled, it is only
 * visible when the view is focused on a building with indoor floor data.
 */
@property(nonatomic, assign) BOOL indoorPicker;

/**
 * Custom the indoorPicker background color.
 */
@property(nonatomic, strong) UIColor* indoorPickerBackgroundColor;


/**
 * Custom the indoorPicker position and reposition the indoorPicker’s x and y origin.
 *
 */
@property(nonatomic, assign) CGPoint indoorPickerOrigin;


/**
 * Enables or disables the My Location button. This is a button visible on the
 * map that, when tapped by users, will center the map on the current user
 * location.
 */
@property(nonatomic, assign) BOOL myLocationButton;


/**
 * If set, Google 3D buildings will be shown where available.  Defaults to YES.
 *
 */
@property(nonatomic, assign) BOOL buildingsEnabled;


/**
 * Controls whether rotate gestures are enabled (default) or disabled. If
 * enabled, users may use a two-finger rotate gesture to rotate the camera.
 */
@property(nonatomic, assign) BOOL rotateGestures;

/**
 * In case of NO MapViewController behaves as following:
 *
 * When the chosen floor on the floor picker does not exist for a specific building a MapViewController will not draw
 * all the floor data for that building. For example if the chosen floor on the floor picker is 5 and the building has
 * only 3 floors MapViewController will not draw the POIs, facility overlay, navigation path, parking, etc... on that
 * building.
 *
 * Default is YES.
 */
@property(nonatomic, assign) BOOL displayTopFloorContent;

@end
