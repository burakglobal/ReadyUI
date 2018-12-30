//
//  UIViewController+NavigationButtons.m
//  Spreo
//
//  Created by Dmitry Pliushchai on 1/9/17.
//  Copyright © 2017 Spreo LLC. All rights reserved.
//

#import "UIViewController+NavigationButtons.h"

@implementation UIViewController (NavigationButtons)

- (void)createBackButton {
    UIBarButtonItem *backButton =[[UIBarButtonItem alloc] initWithImage:[UIImage imageNamed:@"BackArrow_white"]
                                                                  style:UIBarButtonItemStylePlain
                                                                 target:self
                                                                 action:@selector(backButtonTapped)];
    self.navigationItem.leftBarButtonItem = backButton;
}

- (void)createCancelButton {
    UIButton *button = [UIButton buttonWithType:UIButtonTypeCustom];
    [button setTitle:@"Cancel" forState:UIControlStateNormal];
    [button setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
    [button addTarget:self action:@selector(cancelButtonTapped) forControlEvents:UIControlEventTouchUpInside];
    //button.titleLabel.font = kEdmondsansRegularFontWithSize(12);
    [button sizeToFit];
    self.navigationItem.leftBarButtonItem = [[UIBarButtonItem alloc] initWithCustomView:button];
}

- (void)createStartButton:(BOOL)isActive {
    UIButton *button = [UIButton buttonWithType:UIButtonTypeCustom];
    [button setTitle:@"Start" forState:UIControlStateNormal];
    [button setTitleColor:isActive ? [UIColor whiteColor] : [UIColor lightGrayColor] forState:UIControlStateNormal];
    [button addTarget:self action:@selector(startButtonTapped) forControlEvents:UIControlEventTouchUpInside];
    button.userInteractionEnabled = isActive;
    [button sizeToFit];
    self.navigationItem.rightBarButtonItem = [[UIBarButtonItem alloc] initWithCustomView:button];
}

- (void)createMenuButton {
    UIBarButtonItem *backButton =[[UIBarButtonItem alloc] initWithImage:[UIImage imageNamed:@"icon-menu"]
                                                                  style:UIBarButtonItemStylePlain
                                                                 target:self
                                                                 action:@selector(menuButtonTapped:)];
    self.navigationItem.leftBarButtonItem = backButton;
}

- (void)createEditButton{
    UIButton *button = [UIButton buttonWithType:UIButtonTypeCustom];
    [button setTitle:@"Edit" forState:UIControlStateNormal];
    [button setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
    [button addTarget:self action:@selector(editButtonTapped) forControlEvents:UIControlEventTouchUpInside];
    [button sizeToFit];
    self.navigationItem.rightBarButtonItem = [[UIBarButtonItem alloc] initWithCustomView:button];
}

#pragma mark - Actions

- (void)backButtonTapped {
    [self.navigationController popViewControllerAnimated:YES];
}

- (void)cancelButtonTapped {
    [self backButtonTapped];
}

- (void)startButtonTapped {
}

- (void)menuButtonTapped:(id)sender {
 }

- (void)editButtonTapped{
    
}

@end

