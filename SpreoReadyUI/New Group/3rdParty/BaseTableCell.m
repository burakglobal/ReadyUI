//
//  BaseTableCell.m
//  Spreo
//
//  Created by Yury Tulup on 1/23/17.
//  Copyright © 2017 Spreo LLC. All rights reserved.
//

#import "BaseTableCell.h"

#define kBottomSeparatorTag 11
#define kTopSeparatorTag 12

@implementation BaseTableCell

- (void)awakeFromNib {
    [super awakeFromNib];
    // Initialization code
}

- (void)setSelected:(BOOL)selected animated:(BOOL)animated {
    [super setSelected:selected animated:animated];

    // Configure the view for the selected state
}

+ (UINib*)cellNib {
    return [UINib nibWithNibName:NSStringFromClass([self class]) bundle:[NSBundle mainBundle]];
}

+ (CGFloat)cellHeight {
    return 44.f;
}

+ (NSString *)cellIdentifier {
    return nil;
}

#pragma mark - Separators

- (void)addBottomSeparator:(CGFloat)leftPadding rightPadding:(CGFloat)rightPadding height:(CGFloat)height color:(UIColor*)color {
    [self removeSeparatorByTag:kBottomSeparatorTag];
    CGRect separatorFrame = CGRectZero;
    separatorFrame = CGRectMake(leftPadding, self.contentView.frame.size.height - height, self.contentView.frame.size.width - leftPadding - rightPadding, height);
    [self createSeparatorWithFrame:separatorFrame tag:kBottomSeparatorTag color:color];
}

- (void)addTopSeparator:(CGFloat)leftPadding height:(CGFloat)height color:(UIColor*)color {
    [self removeSeparatorByTag:kTopSeparatorTag];
    CGRect separatorFrame = CGRectZero;
    separatorFrame = CGRectMake(leftPadding, 0, self.contentView.frame.size.width - leftPadding, height);
    [self createSeparatorWithFrame:separatorFrame tag:kBottomSeparatorTag color:color];
}

- (void)createSeparatorWithFrame:(CGRect)frame tag:(NSInteger)tag color:(UIColor*)color {
    UIView *separatorView = [[UIView alloc]initWithFrame:frame];
    separatorView.backgroundColor = color;
    separatorView.tag = tag;
    [self.contentView addSubview:separatorView];
}

- (void)removeSeparatorByTag:(NSInteger)tag {
    for (UIView *subView in self.contentView.subviews) {
        if (subView.tag == tag) {
            [subView removeFromSuperview];
        }
    }
}

- (void)removeSeparators {
    UIView *topSeparator = [self.contentView viewWithTag:kTopSeparatorTag];
    UIView *bottomSeparator = [self.contentView viewWithTag:kBottomSeparatorTag];
    [topSeparator removeFromSuperview];
    [bottomSeparator removeFromSuperview];
}

@end
