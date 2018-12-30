//
//  IDNavigationDelegate.h
//  IndoorKit
//
//  Copyright (c) 2016 Spreo LLC. All rights reserved.
//

#import "IDNavigationType.h"

@class IDUserLocation, IDRoute, IDLocation;

////////////////////////////////////////////////////////////////////////////////////////////
//******************************************************************************************
// IDNavigationDelegate
//
/*! 
 * The IDNavigationDelegate protocol provides feedback on the navigation status.
 */

@protocol IDNavigationDelegate <NSObject>

@optional

////////////////////////////////////////////////////////////////////////////////////////
// - updateWithRoute:
/*!
 * This method is to be called when navigation or simulation navigation started
 * @param aRoute IDRoute object
 */
- (void)updateWithRoute:(IDRoute *)aRoute;


////////////////////////////////////////////////////////////////////////////////////////
// - updateWithInstruction:andStatus:
/*!
 * This method is to be called when navigation engine will update instruction with status
 * @param anInstruction NSDictionary instruction like 
 * @{@"id" : @"7", @"text" : @"destination just ahead"}
 * @param aStatus IDNavigationStatus enum type
 */
- (void)updateWithInstruction:(NSDictionary *)anInstruction andStatus:(IDNavigationStatus)aStatus;


////////////////////////////////////////////////////////////////////////////////////////
// - playInstructionSound:
/*!
 * This method is to be called when navigation engine will play instruction sound
 */
- (void)playInstructionSound;


////////////////////////////////////////////////////////////////////////////////////////
// - playSoundForInstruction:
/*!
 * This method is to be called when navigation engine will play instruction sound
 * @param anInstruction NSDictionary instruction like
 * @{@"id" : @"7", @"text" : @"destination just ahead"}
 */
- (void)playSoundForInstruction:(NSDictionary*)anInstruction;


////////////////////////////////////////////////////////////////////////////////////////
// - navigationUpdateWithStatus:
/*!
 * This method is to be called when navigation engine will update status
 * @param aStatus IDNavigationStatus enum type
 */
- (void)navigationUpdateWithStatus:(IDNavigationStatus)aStatus;


////////////////////////////////////////////////////////////////////////////////////////
// - navigationArriveToLocation:nextLocations:
/*!
 * This method is to be called when multi navigation starterd 
 * after calling [IDkit  startNavigateToLocations:withOptions:andDelegate:] method
 * or calling [IDkit  startSimulationNavigationToLocations:fromLocation:withOptions:andDelegate:] method
 * and the user did arrive to first location from nextLocations array
 * @param aLocation IDNavigationStatus enum type
 * @param aNextLocations locations Array
 */
- (void)navigationArriveToLocation:(IDLocation *)aLocation nextLocations:(NSArray<IDLocation*> *)aNextLocations;


@end
