//
//  NDKLocationDetector.h
//  IOSSpreoSDK
//
//  Created by Hasan Sa on 6/15/15.
//  Copyright (c) 2016 Spreo LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ILocationFinder.h"

@interface NDKLocationDetector : NSObject <ILocationFinder>

@property (nonatomic, assign) ILocationFinderDriverMode finderDrive;
@property (nonatomic, strong) IDUserLocation* location;

@end
