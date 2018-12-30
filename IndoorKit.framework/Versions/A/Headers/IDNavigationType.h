//
//  IDNavigationType.h
//  IndoorKit
//
//  Copyright (c) 2016 Spreo LLC. All rights reserved.
//


////////////////////////////////////////////////////////////////////////////////////////////
// IDLocationDetectionStatus
//
/*! @typedef
 * IDLocationDetectionStatus The location detection statuses.
 * (i.e. Bluetooth, CoreLocation Authorization)
 */

#ifndef NS_ENUM
@import Foundation;
#endif
#ifndef NS_ENUM
#import <Foundation/Foundation.h>
#endif
typedef NS_ENUM(NSInteger, IDLocationDetectionStatus) {
    kLocationDetectionUnknown     = 0,
    kLocationDetectionOff         = 1,
    kLocationDetectionOn          = 2,
    kLocationDetectionDetectNON   = 5
};

typedef NS_ENUM(NSInteger, ReportLimitation) {
    kLimitMonitoringKeyAlways,
    kLimitMonitoringKeyIndoor,
    kLimitMonitoringKeyInCampus
};


////////////////////////////////////////////////////////////////////////////////////////////
// IDRegionEventType
//
/*! @typedef
 *  IDRegionEventType The region events types.
 */

typedef NS_ENUM(NSInteger, IDRegionEventType) {
    kRegionEventNon,
    kRegionEventIn,
    kRegionEventOut,
    kRegionEventDuringIn
};

////////////////////////////////////////////////////////////////////////////////////////////
// IDNavigationStatus
//
/*! @typedef
 *  IDNavigationStatus The navigation statuses.
 */

typedef NS_ENUM(NSInteger, IDNavigationStatus) {
    kNavigationIdle               = 0,
    kNavigationStart              = 1,
    kNavigationNavigate           = 2,
    kNavigationChangeFloor        = 3,
    kNavigationTurnBack           = 4,
    kNavigationReroute            = 5,
    kNavigationStopped            = 6,
    kNavigationEnded              = 7,
    kNavigationPending            = 8,
    kNavigationNewRoute           = 9
};


////////////////////////////////////////////////////////////////////////////////////////////
// IDNavInstructions
//
/*! @typedef
 *  IDNavInstructions The navigation instructions modes.
 */

typedef NS_ENUM(NSInteger, IDNavInstructions) {
    kNavInstructionStraight                 = 0,
    kNavInstructionTurnLeft                 = 1,
    kNavInstructionLeftHall                 = 2,
    kNavInstructionTurnRight                = 3,
    kNavInstructionRightHall                = 4,
    kNavInstructionElevatorUp               = 5,
    kNavInstructionElevatorDown             = 6,
    kNavInstructionDestination              = 7,
    kNavInstructionTurnBack                 = 8,
    kNavInstructionRecalculate              = 9,
    kNavInstructionProceedOutdoor           = 10,
    kNavInstructionProceedIndoor            = 11,
    kNavInstructionProceedArrowDirection    = 12,
    kNavInstructionEscalatorUp              = 13,
    kNavInstructionEscalatorDown            = 14,
    kNavInstructionSimplifiedDestination    = 15,
    kNavInstructionDoNothing                = 99

};



////////////////////////////////////////////////////////////////////////////////////////////
// IDNavigationOptions
//

/*! @typedef
 * IDNavigationOptions The navigation options.
 */

typedef NS_ENUM(NSInteger, IDNavigationOptions) {
    /*! Calculate best route with Priority to Elevators than Escalators for Disabled.
     */
    kNavigationOptionDisabled       = 0,
    
    /*! Calculate best route with Priority to Escalators than Elevators or the shortest.
     * In case there is a combined indoor and outdoor route calucate the best Exit/Entrance to the Destination.
     */
    kNavigationOptionRegular        = 1,
    
    
    /*! as kNavigationOptionRegular.
     * BUT in case there is a combined indoor and outdoor route calucate the best Exit/Entrance to the Origin.
     */
    kNavigationOptionStaff          = 2
};
