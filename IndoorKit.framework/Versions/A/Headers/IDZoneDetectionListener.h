//
//  IDZoneDetectionListener.h
//  IOSSpreoSDKDual
//
//  Created by Hasan Sa on 3/14/16.
//  Copyright © 2016 Spreo LLC. All rights reserved.
//

#ifndef IDZoneDetectionListener_h
#define IDZoneDetectionListener_h

/*! @typedef
 * IDZoneStatus The navigation options.
 */
typedef NS_ENUM(NSInteger, IDZoneStatus) {
    kIDZoneOut,
    /*! 
     * when zone status in
     */
    kIDZoneIn
};


/*! @typedef
 * IDZoneDetectionType The zone detection types.
 */
typedef NS_ENUM(NSInteger, IDZoneDetectionType) {
    /*!
     * when got result of initial detection.
     */
    kIDInitialDetection,
    /*!
     * needed for initial logic detection
     */
    kIDUnknownDetection,
    /*! 
     * when got result of gate detection algorithm.
     */
    kIDGateDetection,
    /*!
     * when got result of deveice BT conectivity or Core Location Services mode is Off.
     */
    kIDDeviceConectivetyDetection,
    
    /*!
     * when got result of deveice BT conectivity or Core Location Services mode is On.
     */
    kIDDeviceConectivetyDetectionOn,
    /*!
     * when got result of deveice BT conectivity or Core Location Services mode.
     */
    kIDUserDefenitionDetection
    
};



////////////////////////////////////////////////////////////////////////////////////////////
// @protocol IDZoneDetectionListener
//
/*!
 * The IDZoneDetectionListener protocol provides feedback on the zone detection updates.
 */

@protocol IDZoneDetectionListener <NSObject>

@required
////////////////////////////////////////////////////////////////////////////////////////
// - updateZone:withDetectionType:
/*!
 * This method is to be called when zone mode changed result of detection type.
 * @param aZoneStatus the zone enum mode IDZoneStatus
 * @param aZoneDetectionType the result of the zone change mode IDZoneDetectionType.
 */
- (void)onUpdateGateWithZoneStatus:(IDZoneStatus)aZoneStatus detectionType:(IDZoneDetectionType)aZoneDetectionType;

@optional
////////////////////////////////////////////////////////////////////////////////////////
// - updateZone:withDetectionType:
/*!
 * This method is to be called when zone mode changed result of detection type.
 * @param aTPStateMode the zone enum mode IDZoneStatus
 */
- (void)onUpdateTheftProtectionStateWithMode:(BOOL)aTPStateMode;


@end


#endif /* IDZoneDetectionListener_h */
