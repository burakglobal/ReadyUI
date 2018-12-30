//
//  IDInstructionsControllerDelegate.h
//  IndoorKit
//
//  Copyright (c) 2016 Spreo LLC. All rights reserved.
//

////////////////////////////////////////////////////////////////////////////////////////////
// IDInstructionsControllerDelegate
//
/*!
 * The IDInstructionsControllerDelegate protocol provides feedback on the navigation status.
 */

@protocol IDInstructionsControllerDelegate <NSObject>
@optional

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - didFinishPlayInstruction:
//
/*!
 this method called when instruction did finish play
 @param anInstruction NSDictionary - instruction data
 */
- (void)didFinishPlayInstruction:(NSDictionary *)anInstruction;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - stopNavigationTapped
//
/*!
 this method called when the user force stop navigation
  (see the IndoorKitDemo App example...).
 */
- (void)stopNavigationTapped;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - showInstructionsList
//
/*!
 this method called when the user swipe left on the Instrucrion View
 (see the IndoorKitDemo App example...).
 */
- (void)showInstructionsList;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - showRouteOverview
//
/*!
 this method called when the user swipe right on the Instrucrion View
  (see the IndoorKitDemo App example...).
 */
- (void)showRouteOverview;

@end
