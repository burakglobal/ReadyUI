//
//  IDConvertedLocation.h
//  IOSSpreoSDK
//
//  Created by Hasan Sa on 8/18/15.
//  Copyright (c) 2016 Spreo LLC. All rights reserved.
//

#import <CoreLocation/CoreLocation.h>

////////////////////////////////////////////////////////////////////////////////////////////
//
// IDConvertedLocation
/*!
 * The Indoor Kit Converted Location Class.
 */

@interface IDConvertedLocation : NSObject <NSCopying>

/*!
 * @brief The Location Campus identifier.
 */
@property (nonatomic, strong) NSString *campusId;

/*!
 * @brief The Location Facility identifier.
 */
@property (nonatomic, strong) NSString *facilityId;

/*!
 * @brief The Location Coordinates.
 * local metric X coordinate, or longitude.
 */
@property (nonatomic) double XOrLongitude;

/*!
 * @brief The Location Coordinates.
 * local metric Y coordinate, or latitude.
 */
@property (nonatomic) double  YOrLatitude;

/*!
 * @brief The Location Coordinates.
 *  latitude, longitude.
 */
@property (nonatomic, readonly) CLLocationCoordinate2D  position;

/*!
 * @brief The Location Floor identifier Id.
 */
@property (nonatomic) NSString* floorId;

/*!
 * @brief The Location Floor identifier Id.
 */
@property (nonatomic) CGFloat attitude;


/*!
 *  IDConvertedLocation designated Intitializer
 *
 *  @param aCampusId the location campus identifier NSString
 *  @param aFacilityId the location facility identifier NSString
 *  @param coordinate the location outdoor position CLLocationCoordinate2D
 *  @param floorId the location floor identifier NSInteger
 *  @param attitude the location attitude value CGFloat
 *
 *  @return IDConvertedLocation instance
 */
- (instancetype)initWithCampusId:(NSString*)aCampusId
                      facilityId:(NSString*)aFacilityId
                      coordinate:(CLLocationCoordinate2D)coordinate
                           floorId:(NSInteger)floorId
                          attitude:(CGFloat)attitude NS_DESIGNATED_INITIALIZER;

@end
