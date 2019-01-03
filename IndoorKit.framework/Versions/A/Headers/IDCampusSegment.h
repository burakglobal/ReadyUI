//
//  IDCampusSegment.h
//  IOSSpreoSDK
//
//  Created by Reuven M on 5/12/14.
//  Copyright (c) 2015 Spreo LLC. All rights reserved
//

#import <UIKit/UIKit.h>
#import <MapKit/MapKit.h>
#import "IDSegment.h"

@interface IDCampusSegment : IDSegment

@property (nonatomic, readonly) MKPolyline *polyline;
@property (nonatomic, readonly) CLLocationCoordinate2D start;
@property (nonatomic, readonly) CLLocationCoordinate2D end;

- (instancetype)initWithStartCoordinate:(CLLocationCoordinate2D)start endCoordinate:(CLLocationCoordinate2D)end andId:(NSInteger)identifier;
- (instancetype)initWithDictionary:(NSDictionary *)aSegment;
//
- (void)updatePolylineWithNewCoordinate:(CLLocationCoordinate2D)newCoordinate;

@end
