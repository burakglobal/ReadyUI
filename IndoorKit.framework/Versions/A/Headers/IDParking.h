//
//  IDParking.h
//  IOSSpreoSDKDual
//
//  Created by Patrick Moscova on 7/12/16.
//  Copyright © 2016 Spreo LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

@class IDLocation;

@interface IDParking : NSObject  <NSCoding, NSCopying>

@property (nonatomic, strong) UIImage* parkingImage;
@property (nonatomic, strong) NSDictionary* additionalInfo;
@property (nonatomic, strong) NSString* parkingTitle;
@property (nonatomic, strong) IDLocation* parkingLocation;


@end
