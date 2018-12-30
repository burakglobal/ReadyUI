//
//  IDDualMapViewControllerDelegate.h
//  IndoorKit
//
//  Copyright (c) 2016 Spreo LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <IndoorKit/IDMapType.h>

@class IDPoi;
@class GMSMarker;
@class IDLabel;
@class IDParking;

////////////////////////////////////////////////////////////////////////////////////////////
// IDMapViewControllerDelegate
//
/*!
 * The IDDualMapViewControllerDelegate protocol provides API methods to custom The Indoor Kit Map views.
 * And provides all map situations.
 */

@protocol IDDualMapViewControllerDelegate <NSObject>

@optional


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - mapViewForUser √
//
/*!
 * show custom icon image for user.
 * @return Returns image UIImage, or nil for default
 */
- (UIImage *)mapIconForUserAnnotaion;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - mapIconForPoi: √
//
/*!
 * show custom icon image for Poi annotation on map
 * @param aPoi IDPoi
 * @return Returns image UIImage, or nil for default
 */
- (UIImage*)mapIconForPoi:(IDPoi *)aPoi;



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - mapViewForCalloutOfPoi: √
/**
 * Called when a marker is about to become selected, and provides an optional
 * custom info window to use for that marker if this method returns a UIView.
 * If you change this view after this method is called, those changes will not
 * necessarily be reflected in the rendered version.
 *
 * The returned UIView must not have bounds greater than 500 points on either
 * dimension.  As there is only one info window shown at any time, the returned
 * view may be reused between other info windows.
 *
 * Removing the marker from the map or changing the map's selected marker during
 * this call results in undefined behavior.
 *
 * @return The custom info window for the specified marker, or nil for default
 */

- (UIView *)mapViewForCalloutOfPoi:(IDPoi *)aPoi;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - mapViewForCalloutOfParkingAnnotation: √
/**
 * Called when a marker is about to become selected, and provides an optional
 * custom info window to use for that marker if this method returns a UIView.
 * If you change this view after this method is called, those changes will not
 * necessarily be reflected in the rendered version.
 *
 * The returned UIView must not have bounds greater than 500 points on either
 * dimension.  As there is only one info window shown at any time, the returned
 * view may be reused between other info windows.
 *
 * Removing the marker from the map or changing the map's selected marker during
 * this call results in undefined behavior.
 *
 * @return The custom info window for the specified marker, or nil for default
 */

- (UIView *)mapViewForCalloutOfParking:(IDParking *)parkingMarker;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - mapIconForParkingAnnotaion √
//
/*!
 * show custom view for parking annotation on map
 * @return Returns view UIView, or nil for default
 */
- (UIImage *)mapIconForParkingAnnotaion;


////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - mapColorForRoute: √
//
/*!
 * The method returns UIColor for the route path
 * show custom color for route view on map
 * @return Returns color UIColor, or nil for default
 */
- (UIColor *)mapColorForRoute;


////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - labelViewForFloorTitle: √
//
/*!
 * The method returns UILabel for the indoor picker view
 * show custom label view for the indoor picker view 
 * @param aFloorTitle picker text value
 * @param selected in order to custom the selected floor title value
 * @return Returns label UILabel, or nil for default
 */
- (UILabel*)labelViewForFloorTitle:(NSString *)aFloorTitle isSelected:(BOOL)selected;



////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - mapColorForMultiPointLocation
//
/*!
 * The method returns UIColor for trip circle Index titled view.
 * to custom circle background color.
 * @return Returns UIColor
 */

- (UIColor *)mapColorForMultiPointLocation;


////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - mapColorForMultiPointVisitedLocation
//
/*!
 * The method returns UIColor for trip circle Index titled view.
 * to custom circle background color on Visited pois.
 * @return Returns UIColor
 */

- (UIColor *)mapColorForMultiPointVisitedLocation;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - mapColorForMultiPointLocation
//
/*!
 * The method returns UIColor for trip circle Index titled view.
 * to custom circle text & border color.
 * @return Returns UIColor
 */

- (UIColor *)mapColorForMultiPointIndexText;


////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - mapIconForMultiPoinSwitchFloorLocation
//
/*!
 * The method returns UIImage for switch floor view.
 * to custom circle icon.
 * @return Returns UIColor
 */

- (UIImage *)mapIconForMultiPoinSwitchFloorLocation;



////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - mapIconForMultiPoinEntranceExitLocation
//
/*!
 * The method returns UIImage for entrance exit view.
 * to custom circle icon.
 * @return Returns UIColor
 */

- (UIImage *)mapIconForMultiPoinEntranceExitLocation;




/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - mapDidTapPOI: √
//
/*!
 * when a map annotation view did selected
 * @param aPoi IDPoi
 */
- (void)mapDidTapPOI:(IDPoi *)aPoi;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - mapDidTapAtCoordinate:: √
//
 /**
  * Called after a tap gesture at a particular coordinate, but only if a marker
  * was not tapped.
  * @param coordinate The location that was pressed.
  * @param facilityId if facility floor overlay tapped, nil if not.
  * @param floorId in case there is a valid floor id, nil if not.
 */
- (void)mapDidTapAtCoordinate:(CLLocationCoordinate2D)coordinate
                   facilityId:(NSString*)facilityId
                      floorId:(NSString*)floorId;



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - mapDidLongPressAtCoordinate:: √
//
/**
 * Called after a long-press gesture at a particular coordinate.
 *
 * @param coordinate The location that was pressed.
 * @param facilityId if facility floor overlay tapped, nil if not.
 * @param floorId in case there is a valid floor id, nil if not.
 */
- (void)mapDidLongPressAtCoordinate:(CLLocationCoordinate2D)coordinate
                      facilityId:(NSString*)facilityId
                         floorId:(NSString*)floorId;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - mapDidTapCalloutOfPOI: √
//
/*!
 * when a map annotation callout view did tapped
 * @param aPoi IDPoi
 */
- (void)mapDidTapCalloutOfPOI:(IDPoi *)aPoi;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - mapDidTapCalloutOfParking: √
//
/*!
 * when a map annotation callout view did tapped
 * @param parkingMarker GMSMarker
 */
- (void)mapDidTapCalloutOfParking:(IDParking *)parkingMarker;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - mapDidTapMyLocationButton √
//
/*!
 * when a map my location button view did tapped
 * this method will be called in case:
 @code self.mapVC.settings.myLocationButton = YES; @endcode
 default is false
 @see self.mapVC.settings object
 */
- (void)mapDidTapMyLocationButton;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - mapDidTapUserAnnotaionIcon: √
//
/*!
 * when a map annotation view did selected
 * @param anAnnotationView your custom view or UIImageView in case you did not implement mapViewForUser method.
 * @see mapViewForUser
 */
- (void)mapDidTapUserAnnotaionIcon:(UIImage *)anAnnotationView;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - mapDidTapParkingAnnotaionIcon: √
//
/*!
 * when a map annotation view did selected
 * @param anAnnotationView your custom view or UIImageView in case you did not implement
 * mapViewForParkingAnnotaion method.
 * @see mapViewForParkingAnnotaion
 */
- (void)mapDidTapParkingAnnotaionIcon:(UIImage *)anAnnotationView;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - mapDidTapLabelAnnotaionIcon:forLabel:
//
/*!
 when a map Label view did selected
 @param aLabel IDLabel Object
 aLabel.dictionary = {
     bottom = 910;
     description = "CALIFORNIA PIZZA KITCHEN";
     floor = 0;
     left = 1151;
     "place_id" = E122;
     right = 1209;
     top = 877;
 }
 */
- (void)mapDidTapLabel:(IDLabel*)aLabel;



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - mapDidChangedFocusToLocationWithID: √
//
/*!
 * This method will Be called when closest facility region contains the map center point - the location Id will be the 'facilityId'.
 * or when center point is out of all regions - the location Id will be 'nil';
 * @param aLocationId - for facility the  aLocationId format will be aFacilityId
 */
- (void)mapDidChangedFocusToLocationWithID:(NSString *)aLocationId;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - mapDidChangeFloorId:atFacilityId: √
//
/*!
 * when the map did change floor map indecation at facilityId
 * @param aFloorId the floor map index
 * @param aFacilityId the facility of the map index
 */
- (void)mapDidChangeFloorId:(NSInteger)aFloorId atFacilityId:(NSString*)aFacilityId;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - mapDidChangeZoomLevel: √
//
/*!
 * When the mapView did zoomed to zoom level.
 * @param aZoomLevel float value of current zoomlevel
 */
- (void)mapDidChangeZoomLevel:(CGFloat)aZoomLevel;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - mapWillMove: √
//
/*!
 */
- (void)mapWillMove;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - mapFollowUser: √
//
/*!
 * when the map followuser change
 * @param mode of user follow
 */
- (void)mapFollowUser:(BOOL)mode;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - mapTapMultiPoiIcon: √
//
/*!
 * when user tap the multi poi icon
 * @param poi the poi that was tapped
 */
- (void)mapTapMultiPoiIcon:(IDPoi*)poi;


@end
