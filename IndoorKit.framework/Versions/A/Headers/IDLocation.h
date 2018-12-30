//
//  IDLocation.h
//  IndoorKit
//
//  Copyright (c) 2016 Spreo LLC. All rights reserved.
//

#import <CoreLocation/CoreLocation.h>

////////////////////////////////////////////////////////////////////////////////////////////
//
// IDLocation
/*! 
 * The Indoor Kit General Location Class.
 */

@interface IDLocation : NSObject <NSCoding, NSCopying>


/*!
 * @brief The Location Campus identifier.
 */
@property (nonatomic, strong) NSString *campusId;


/*!
 * @brief The Location Facility identifier.
 */
@property (nonatomic, strong) NSString *facilityId;


/*!
 * @brief The Location Floor identifier Number.
 */
@property (nonatomic) NSInteger floorId;


/*!
 * @brief The Location inCoordinate Point. The indoor Position
 */
@property (nonatomic) CGPoint inCoordinate;

/*!
 * @brief The Location rawCoordinate Point. The indoor raw Position 
 */
@property (nonatomic) CGPoint rawCoordinate;


/*!
 * @brief The Location outCoordinate Coordinates. The outdoor Position
 */
@property (nonatomic) CLLocationCoordinate2D outCoordinate;


/*!
 * @brief The Location isExternal BOOL.in cas a POI location has an outdoor navigation type "external"
 */
@property (nonatomic) BOOL isExternal;


/*!
 * @return True in case has no valid value for facilityId but has a valid value for campusId
 * and isExternal is False, otherwise returns False.
 */
@property (nonatomic, getter=isIndoor, readonly) BOOL indoor;


/*!
 * @return True in case the inCoordinate and outCoordinate are not equal to {0, 0}. otherwise False.
 */
@property (nonatomic, getter=isValid, readonly) BOOL valid;


/*!
 *  IDLocation designated Intitializer
 *
 *  @param aCampusId the location campus identifier NSString
 *  @param aFacilityId the location facility identifier NSString
 *  @param outCoordinate the location outdoor position CLLocationCoordinate2D
 *  @param inCoordinate the location indoor position CGPoint
 *  @param floorId the location floor identifier NSInteger
 *
 *  @return IDLocation instance
 */
- (instancetype)initWithCampusId:(NSString *)aCampusId
                      facilityId:(NSString *)aFacilityId
                   outCoordinate:(CLLocationCoordinate2D)outCoordinate
                    inCoordinate:(CGPoint)inCoordinate
                      andFloorId:(NSInteger)floorId NS_DESIGNATED_INITIALIZER;

@end

////////////////////////////////////////////////////////////////////////////////////////////
//
// IDUserLocation
/*! 
 * The Indoor Kit User Location Class.
 */

@interface IDUserLocation : IDLocation


/*!
 * @brief A Segment identifier.
 */
@property (nonatomic) NSInteger segmentId;


/*!
 * @brief A Attitude. The oreinteion angle
 */
@property (nonatomic) CGFloat attitude;


/*!
 *  IDUserLocation designated Intitializer
 *
 *  @param aCampusId the location campus identifier NSString
 *  @param aFacilityId the location facility identifier NSString
 *  @param outCoordinate the location outdoor position CLLocationCoordinate2D
 *  @param inCoordinate the location indoor position CGPoint
 *  @param floorId the location floor identifier NSInteger
 *  @param segmentId the location segmentId identifier NSInteger
 *  @param attitude the location attitude value CGFloat
 *
 *  @return IDUserLocation instance
 */
- (instancetype)initWithCampusId:(NSString *)aCampusId
                      facilityId:(NSString *)aFacilityId
                   outCoordinate:(CLLocationCoordinate2D)outCoordinate
                    inCoordinate:(CGPoint)inCoordinate
                         floorId:(NSInteger)floorId
                       segmentId:(NSInteger)segmentId
                     andAttitude:(CGFloat)attitude NS_DESIGNATED_INITIALIZER;

@end