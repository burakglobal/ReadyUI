//
//  FloorModel.m
//  Spreo
//
//  Created by Yury Tulup on 20.03.17.
//  Copyright © 2017 Spreo LLC. All rights reserved.
//

#import "FloorModel.h"

@implementation FloorModel

+ (FloorModel*)initWithFloorName:(NSString*)name floorIndex:(NSInteger)index {
    FloorModel *model = [[FloorModel alloc] init];
    model.name = name;
    model.index = index;
    return model;
}

@end
