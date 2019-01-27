//
//  TYLevelPicker.m
//  Spreo
//
//  Created by Yury Tulup on 3/16/17.
//  Copyright © 2017 Spreo LLC. All rights reserved.
//

#import "TYLevelPicker.h"
#import "LevelPickerCell.h"
#import "UIView+FNSetFrame.h"
#import "Constants.h"
#import "FloorModel.h"

#define containerWidth 70

@implementation TYLevelPicker

+ (TYLevelPicker*)createLevelPickerView {
    TYLevelPicker *view = [[TYLevelPicker alloc] initWithFrame:CGRectZero];
    return view;
}

- (void)setUpPickerViewForMapVC:(IDDualMapViewController*)mapVC {
    currentMapVC = mapVC;
    _currentFloorId = currentMapVC.currentPresentedFloorID;
    self.backgroundColor = [UIColor clearColor];
    containerView = [[UIView alloc] initWithFrame:self.bounds];
    containerView.backgroundColor = [UIColor clearColor];
    
    triangleUp = [[UIImageView alloc] initWithImage:[UIImage imageNamed:@"triangle_up"]];
    [triangleUp setFrame:CGRectZero];
    [self addSubview:triangleUp];
    
    triangleDown = [[UIImageView alloc] initWithImage:[UIImage imageNamed:@"triangle_down"]];
    [triangleDown setFrame:CGRectZero];
    [self addSubview:triangleDown];
    
    [self addSubview:containerView];
    
    [self getFloorsPickerData];
    [self setContentTableView];
}

- (void)addToView:(UIView *)parentView {
    currentParentView = parentView;
    [self updateView];
    [self setFrameWidth:kSetDefaultValue height:kSetDefaultValue x:parentView.frame.size.width y:kSetDefaultValue];
    [parentView addSubview:self];
    CGFloat xCoord = currentParentView.frame.size.width - self.frame.size.width - 10.f;
    [UIView animateWithDuration:0.5
                          delay:0.1
                        options: UIViewAnimationOptionCurveEaseIn
                     animations:^ {
                         [self setFrameWidth:kSetDefaultValue height:kSetDefaultValue x:xCoord y:kSetDefaultValue];
     }
                     completion:^(BOOL finished){
     }];
}

- (void)setContentTableView {
    contentTableView = [[UITableView alloc] initWithFrame:containerView.bounds];
    contentTableView.delegate = self;
    contentTableView.dataSource = self;
    contentTableView.backgroundColor = [UIColor clearColor];
    contentTableView.separatorStyle = UITableViewCellSeparatorStyleNone;
    contentTableView.scrollEnabled = YES;
    [containerView addSubview:contentTableView];
    [contentTableView registerNib:[LevelPickerCell cellNib] forCellReuseIdentifier:[LevelPickerCell cellIdentifier]];
}

- (void)getFloorsPickerData {
    NSString *campusId = [[IDKit getCampusIDs] firstObject];
    NSString* facilityId  = [IDKit getMaxVenueIdFloorsCountAtCampusId:nil];
    NSDictionary* dict = [IDKit getInfoForFacilityWithID:facilityId atCmpusWithID:campusId];
    if (dict != nil) {
        allFloorsArray = [NSMutableArray new];
        NSArray *floorsTitles = dict[@"floors_titles"];
        NSArray *floorsIndexes = dict[@"floors_indexes"];
        for (int i = 0; i < floorsTitles.count; i++) {
            FloorModel *floorModel = [FloorModel initWithFloorName:floorsTitles[i] floorIndex:@([floorsIndexes[i] integerValue]).integerValue];
            [allFloorsArray addObject:floorModel];
        }
    }
    [self getCurrentFlorsDataArray];
}

#pragma mark - UITableViewDataSource

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
    return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return currentFloorsArray.count;
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
    return [LevelPickerCell cellHeight];
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    LevelPickerCell *cell = [tableView dequeueReusableCellWithIdentifier:[LevelPickerCell cellIdentifier]];
    cell.isFirstCell = indexPath.row == 0;
    NSInteger currentIndex = [self getRevertedIndex:indexPath];
    FloorModel *model = currentFloorsArray[currentIndex];
    [cell updateWithFloorModel:model];
    return cell;
}

#pragma mark - UITableViewDelegate

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    NSInteger floorId = ((FloorModel*)currentFloorsArray[[self getRevertedIndex:indexPath]]).index;
    if (isOpen) {
        if (_currentFloorId != floorId) {
            if ([_delegate respondsToSelector:@selector(levelPicker:didSelectFloor:)]) {
                [_delegate levelPicker:self didSelectFloor:floorId];
                [self updateWithFloorId:floorId];
            }
        }
        isOpen = NO;
    } else {
        isOpen = YES;
    }
    [self updateView];
}

#pragma mark - Helpers

- (NSInteger)getRevertedIndex:(NSIndexPath*)indexPath {
    return (currentFloorsArray.count - 1) - indexPath.row;
}

- (NSArray*)getCurrentFlorsDataArray {
    currentFloorsArray = [NSMutableArray new];
    [self updateAllModels];
    if (isOpen) {
        currentFloorsArray = allFloorsArray;
    } else {
        currentFloorsArray = [self getCurrentFloorsData].mutableCopy;
    }
    return currentFloorsArray;
}

- (NSArray*)getCurrentFloorsData {
    NSMutableArray *floorsArray = [NSMutableArray new];
    for (FloorModel *model in allFloorsArray) {
        if (isNavigation) {
            if (model.isStart || model.isDestination || model.isCurrent) {
                [floorsArray addObject:model];
            }
        } else {
            if (model.isCurrent) {
                [floorsArray addObject:model];
            }
        }
    }
    return floorsArray;
}

- (void)updateAllModels {
    for (FloorModel *model in allFloorsArray) {
        model.isStart = model.isDestination = NO;
        if (isNavigation) {
            model.isStart = model.index == _startFloorId;
            model.isDestination = model.index == _destinationFloorId;
        }
        model.isCurrent = model.index == _currentFloorId;
    }
}

#pragma mark - UI Helpers

- (void)updateView {
    [self getCurrentFlorsDataArray];
    if (currentFloorsArray.count < 6) {
        [containerView setFrameWidth:containerWidth height:[LevelPickerCell cellHeight]*currentFloorsArray.count x:0.f y:0.f];
    } else {
        [containerView setFrameWidth:containerWidth height:[LevelPickerCell cellHeight]*5 x:0.f y:0.f];
    }
    
    [self setFrameWidth:containerView.frame.size.width height:containerView.frame.size.height + 16.f x:0.f y:kSetDefaultValue];
    CGFloat yCoord = currentParentView.frame.size.height - self.frame.size.height - 130.f;
    CGFloat xCoord = currentParentView.frame.size.width - self.frame.size.width - 27.f;
    [self setFrameWidth:kSetDefaultValue height:kSetDefaultValue x:xCoord y:yCoord];
    
    [triangleUp setFrameWidth:14 height:8 x:kSetDefaultValue y:kSetDefaultValue];
    [triangleUp setHorizontalCenterAlignInView:self];
    [triangleUp setFrameWidth:kSetDefaultValue height:kSetDefaultValue x:triangleUp.frame.origin.x + 7.f y:kSetDefaultValue];
    
    [triangleDown setFrameWidth:14 height:8 x:kSetDefaultValue y:kSetDefaultValue];
    [triangleDown setHorizontalCenterAlignInView:self];
    [triangleDown setFrameWidth:kSetDefaultValue height:kSetDefaultValue x:triangleDown.frame.origin.x + 7.f y:self.frame.size.height - triangleDown.frame.size.height];
    
    [containerView setVerticalCenterAlignInView:self];
    [contentTableView setFrame:containerView.bounds];
    [contentTableView reloadData];
}

- (void)updateWithFloorId:(NSInteger)floorId {
    if (_currentFloorId != floorId) {
        _currentFloorId = floorId;
        [self updateView];
    }
}

#pragma mark - Navigation

- (void)updateViewForNavigationToFloor:(NSInteger)destinationFloorId fromFloor:(NSInteger)startFloorId {
    isNavigation = YES;
    _startFloorId = startFloorId;
    _destinationFloorId = destinationFloorId;
    [self updateView];
}

- (void)stopNavigation {
    isNavigation = NO;
    _startFloorId = 0;
    _destinationFloorId = 0;
    [self updateView];
}

@end
