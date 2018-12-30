//
//  FloorModel.h
//  Spreo
//
//  Created by Yury Tulup on 20.03.17.
//  Copyright © 2017 Spreo LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface FloorModel : NSObject

+ (FloorModel*)initWithFloorName:(NSString*)name floorIndex:(NSInteger)index;

@property (nonatomic, strong) NSString *name;
@property (nonatomic, assign) NSInteger index;
@property (nonatomic, assign) BOOL isStart;
@property (nonatomic, assign) BOOL isDestination;
@property (nonatomic, assign) BOOL isCurrent;

@end
