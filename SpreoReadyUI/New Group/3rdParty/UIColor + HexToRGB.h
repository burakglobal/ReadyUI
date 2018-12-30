//
//  UIColor.h
//  Spreo
//
//  Created by Dmitry Pliushchai on 15/03/2017.
//  Copyright © 2017 Spreo LLC. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIColor(HexToRGB)

+ (UIColor *)colorWithHex:(UInt32)col;
+ (UIColor *)colorWithHexString:(NSString *)hexString;

@end
