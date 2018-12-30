//
//  IDPoi+Friends.h
//  IndoorKit
//
//  Copyright (c) 2018 Spreo LLC. All rights reserved.
//

#import "IDPoi.h"

@class IDPoi;
@class IDLocation;

@interface IDPoi (Friends)

+ (IDPoi *)friendPoiWithId:(NSString *)friendId
                      name:(NSString *)friendName
            imageURLString:(NSString *)imageURLString
                  location:(IDLocation *)friendLocation;

@end
