//
//  UIViewController+NavigationButtons.h
//  Spreo
//
//  Created by Dmitry Pliushchai on 1/9/17.
//  Copyright © 2017 Spreo LLC. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIViewController (NavigationButtons)

- (void)createBackButton;
- (void)createCancelButton;
- (void)createStartButton:(BOOL)isActive;
- (void)createMenuButton;
- (void)createEditButton;

#pragma mark - Actions

- (void)backButtonTapped;
- (void)cancelButtonTapped;
- (void)startButtonTapped;
- (void)menuButtonTapped:(id)sender;
- (void)editButtonTapped;

@end
