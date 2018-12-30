//
//  IDRoute.h
//  IndoorKit
//
//  Copyright (c) 2016 Spreo LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

#ifndef NS_ENUM
@import Foundation;
#endif
typedef NS_OPTIONS(unsigned int, IDRouteType) {
    kIDIndoorRoute                  = 0x10,
    kIDIndoorMultiFloorRoute        = 0x30,
    kIDIndoorPointRoute             = 0x40,
    kIDOutdoorPointRoute            = 0xC0,
    kIDOutdoorRoute                 = 0x80,
    kIDOutdoorCombinedRoute         = 0x90
};

@class IDLocation;

@interface IDRoute : NSObject

@property (nonatomic, strong, readonly) IDLocation *origion;
@property (nonatomic, strong, readonly) IDLocation *destination;
@property (nonatomic, strong, readonly) NSArray *segments;
@property (nonatomic, strong) NSArray *instructions;
@property (nonatomic, assign, readonly) NSInteger identifier;
@property (nonatomic, assign, getter=getRouteType, readonly) IDRouteType routeType;
@property (nonatomic, assign, getter=isIndoorRoute, readonly) BOOL indoorRoute;
@property (nonatomic, assign, getter=isOutdoorRoute, readonly) BOOL outdoorRoute;

- (instancetype)initWithOrigion:(IDLocation *)anOrigion
                    destination:(IDLocation *)aDestination
                       segments:(NSArray *)aSegments
                   instructions:(NSArray *)anInstructions
                          andId:(NSInteger)anId NS_DESIGNATED_INITIALIZER;

- (id)simplifieyRouteInstructions;
- (void)removeDuplicateInstructions;

@end

@interface IDCombinedRoute : IDRoute

@property (nonatomic, strong, readonly) NSArray *routes;
@property (nonatomic) NSInteger currentRoute;

- (instancetype)initWithOrigion:(IDLocation *)anOrigion
                    destination:(IDLocation *)aDestination
                         routes:(NSArray *)routes
                          andId:(IDRouteType)anId NS_DESIGNATED_INITIALIZER;

- (BOOL)hasNext;
- (IDRoute *)getFirstRoute;
- (IDRoute *)getRouteWithIndex:(NSInteger)index;
- (IDRoute *)getRouteForFloorId:(NSInteger)floor;

@end
