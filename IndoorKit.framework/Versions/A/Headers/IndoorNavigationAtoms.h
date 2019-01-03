//
//  IndoorNavigationAtoms.h
//  IOSSpreoSDK
//
//  Created by Adi Avram on 11/4/13.
//  Copyright (c) 2015 Spreo LLC. All rights reserved
//

#ifndef IndoorNavigationAtoms_h
#define IndoorNavigationAtoms_h

#import <CoreLocation/CoreLocation.h>
@class BlipBean;

typedef enum {
    kNavigationSwitchAll              = 0x00,
    kNavigationSwitchStaircase        = 0x01,
    kNavigationSwitchEscalator        = 0x02,
    kNavigationSwitchElevator         = 0x04,
    kNavigationSwitchLargeElevator    = 0x08,
    kNavigationSwitchExpress          = 0x10  // free fall
} IndoorNavigationSwitchType;


@interface BlipRF : NSObject

@property (nonatomic, strong) NSString* bssid;
@property (nonatomic, assign) int level;
@property (nonatomic, assign) BOOL unknown;

+ (instancetype)blipWithID:(NSString *)anId andLevel:(int)aLevel;
+ (instancetype)blipWithDictionary:(NSDictionary *)aDict;
+ (instancetype)blipWithBean:(BlipBean*)aBlipBean;
+ (instancetype)blipWithCLBeacon:(CLBeacon*)aBeacon;

@end

#endif
