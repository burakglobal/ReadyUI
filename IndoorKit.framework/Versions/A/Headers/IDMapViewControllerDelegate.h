//
//  IDMapViewControllerDelegate.h
//  IndoorKit
//
//  Copyright (c) 2016 Spreo LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <IndoorKit/IDMapType.h>

@class IDPoi;
@class IDUser;

////////////////////////////////////////////////////////////////////////////////////////////
// IDMapViewControllerDelegate
//
/*!
 * The IDMapViewControllerDelegate protocol provides API methods to custom The Indoor Kit Map views.
 * And provides all map situations.
 */

@protocol IDMapViewControllerDelegate <NSObject>

@optional

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - mapViewForCampusWithCampusID:
//
/*!
 show custom campus annotation view.
 @param  aCampusId campus ideintifier
 @return Returns view UIView
 */
- (UIView *)mapViewForCampusWithCampusID:(NSString *)aCampusId;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - mapImageForCampusGraphicsWithCampusID:
//
/*!
 show custom campus overlay image
 @param aCampusId campus ideintifier
 @return Returns image UIImage
 */
- (UIImage *)mapImageForCampusGraphicsWithCampusID:(NSString *)aCampusId;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - mapViewForFacilityWithID:atCampusWithId:
//
/*!
 show custom facility annotation view.
 @param  aFacilityId facility ideintifier
 @param  aCampusId campus ideintifier
 @return Returns view UIView
 */
- (UIView *)mapViewForFacilityWithID:(NSString *)aFacilityId atCampusWithId:(NSString *)aCampusId;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - mapViewForUser
//
/*!
 show custom View for user.
 @return Returns view UIView
 */
- (UIView *)mapViewForUser;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - mapViewForPoi:
//
/*!
 show custom view for Poi annotation on map
 @param aPoi IDPoi
 @return Returns view UIView
 */
- (UIView *)mapViewForPoi:(IDPoi *)aPoi;



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - mapViewForParkingAnnotaion
//
/*!
 show custom view for parking annotation on map
 @return Returns view UIView
 */
- (UIView *)mapViewForParkingAnnotaion;


////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - mapArrowImageForRoute:
//
// Description:
/*!
 * set The method returns arrow image to draw on the navigation route view.
 * show custom view for route view on map add arrow image,
 * to recognize navigation directions.
 @return Returns arrow UIImage
 */
- (UIImage *)mapArrowImageForRoute;


////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - mapColorForRoute:
//
/*!
 * The method returns UIColor for the route path
 * show custom color for route view on map
 * @return Returns color UIColor
 */
- (UIColor *)mapColorForRoute;



////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - mapColorForTripOverviewRoute:
//
/*!
 * The method returns UIColor for trip overview route view.
 * to show custom color for route overview.
 * @return Returns UIColor
 */
- (UIColor *)mapColorForTripOverviewRoute;



////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - mapColorForTripOverviewCircle:
//
/*!
 * The method returns UIColor for trip circle Index titled view.
 * to custom circle background color.
 * @return Returns UIColor
 */

- (UIColor *)mapColorForTripOverviewCircle;



////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - mapColorForTripOverviewArrivedCircle:
//
/*!
 * The method returns UIColor for arrived trip overview circle .
 * to custom circle background color.
 * @return Returns UIColor
 */
- (UIColor *)mapColorForTripOverviewArrivedCircle;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - mapDidChangeFocusLocationWithID:
//
/*!
 when the map did change region or focus for campus or facility
 @param aLocationId - for campus the aLocationId format will be ("campus.%@", aCampusId)
 - for facility the  aLocationId format will be ("facility.%@", aFacility)
 */
- (void)mapDidChangeFocusLocationWithID:(NSString *)aLocationId;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - mapDidSelectPOI:
//
/*!
 when a map annotation view did selected
 @param aPoi IDPoi
 */
- (void)mapDidSelectPOI:(IDPoi *)aPoi;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - mapDidTapCalloutOfPOI:
//
/*!
 when a map annotation callout view did tapped
 @param aPoi IDPoi
 */
- (void)mapDidTapCalloutOfPOI:(IDPoi *)aPoi;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - mapDidTapMyLocationButton
//
/*!
 when a map my location button view did tapped
 */
- (void)mapDidTapMyLocationButton;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - mapDidSelectLabelView:withInfo:
//
/*!
 when a map Label view did selected
 @param aLabelView inherits from :UILabel you can change textColor or BackgroundColor
 @param aLabelInfo NSDictionary
 {
 bottom = 910;
 description = "CALIFORNIA PIZZA KITCHEN";
 floor = 0;
 left = 1151;
 "place_id" = E122;
 right = 1209;
 top = 877;
 }
 */
- (void)mapDidSelectLabelView:(UILabel *)aLabelView withInfo:(NSDictionary *)aLabelInfo;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - mapDidSelectedUserAnnotaionView:
//
/*!
 when a map annotation view did selected
 @param anAnnotationView your custom view or UIImageView in case you did not implement mapViewForUser method.
 @see mapViewForUser
 */
- (void)mapDidSelectedUserAnnotaionView:(UIView *)anAnnotationView;



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - mapDidSelectedParkingAnnotaionView:
//
/*!
 when a map annotation view did selected
 @param anAnnotationView your custom view or UIImageView in case you did not implement
 mapViewForParkingAnnotaion method.@see mapViewForParkingAnnotaion
 */
- (void)mapDidSelectedParkingAnnotaionView:(UIView *)anAnnotationView ;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - mapWillChangeFloor:
//
/*!
 when a indoor map will change floor map indecation
 @param aFloorId the floor map index
 */
- (void)mapWillChangeFloor:(NSInteger)aFloorId;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - mapWillChangeFloor:
//
/*!
 when a indoor map did change floor map indecation
 @param aFloorId the floor map index
 */
- (void)mapDidChangeFloor:(NSInteger)aFloorId;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - mapWillSwapMapToMap:
//
/*!
 when the map will swap maps to either outdoor mapview or indoor mapview
 @param aMapId IDMapViewId enum
 */
- (void)mapWillSwapMapToMap:(IDMapViewId)aMapId;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - mapDidSwapMapToMap:
//
/*!
 when the map did swap maps to either outdoor mapview or indoor mapview
 @param aMapId IDMapViewId enum
 */
- (void)mapDidSwapMapToMap:(IDMapViewId)aMapId;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - mapDidChangeZoomLevel:
//
/*!
 When the indoor mapView did zoomed to zoom level, available for the indoor map only.
 @param aZoomLevel float value of current zoomlevel
 */
- (void)mapDidChangeZoomLevel:(CGFloat)aZoomLevel;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - mapWillMove: √
//
/*!
 */
- (void)mapWillMove;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - mapFollowUser:
//
/*!
 when the map followuser change
 @param mode of user follow
 */
- (void)mapFollowUser:(BOOL)mode;


- (UIView *)mapViewForLocationSharingUser:(IDUser*)aUser;
- (void)mapDidSelectLocationSharingUser:(IDUser *)aUser;

@end
