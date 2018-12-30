//
//  CustomCalloutView.m
//  Spreo
//
//  Created by Yury Tulup on 10.04.17.
//  Copyright © 2017 Spreo LLC. All rights reserved.
//

#import "CustomCalloutView.h"

@implementation CustomCalloutView

- (void)awakeFromNib {
    [super awakeFromNib];
    self.backgroundColor = [UIColor clearColor];
    containerTitleView.layer.borderWidth = 2.5f;
    containerTitleView.layer.borderColor = [UIColor blackColor].CGColor;
    containerTitleView.layer.cornerRadius = containerTitleView.frame.size.height/3;
}

- (void)setCalloutTitle:(NSString *)title withNavIcon:(BOOL)activeNavIcon {
    calloutTitleLable.text = title;
    CGRect rect = [title boundingRectWithSize:CGSizeMake(20, MAXFLOAT)
                                           options:NSStringDrawingUsesDeviceMetrics
                                        attributes:@{NSFontAttributeName : calloutTitleLable.font}
                                           context:nil];
    if (!activeNavIcon) {
        [navIcon removeFromSuperview];
    }
    
    CGFloat calloutWidth = rect.size.width + rect.size.width / 2 + 12 + (activeNavIcon ? 30 : 0);
    CGFloat maxWidth = [[UIScreen mainScreen] bounds].size.width - 8;
    
    if (calloutWidth > maxWidth) {
        calloutWidth = maxWidth;
    }
    
    self.frame = CGRectMake(self.frame.origin.x, self.frame.origin.y, calloutWidth, self.frame.size.height);
}

@end
