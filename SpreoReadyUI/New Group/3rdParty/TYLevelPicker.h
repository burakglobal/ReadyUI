//
//  TYLevelPicker.h
//  Spreo
//
//  Created by Yury Tulup on 3/16/17.
//  Copyright © 2017 Spreo LLC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <IndoorKit/IndoorKit.h>
#import <IndoorKit/IDDualMapViewController.h>

@class TYLevelPicker;
@protocol TYLevelPickerDelegate <NSObject>

- (void)levelPicker:(TYLevelPicker*)picker didSelectFloor:(NSInteger)floorId;

@end

@interface TYLevelPicker : UIView <UITableViewDelegate, UITableViewDataSource> {
    IDDualMapViewController *currentMapVC;
    UIView *currentParentView;
    
    UIView *containerView;
    UITableView *contentTableView;
    
    NSMutableArray *allFloorsArray;
    NSMutableArray *currentFloorsArray;

    BOOL isOpen;
    
    BOOL isNavigation;
    NSInteger _currentFloorId;
    NSInteger _startFloorId;
    NSInteger _destinationFloorId;
    
    UIImageView *triangleUp;
    UIImageView *triangleDown;
}

+ (TYLevelPicker*)createLevelPickerView;

@property (nonatomic, weak) id<TYLevelPickerDelegate> delegate;

- (void)addToView:(UIView*)parentView;
- (void)setUpPickerViewForMapVC:(IDDualMapViewController*)mapVC;

- (void)updateWithFloorId:(NSInteger)floorId;
- (void)updateViewForNavigationToFloor:(NSInteger)destinationFloorId fromFloor:(NSInteger)startFloorId;
- (void)updateView;
- (void)stopNavigation;

@end
