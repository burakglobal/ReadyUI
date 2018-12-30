//
//  UIView+FNSetFrame.m
//  Financial
//
//  Created by Admin Account on 9/4/15.
//  Copyright (c) 2015 Igor Nikolaev. All rights reserved.
//

#import "UIView+FNSetFrame.h"

@implementation UIView (FNSetFrame)

- (void)setFrameWidth:(CGFloat)width height:(CGFloat)height x:(CGFloat)x y:(CGFloat)y {
    CGRect selfFrame = self.frame;
    if (width > kSetDefaultValue) {
        selfFrame.size.width = width;
    }
    if (height > kSetDefaultValue) {
        selfFrame.size.height = height;
    }
    if (x > kSetDefaultValue) {
        selfFrame.origin.x = x;
    }
    if (y > kSetDefaultValue) {
        selfFrame.origin.y = y;
    }
    self.frame = selfFrame;
}

- (void)setHorizontalCenterAlignInView:(UIView*)parentView {
    [self setFrameWidth:self.frame.size.width height:self.frame.size.height x:(parentView.frame.size.width/2 - self.frame.size.width/2) y:self.frame.origin.y];
}

- (void)setVerticalCenterAlignInView:(UIView*)parentView {
    [self setFrameWidth:self.frame.size.width height:self.frame.size.height x:self.frame.origin.x y:(parentView.frame.size.height/2 - self.frame.size.height/2)];
}

- (void)setCenterAlignInView:(UIView*)parentView {
    [self setHorizontalCenterAlignInView:parentView];
    [self setVerticalCenterAlignInView:parentView];
}

@end
