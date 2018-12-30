//
//  BaseTableCell.h
//  Spreo
//
//  Created by Yury Tulup on 1/23/17.
//  Copyright © 2017 Spreo LLC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "Constants.h"

@interface BaseTableCell : UITableViewCell

+ (UINib*)cellNib;
+ (CGFloat)cellHeight;
+ (NSString *)cellIdentifier;

- (void)addBottomSeparator:(CGFloat)leftPadding rightPadding:(CGFloat)rightPadding height:(CGFloat)height color:(UIColor*)color;
- (void)addTopSeparator:(CGFloat)leftPadding height:(CGFloat)height color:(UIColor*)color;
- (void)removeSeparators;

@end
