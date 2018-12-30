//
//  IDLocationListener.h
//  IOSSpreoSDK
//
//  Copyright (c) 2016 Spreo LLC. All rights reserved.
//


////////////////////////////////////////////////////////////////////////////////////////////
//******************************************************************************************
// IDLocationListener
//
/*!
 * The IDLocationListener protocol provides feedback on the location updates, status and events.
 */

@protocol IDLocationListener <NSObject>

@optional
////////////////////////////////////////////////////////////////////////////////////////
// - locationDetectionStatusChanged:
/*!
 * This method is to be called when the location detection be changed
 * (i.e. Bloutooth mode, CoreLocation Authorization mode)
 * @param aStatus IDLocationDetectionStatus enum type
 */
- (void)locationDetectionStatusChanged:(IDLocationDetectionStatus)aStatus;


////////////////////////////////////////////////////////////////////////////////////////
// - updateUserLocationWithLocation:
/*!
 * This method is to be called when the user location be updated
 * @param aLocation IDUserLocation class
 */
- (void)updateUserLocationWithLocation:(IDUserLocation *)aLocation;


////////////////////////////////////////////////////////////////////////////////////////
// - regionEventChangedForCampusId:
/*!
 * This method is to be called when the user location changed for campusId
 * @param  aCampusId region status changed for campus
 * @param  anEventType IDRegionEventType the region event
 */
- (void)regionEventChangedForCampusId:(NSString*)aCampusId
                            withEvent:(IDRegionEventType)anEventType;


////////////////////////////////////////////////////////////////////////////////////////
// - updateUserLocationWithLocation:
/*!
 * This method is to be called when the user location changed for facilityId at campusId
 * @param  aCampusId region status changed for campus
 * @param  anEventType IDRegionEventType the region event
 */
- (void)regionEventChangedForFacilityWithID:(NSString*)aFacilityId
                                   campusId:(NSString*)aCampusId
                                  withEvent:(IDRegionEventType)anEventType;

@end
