//
//  CustomCalloutView.h
//  Spreo
//
//  Created by Yury Tulup on 10.04.17.
//  Copyright © 2017 Spreo LLC. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface CustomCalloutView : UIView {
    IBOutlet UILabel *calloutTitleLable;
    IBOutlet UIView *containerTitleView;
    IBOutlet UIImageView *navIcon;
}

- (void)setCalloutTitle:(NSString *)title withNavIcon:(BOOL)activeNavIcon;

@end
