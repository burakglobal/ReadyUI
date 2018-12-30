//
//  IDFriend.h
//  IndoorKit
//
//  Created by Spreo on 2/26/18.
//  Copyright © 2018 Spreo LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <GoogleMaps/GoogleMaps.h>

@class IDLocation;

@interface IDFriend : NSObject <NSCoding, NSCopying>

@property (nonatomic, readonly, copy) NSString *id;
@property (nonatomic, readonly, copy) UIImage *icon;
@property (nonatomic, strong, readonly) NSString *name;
@property (nonatomic) IDLocation *location;
@property (nonatomic) GMSMarker *marker; // Use Utility Class ID Gms Class

- (instancetype)initFriend:(NSString *)id
                        icon:(UIImage *)icon
                     name:(NSString *)name
                    location:(IDLocation *)aLocation;

@end

 

