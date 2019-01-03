//
//  LocationBeaconsManager.h
//  IOSSpreoSDKDual
//
//  Created by Yury Tulup on 24.08.17.
//  Copyright © 2017 Spreo LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LocationBeacon.h"

@interface LocationBeaconsManager : NSObject

+(instancetype)sharedManager;
- (LocationBeacon*)getLocationBeaconForLocation:(IDLocation*)location devices:(NSArray*)devices;

@end
