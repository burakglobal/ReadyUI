//
//  IDSegment.h
//  IOSSpreoSDK
//
//  Created by Reuven M on 5/12/14.
//  Copyright (c) 2015 Spreo LLC. All rights reserved
//

#import <Foundation/Foundation.h>

@interface IDSegment : NSObject

@property (nonatomic, readonly) NSInteger identifier;

- (instancetype)initWithId:(NSInteger)identifier;

@end
