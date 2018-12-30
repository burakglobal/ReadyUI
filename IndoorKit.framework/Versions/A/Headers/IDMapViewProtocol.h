//
//  IDMapViewProtocol.h
//  IOSSpreoSDK
//
//  Created by Hasan Sa on 06/10/2015.
//  Copyright © 2015 Spreo LLC. All rights reserved.
//

#ifndef IDMapViewProtocol_h
#define IDMapViewProtocol_h

#import <IndoorKit/IDMapType.h>

@class IDPoi;
@class IDRoute;

@protocol IDMapViewProtocol <NSObject>


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
// - setMapType:
/*!
 * set the outdoor mapview type
 * @param aMapType IDMapType enum
 */
- (void)setMapType:(IDMapType)aMapType;


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
// - setMapIcon:forPoi:
//
/*!
 * Deprecated method.
 * USE aPoi.icon property setter then call the map with map reload API
 * @code [self.mapViewController setMapIcon:[UIImage imageNamed:@"selected-green-icon" forPoi:myPoi];
 */
- (void)setMapIcon:(UIImage *)anIcon forPoi:(IDPoi *)aPoi;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - setMapBubblesMode:
//
/*!
 * allow the map to enable / disable bubble view presentation for all pois, defaults to POIs configuration (CMS Data).
 * in case aMode = NO or not if YES, default bubble mode enabled
 * @param aMode turn on / off bubbles mode
 */
- (void)setMapBubblesMode:(BOOL)aMode;
- (void)setMapBubblesModeForNavigation:(BOOL)aMode;



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - setMapBubblesMode:forPoi:
//
/*!
 * allow the map to enable / disable bubble view presentation for poi, defaults to POIs configuration (CMS Data).
 * in case aMode = NO or not if YES, default bubble mode enabled
 * @param aMode turn on / off bubbles mode
 */
- (void)setMapBubbleMode:(BOOL)aMode forPoi:(IDPoi*)aPoi;


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
// - setVisiblePOIsWithCategories:
//
/*!
 * Set the map show visible poi categories array.
 * @param aCategories the pois categories Array.
 * @note in case the aCategories parameter is nil, the Map will show all Pois.
 */
- (void)setVisiblePOIsWithCategories:(NSArray <NSString*> *)aCategories;



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - setVisiblePOIsWithIds:
//
/*!
 * Set the map show visible pois with ids array.
 * @param aPoisIds pois ids [NSString] Array.
 * @note in case the aPoisIds parameter is nil, the Map will show all Pois.
 */
- (void)setVisiblePOIsWithIds:(NSArray <NSString*> *)aPoisIds;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - setHideLabelsforPois:
//
- (void)updatePOIIcon:(IDPoi*)aPoi :(UIImage*_Nullable)icon;
- (void)setShowAllOnZoomLevel:(IDPoi *_Nullable)aPoi :(BOOL)mode;
- (void)setIsIconShown:(IDPoi *_Nullable)aPoi :(BOOL)mode;
- (void)setLabelAlgorithm:(IDPoi *_Nullable)aPoi :(BOOL)mode;
-(BOOL)getShowOnAllZoomLevels:(IDPoi *_Nullable)aPoi;
-(BOOL)getHidePoiIcon:(IDPoi *_Nullable)aPoi;
-(BOOL)getLabelAlgoritmForPoi:(IDPoi *_Nullable)aPoi;
- (void)setIsShowLabel:(IDPoi *_Nullable)aPoi :(BOOL)mode;
- (void)addTiles;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - setMapAutoFollowUserMode:
//
/*!
 * Set map auto follow user location mode, by defult the mode will be YES
 * @param aMode BOOL value
 */
- (void)setMapAutoFollowUserMode:(BOOL)aMode;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - setUserAutoFollowTimeInterval:
//
/*!
 * Set time gap from last user interaction to auto follow user location
 * @param aDuration NSTimeInterval
 */
- (void)setUserAutoFollowTimeInterval:(NSTimeInterval)aDuration;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - presentLocation:
//
/*!
 * The map will present and center location.
 * @param aLocation IDLocation.
 */
- (void)presentLocation:(IDLocation *)aLocation;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - presentPoiOnMapWithPoi:
//
/*!
 * The map will present and center Poi.
 * @param aPoi IDPoi.
 */
- (void)presentPoiOnMapWithPoi:(IDPoi *)aPoi;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - updatePresentation
- (void)updatePresentationMode:(IDPoi *)aPoi :(BOOL)mode;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - showBubbleForPoi:
//
/*!
 * The map will show bubble for poi in case the user SDK Provied Custom Poi.
 * use this method when get map did select or did tap Poi On Map.
 * @param aPoi IDPoi
 */
- (void)showBubbleForPoi:(IDPoi *)aPoi;



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - hideBubbleForPoi:
//
/*!
 * The map will hide bubble for poi
 * @param aPoi IDPoi
 */
- (void)hideBubbleForPoi:(IDPoi *)aPoi;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - centerFacilityMapWithFacilityId:atCampusId:
//
/*!
 * The map will show indoor facility map
 * @param aFacilityId the facility to Present
 * @param aCampusId at campus
 */
- (void)centerFacilityMapWithFacilityId:(NSString *)aFacilityId atCampusId:(NSString *)aCampusId;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - centerCampusMapWithCampusId:
//
/*!
 * The map will show outdoor campus map
 * @param aCampusId at campus
 */
- (void)centerCampusMapWithCampusId:(NSString *)aCampusId;



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - showFloorWithId:
//
/*!
 * The indoor mapview will present floor map
 * @param aFloorID floor index
 * @param aFacilityId the floorId of the desiered facility, nil is current presented facility
 */
- (void)showFloorWithID:(NSInteger)aFloorID atFacilityWithId:(NSString *)aFacilityId;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - showMyPosition
//
/*!
 * The map will center the user position
 */
- (void)showMyPosition;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - zoomIn
//
/*!
 * The map will be zoomed in
 * @return Returns YES if the zoom in not the max zoom scale else will return NO
 */
- (BOOL)zoomIn;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - zoomOut
//
/*!
 * The map will be zoomed out
 * @return Returns YES if current zoom not the min zoom scale else will return NO
 */
- (BOOL) zoomOut;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - setMapZoomLevel:
//
/*!
 * The map will be zoomed by the given value.
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
// - setMapDrawMultiPointsForPOIs:showSwitchFloors:showEntrancesExits:
//
/*!
 * The map will draw dot for locations.
 * The method will number supported locations by Index, you can custom Marker color on map
 * by Implementing the IDDualMapViewControllerDelegate methods:
 * @see -mapColorForMultiPointLocation
 * @see -mapColorForMultiPointIndexText
 * @see -mapColorForMultiPoinSwitchFloorLocation:
 * @see -mapColorForMultiPoinEntranceExitLocation;
 * @warning The lcoations Array Count MUST be gratter than 1 object.
 * @param aPois array of locations to draw on map.
 * @param switchFloors show switch floor location if needed.
 * @param entrancesExits show entrance or exit location if needed.
 */

- (void)setMapDrawMultiPointsForPOIs:(NSArray<IDPoi *> *)aPois
                      visitedPoiList:(NSArray<IDPoi*> *)aVisitedPois
                    showSwitchFloors:(BOOL)switchFloors
                  showEntrancesExits:(BOOL)entrancesExits;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - setMapRemoveMultiPoints
//
/*!
 * set the map remove all dash lines
 * \code  [self.mapViewController setMapRemoveMultiPoints];
 */

-(void)setMapRemoveMultiPoints;


@end

#endif /* IDMapViewProtocol_h */
