//
//  UIView+FNSetFrame.h
//  Financial
//
//  Created by Admin Account on 9/4/15.
//  Copyright (c) 2015 Igor Nikolaev. All rights reserved.
//

#import <UIKit/UIKit.h>

#define kSetDefaultValue -11111.f

@interface UIView (FNSetFrame)

- (void)setFrameWidth:(CGFloat)width height:(CGFloat)height x:(CGFloat)x y:(CGFloat)y;

- (void)setHorizontalCenterAlignInView:(UIView*)parentView;
- (void)setVerticalCenterAlignInView:(UIView*)parentView;
- (void)setCenterAlignInView:(UIView*)parentView;

@end
