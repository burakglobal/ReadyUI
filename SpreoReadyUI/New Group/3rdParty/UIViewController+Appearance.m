//
//  UIViewController+Appearance.m
//  Spreo
//
//  Created by Yury Tulup on 2/3/17.
//  Copyright © 2017 Spreo LLC. All rights reserved.
//

#import "UIViewController+Appearance.h"

@implementation UIViewController (Appearance)

- (void)createTitleLabelWithText:(NSString *)text {
//    UILabel *titleLabel = [[UILabel alloc] initWithFrame:CGRectMake(0, 0, 150, 44)];
//    titleLabel.text = text;
//    titleLabel.backgroundColor = [UIColor clearColor];
//    titleLabel.textColor = [UIColor whiteColor];
//    titleLabel.textAlignment = NSTextAlignmentCenter;
//    self.navigationItem.titleView = titleLabel;
    self.title = text;
}

@end
