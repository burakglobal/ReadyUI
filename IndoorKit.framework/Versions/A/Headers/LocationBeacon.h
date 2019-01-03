//
//  LocationBeacon.h
//  IOSSpreoSDKDual
//
//  Created by Yury Tulup on 24.08.17.
//  Copyright © 2017 Spreo LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IndoorNavigationAtoms.h"

@interface LocationBeacon : NSObject

@property (nonatomic, strong, readonly) NSString *bssid;
@property (nonatomic, assign, readonly) NSInteger enterLevel;
@property (nonatomic, assign, readonly) NSInteger exitLevel;
@property (nonatomic, assign, readonly) NSInteger currentLevel;
@property (nonatomic, assign, readonly) NSInteger counter;
@property (nonatomic, assign, readonly) CGFloat x;
@property (nonatomic, assign, readonly) CGFloat y;
@property (nonatomic, assign, readonly) NSInteger floor;
@property (nonatomic, assign, readonly) BOOL inState;

- (instancetype)initWithLocationBeacon:(NSDictionary *)beacon;

- (BOOL)isInState:(NSArray*)devices proximityCounterThresh:(NSInteger)counterThresh;

@end
