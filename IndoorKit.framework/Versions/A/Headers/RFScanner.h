//
//  RFScanner.h
//  IOSSpreoSDK
//
//  Created by Reuven M on 11/5/13.
//  Copyright (c) 2015 Spreo LLC. All rights reserved
//

#import <Foundation/Foundation.h>
#import "IDNavigation.h"

@protocol RFScannerDelegate <NSObject>

- (void)devicesInRange:(NSArray *)devices;
- (void)detectionStatusChanged:(IDLocationDetectionStatus)status;

@end

@interface RFScanner : NSObject

+ (instancetype)sharedScanner;

- (void)registerWithDelegate:(id<RFScannerDelegate>)aDelegate;
- (BOOL)canScan;
- (void)startScanRF;
- (void)stopScanRF;
- (BOOL)isScaning;

- (void)setMinDevicesNumberForDetection:(NSInteger)devices;

- (void)startSimulateBLEDevices:(NSArray*)devices;
- (void)stopSimulation;
-(void)setLowPowerMode:(BOOL)lowPowerMode;
@end
