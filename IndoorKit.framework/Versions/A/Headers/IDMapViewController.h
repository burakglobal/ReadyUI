//
//  IDMapViewController.h
//  IndoorKit
//
//  Copyright (c) 2016 Spreo LLC. All rights reserved.
//

#import <MapKit/MapKit.h>
#import "IDMapType.h"
#import "IDMapViewControllerDelegate.h"
#import "IDNavigationDelegate.h"
#import "IDLocationListener.h"
#import "IDMapViewProtocol.h"

////////////////////////////////////////////////////////////////////////////////////////////
//
// IDMapViewController
/*!
 * The Indoor Kit Map provides an embeddable map interface.
 * You use this class as-is to display map information and to manipulate the map contents from your application.
 * You can center the map on a given coordinate, specify the size of the area you want to display...
 */

@interface IDMapViewController : UIViewController <IDNavigationDelegate, IDLocationListener, IDMapViewProtocol>

/*!
 * @brief mapMinZoomLevel The Map Minimum zoom level.
 */
@property (nonatomic, readonly) CGFloat mapMinZoomLevel;

/*!
 * @brief mapMaxZoomLevel The Map Maximum zoom level.
 */
@property (nonatomic, readonly) CGFloat mapMaxZoomLevel;

/*!
 * @brief mapZoomLevel A The Map Current zoom level.
 */
@property (nonatomic, readonly) CGFloat mapZoomLevel;

/*!
 * @brief The current presented floor map indecation.
 */
@property (nonatomic, readonly) NSInteger currentPresentedFloorID;


/*!
 * @brief The current presented facilityId.
 */
@property (nonatomic, readonly) NSString* currentPresentedFacilityID;


/*!
 * @brief The map delegate.
 */
@property (assign, nonatomic) id<IDMapViewControllerDelegate> delegate;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - addCustomOverlayImage:atTopLeftCoordinates:bottomRightCoordinates:
/*!
 * add overlay to the outdoor mapview
 * @param anImage image for overlay
 * @param aTopLeftCoords the top left coordinate of the overlay
 * @param aBottomRightCoords the bottom right coordinate of the overlay
 * \code [self.mapViewController addCustomOverlayImage:[UIImage imageNamed:@"TVO Overlay"]
 atTopLeftCoordinates:CLLocationCoordinate2DMake(42.4943462, -83.4737563)
 andBottomRightCoordinates:CLLocationCoordinate2DMake(42.4897181, -83.4736168)];
 */
- (void)addCustomOverlayImage:(UIImage*)anImage
         atTopLeftCoordinates:(CLLocationCoordinate2D)aTopLeftCoords
    andBottomRightCoordinates:(CLLocationCoordinate2D)aBottomRightCoords;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - removeCustomOverlays:
/*!
 * remove overlay from the outdoor mapview
 */
- (void)removeCustomOverlays;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - setMapType:
/*!
 * set the outdoor mapview type
 * @param aMapType IDMapType enum
 */
- (void)setMapType:(IDMapType)aMapType;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - exitFacilityMapWhenZoomOut:
/*!
 * call this method to show the outdoor Map when zoom out from indoor Facility Map
 * @param aMode Bool vlaue default is NO
 */
- (void)exitFacilityMapWhenZoomOut:(BOOL)aMode;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - setMapRotationMode:
/*!
 * set the indoor mapview rotation mode
 * @param aRotationType IDMapRotationType enum
 * \code  [self.mapViewController setMapRotationMode:kIDMapOutdoorRotationCompass];
 [self.mapViewController setMapRotationMode:kIDMapIndoorRotationOrientation];
 */
- (void)setMapRotationMode:(IDMapRotationType)aRotationType;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - setMapBackgroundColor:
//
/*!
 * set the background color of the map
 * @param aColor UIColor
 * \code  [self.mapViewController setMapBackgroundColor:[UIColor whiteColor]];
 */
- (void)setMapBackgroundColor:(UIColor *)aColor;



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - showCameraDuringNavigationWithMode:
//
/*!
 * showCameraDuringNavigationWithMode, will show the camera session with arrow rotated to next instruction and the user location attitude,
 * The camera session is active just during navigation.
 * by default NO.
 * @param aMode BOOL visible / hidden
 * \code  [self.mapViewController showCameraDuringNavigationWithMode];
 */
- (void)showCameraDuringNavigationWithMode:(BOOL)aMode;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - setMapDrawTripOverviewWithPois:arrivedPois
//
/*!
 * The map will draw dot lines between poi locations.
 The method will number supported locations by Index, you can custom Circled views color on map
 by Implementing the IDMapViewControllerDelegate methods:
 * @see -mapColorForTripOverviewRoute:
 * @see -mapColorForTripOverviewCircle:
 * @see -mapColorForTripOverviewArrivedCircle:
 * @warning The lcoations Array Count MUST be gratter than 1 object.
 * @param aPois array of indoor pois.
 * @param anArraivedPois array of arraived pois.
 * @param drawPoisCircles set map show circle view with index number title.
 * @param addSwitchFloorsCircles array of indoor pois.
 * @param addEntrancesCircles array of arraived pois.
 */

- (void)setMapDrawTripOverviewWithPois:(NSArray*)aPois arrivedPois:(NSArray*)anArraivedPois
                       drawPoisCircles:(BOOL)drawPoisCircles
               drawSwitchFloorsCircles:(BOOL)addSwitchFloorsCircles
                  drawEntrancesCircles:(BOOL)addEntrancesCircles;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - setMapRemoveTripOverview
//
/*!
 * set the map remove all dash lines
 * \code  [self.mapViewController setMapRemoveTripOverview];
 */

-(void)setMapRemoveTripOverview;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - setMapShowLayer:mode:
//
/*!
 * set the map visible layers
 * @param aLayerType IDMapLayerType enum
 * @param aMode BOOL visible / hidden
 * \code  [self.mapViewController setMapShowLayer:kIDMapLayerFacility mode:YES];
 
 */
- (void)setMapShowLayer:(IDMapLayerType)aLayerType mode:(BOOL)aMode;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - showAllPois
//
/*!
 * the map will show all pois on map
 * \code  [self.mapViewController showAllPois];
 
 */
- (void)showAllPois;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - hideAllPois
//
/*!
 * the map will hide all pois on map
 * \code  [self.mapViewController hideAllPois];
 
 */
- (void)hideAllPois;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - showAllLabels
//
/*!
 * the map will show all Labels on map
 * \code  [self.mapViewController showAllLabels];
 
 */
- (void)showAllLabels;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - hideAllLabels
//
/*!
 * the map will hide all labels on map
 * \code  [self.mapViewController hideAllLabels];
 
 */
- (void)hideAllLabels;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - setMapShowCategory:
//
/*!
 * set the map show category
 * @param aCategory category name
 * @param aMode BOOL visible / hidden
 */
- (void)setMapShowCategory:(NSString*)aCategory mode:(BOOL)aMode;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - setVisiblePOIsWithCategories:
//
/*!
 * set the map visible poi categories array
 * @param aCategories categories Array
 */
- (void)setVisiblePOIsWithCategories:(NSArray *)aCategories;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - setMapLockToRegionPath:
//
/*!
 * set a lock to the map by a region path
 * @param aPath NSString should have format as "campusId.facilityId"
 * \code  [self.mapViewController setMapLockToRegionPath:@"myCampusId"]; // To lock the map to the outdoor map
 [self.mapViewController setMapLockToRegionPath:@"myCampusId.myFacilityId"]; // To lock the map to the indoor map
 [self.mapViewController setMapLockToRegionPath:nil]; // To unlock the map
 */
- (void)setMapLockToRegionPath:(NSString *)aPath;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - setPoiRegionRadius:
//
/*!
 * set the radius for the poi region, when a user steep in or out that region the methods of the
 * IDPoiViewProtocol protocol are called (will be deprecated)
 * IDCalloutProtocol protocol are called
 * @param aRadius NSInteger
 */
- (void)setPoiRegionRadius:(NSInteger)aRadius;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - setMaxPoiPopups:
//
/*!
 * set the max number of pois popup on map, this number limits the number of poi popups on map
 * in vicinity to user location
 * 3 pois popup is the default number
 * @param aNumber NSInteger
 */
- (void)setMaxPoiPopupsNumber:(NSInteger)aNumber;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - setMapAutoFollowUserMode:
//
/*!
 set map auto follow user location mode, by defult the mode will be YES
 @param aMode BOOL value
 */
- (void)setMapAutoFollowUserMode:(BOOL)aMode;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - setUserAutoFollowTimeInterval:
//
/*!
 * set time gap from last user interaction to auto follow user location
 * @param aDuration NSTimeInterval
 */
- (void)setUserAutoFollowTimeInterval:(NSTimeInterval)aDuration;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - presentLocation:
//
/*!
 * The map will present and center location
 * @param aLocation IDLocation
 */
- (void)presentLocation:(IDLocation *)aLocation;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//-presentUserLocationWithBubble:
//
/*!
 * User location will be presented with a customised bubble
 * @param aBubbleView UIView
 */
- (void)presentUserLocationWithBubble:(UIView*)aBubbleView;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - presentPoiOnMapWithPoi:
//
/*!
 * The map will present and center Poi
 * @param aPoi IDPoi
 */
- (void)presentPoiOnMapWithPoi:(IDPoi *)aPoi;



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - showBubbleForPoi:
//
/*!
 * The map will show bubble for poi in case the user SDK Provied Custom Poi
 * use this method when get map did select Poi On Map
 * the (IDMapViewControllerDelegate method - (void)mapDidSelectPOI:(IDPoi *)aPoi)
 * @param aPoi IDPoi
 */
- (void)showBubbleForPoi:(IDPoi *)aPoi ;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - updatePresentation
- (void)updatePresentationMode:(IDPoi *)aPoi :(BOOL)mode;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - hideBubbleForPoi:
//
/*!
 * The map will hide bubble for poi
 * @param aPoi IDPoi
 */
- (void)hideBubbleForPoi:(IDPoi*)aPoi;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - centerFacilityMapWithFacilityId:atCampusId:
//
/*!
 * The map will show indoor facility map
 * @param aFacilityId the facility to Present
 * @param aCampusId at campus
 */
- (void)centerFacilityMapWithFacilityId:(NSString*)aFacilityId atCampusId:(NSString*)aCampusId;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - centerCampusMapWithCampusId:
//
/*!
 * The map will show outdoor campus map
 * @param aCampusId at campus
 */
- (void)centerCampusMapWithCampusId:(NSString*)aCampusId;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - viewForPoi:
//
/*!
 method returns the associated view for the provided poi
 @param aPoi IDPoi
 @return view for the provided poi;
 */
- (UIView *)viewForPoi:(IDPoi *)aPoi;



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - getFloorTitleForFloorID:
/*!
 * The title for map floors indecation
 * @param aFloorID the floor title
 * @return Returns floor title
 */
- (NSString *)getFloorTitleForFloorID:(NSInteger)aFloorID;



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - getMapViewID:
/*!
 * The map map type kIDMapViewIndoor or kIDMapViewOutdoor
 * @return Returns IDMapViewId enum type
 */
@property (nonatomic, getter=getMapViewID, readonly) IDMapViewId mapViewID;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - showFloorWithId:
//
/*!
 * The indoor mapview will present floor map
 @param aFloorID floor index
 */
- (void)showFloorWithID:(NSInteger)aFloorID;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - showMyPosition
//
/*!
 * The map will center the user position
 */
- (void)showMyPosition;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - mapZoomIn
//
/*!
 * The map will be zoomed in
 * @return Returns YES if the zoom in not the max zoom scale else will return NO
 */
- (BOOL)zoomIn;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - mapZoomOut
//
/*!
 * The map will be zoomed out
 * @return Returns YES if current zoom not the min zoom scale else will return NO
 */
- (BOOL)zoomOut;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - setMapZoomLevel:
//
/*!
 * The map will be zoomed by the given value,  available for the indoor map only.
 * @param aMapZoomLevel The zoom level to set.
 * @return Returns YES if current zoom not the min zoom scale else will return NO
 */

- (BOOL)setMapZoomLevel:(CGFloat)aMapZoomLevel;
- (void)setMapZoomSWFT:(CGFloat)zoomLevel;
- (void)changePOIIcons:(float)size;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - mapReload
//
/*!
 * the map will reload map views for either outdoor mapview or indoor mapview
 */
- (void)mapReload;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - mapClosePOIsBubbles
//
/*!
 * The method close all open POIs bubbles
 */
- (void)mapClosePOIsBubbles;



- (void)showLocationSharingUsers:(NSArray*)aUsers;
- (void)hideLocationSharingUsers;

@end
