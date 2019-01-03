//
//  LevelPickerCell.m
//  Spreo
//
//  Created by Yury Tulup on 3/17/17.
//  Copyright © 2017 Spreo LLC. All rights reserved.
//

#import "LevelPickerCell.h"

static NSString *const kLevelPickerCellIdentifier = @"LevelPickerCell";

@implementation LevelPickerCell

- (void)awakeFromNib {
    [super awakeFromNib];
    self.backgroundColor = [UIColor clearColor];
    leftSeparator.backgroundColor = [UIColor blackColor];
    rightSeparator.backgroundColor =  [UIColor blackColor];
}

+ (CGFloat)cellHeight {
    return 38.f;
}

+ (NSString *)cellIdentifier {
    return kLevelPickerCellIdentifier;
}

- (void)updateWithFloorModel:(FloorModel *)model {
    floorLabel.text = model.name;
    [self setSelectedStyle:model.isCurrent];
    navImageView.hidden = !model.isStart && !model.isDestination;
    if (navImageView.hidden == NO) {
        navImageView.image = [UIImage imageNamed:model.isDestination ? @"map_destination" : @"map_start_point"];
    }
}

- (void)setSelectedStyle:(BOOL)isSelected {
    containerView.backgroundColor = isSelected ? [UIColor whiteColor] : RGBCOLORWITHALPHA(0, 0, 0, 0.8);
    floorLabel.textColor = isSelected ?  [UIColor blackColor]: [UIColor whiteColor];
}

- (void)layoutSubviews {
    [super layoutSubviews];
    [self addBottomSeparator:15.f rightPadding:0.f height:2.f color: [UIColor blackColor]];
    if (_isFirstCell) {
        [self addTopSeparator:15.f height:2.f color: [UIColor blackColor]];
    }
}

@end
