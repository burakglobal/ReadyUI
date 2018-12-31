//
//  ViewController.h
//  IOSpreoSDK
//
//  Created by Hasan Sa on 9/10/15.
//  Copyright (c) 2015 SPREO. All rights reserved.
//

#import <UIKit/UIKit.h>

#import <GoogleMaps/GoogleMaps.h>

#import "IDNavigationDelegate.h"
#import "IDDualMapViewControllerDelegate.h"

#import "IDUISettings.h"
#import "IDMapViewProtocol.h"
#import "IDLocationListener.h"

@interface IDDualMapViewController : UIViewController <IDMapViewProtocol, IDNavigationDelegate, IDLocationListener>

@property (nonatomic, strong) IBOutlet GMSMapView *mapView_;

/*!
 * @brief mapMinZoomLevel The Map Minimum zoom level.
 */
@property (nonatomic, readonly) CGFloat mapMinZoomLevel;


/*!
 * @brief mapMaxZoomLevel The Map Maximum zoom level.
 */
@property (nonatomic, readonly) CGFloat mapMaxZoomLevel;


/*!
 * @brief The current presented floor map indecation.
 */
@property (nonatomic, readonly) NSInteger currentPresentedFloorID;


/*!
 * @brief The current presented facilityId.
 */
@property (nonatomic, readonly) NSString *currentPresentedFacilityID;


/*!
 * @brief settings A The Map settings.
 */
@property(nonatomic, strong, readonly) IDUISettings *settings;


/*!
 * @brief IDMapViewControllerDelegate A The Map delegate.
 */
@property (assign, nonatomic) id<IDDualMapViewControllerDelegate> delegate;



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * Controls the 'visible' region of the view.  By applying padding an area
 * arround the edge of the view can be created which will contain map data
 * but will not contain UI controls.
 *
 * If the padding is not balanced, the visual center of the view will move as
 * appropriate.  Padding will also affect the |projection| property so the
 * visible region will not include the padding area.
 * fitToBounds will ensure that both this padding and any padding requested
 * will be taken into account.
 *
 * This property may be animated within a UIView-based animation block.
 */
@property(nonatomic, assign) UIEdgeInsets padding;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * Controls the 'putUserInCampus' ability .  By applying TRUE if the user is further than 8 km from the camppus 
 * cecenter the map will focus on the campus default location
 *
 * This property may be set by User not from the main Q.
 */
@property(nonatomic, assign) BOOL putUserInCampus;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - provideGoogleMapsAPIKey:
/*!
 * Call This Method in order to set
 * @param apiKey Google Maps App API Key String
 */
- (BOOL)provideGoogleMapsAPIKey:(NSString *)apiKey;



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - setLabelVisibleByID:
/*!
 * Call This Method in order to show or hide label by ID
 * @param labelId the label id to show hide 
 * @param visible  boolean value to set the visibility 
 * the function will set the visible attribute of the label hide it from the map if visible, the  label will not show until called with visible true
 */
- (BOOL)setLabelVisibleByID:(NSString *)labelId showLabel:(BOOL)visible;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - setLabelVisibleByID:
/*!
 * Call This Method in order to show or hide label by ID
 * @param labels array of label id to show hide
 * @param visible  boolean value to set the visibility
 * the function will set the visible attribute of the label hide it from the map if visible, the  label will not show until called with visible true
 */

- (BOOL)setLabelsVisibleByID:(NSArray<NSString*> *)labels showLabel:(BOOL)visible;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - prepareMapForVenuesForFloorId:
/*!
 * Call This Method in order to set the floor index on all venues
 * @param floorId  the floor Id to set on all venues
 */
- (BOOL)prepareMapForVenuesForFloorId:(NSString*)floorId :(BOOL)forceToUpdate;
- (BOOL)forcePrepareMapForVenuesForFloorId:(NSString*)floorId;
- (void)updateUserLocationWithSmoothlyAnimation;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - getEntranceFloorId
/*!
 * Call This Method to get entrance floor id from faclity with maximum number of floors
 */
- (NSString *)getEntranceFloorId;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - getMapCenterPosition:
/*!
 * Call This Method in order to the location for the currently center of the map view
 */
-(IDLocation*) getMapCenterPosition;


/*!
 Call This Method in order to show parking poi on the map
 */
-(void)selectParkingPoi;


/*!
 Call This Method in order to set the default zoom value for the map
 @param nZoom the default zoom value for  the map
 */
-(void) setDefaultZoomLevel:(float)nZoom;


/*!
 Call This Method in order to set the minimum zoom value for the map and the maximum zoom value for the map

 @param aMinZoom the minimum zoom value for  the map
 @param aMaxZoom the maximum zoom value for  the map
 */
-(void) setMinZoom:(float)aMinZoom maxZoom:(float)aMaxZoom;

/*!
 Call This Method in order to exit from "followMeMode"
 */
-(void) exitFollowMeMode;


/*!
 Call This Method in order to add the destination marker on the map
 @param aLocation the location of destination point
 */
-(void)setFixedDestinationLocation:(IDLocation*)aLocation;

/*!
 Call This Method in order to update custom markers on the map
 */
- (void)reloadCustomMarkers;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - getTotalDistanceOfNavigationRoute
/*!
 * The method returns a total disatace of current navigation route
 */
- (NSNumber*)getTotalDistanceOfNavigationRoute;
-(void)setIc;
-(void) addPolygonWithPoiId:(NSString*)poiId :(BOOL)avaliable;
-(void) addPolygons;
-(void) removePolygonyWithId:(NSString*)poiId;
@end

