//
//  IDInstructionsViewController.h
//  IndoorKit
//
//  Copyright (c) 2016 Spreo LLC. All rights reserved.
//

#import "IDInstructionsControllerDelegate.h"
#import "IDNavigationType.h"


////////////////////////////////////////////////////////////////////////////////////////////
// IDInstructionsController
//
 
/*!
 * The IDInstructionsViewController to present the navigation instructions.
 */

@interface IDInstructionsViewController : UIViewController


/*!
 * @brief in order to get IDInstructionsViewController the callbacks.
 */
@property (nonatomic, assign) id<IDInstructionsControllerDelegate> delegate;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - presentInstructionFromOriginY:toPositionY:
//
/*!
 * call this method when user starts navigation
 * the instruction view will be presented form 2 different y origin with animation
 * @param yOrigin first y position
 * @param yPosition second y position
*/
- (void)presentInstructionFromOriginY:(CGFloat)yOrigin toPositionY:(CGFloat)yPosition;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - dismissInstruction:
//
/*!
 * call this method when user stop navigation
 * the instruction view will dismissed
*/
- (void)dismissInstruction;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - updateWithInstruction:andStatus:
//
/*!
 * call this method when there is an indecation from the IDNavigationDelegate method:
 * to update the UI of the Instruction View.
 * @param anInstruction NSDictionary of IDNavInstructions enum type
 * @param aStatus IDNavigationStatus enum type
 */
- (void)updateWithInstruction:(NSDictionary *)anInstruction andStatus:(IDNavigationStatus)aStatus;

- (void)updateViewForInstruction:(NSDictionary *)anInstruction;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - playInstructionSound:
//
/*!
 * call this method when there is an indecation from the IDNavigationDelegate method:
 * to play the Instruction sounds.
 */
- (void)playInstructionSound;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - playSoundForInstruction:
//
/*!
 * call this method when there is an indecation from the IDNavigationDelegate method:
 * to play the Instruction sounds of instruction.
 * @param anInstruction to play sound of;
 */

- (void)playSoundForInstruction:(NSDictionary *)anInstruction;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - getInstructionsList:
//
/*!
 * call this method when the navigation have been started, get
 * array of dictionaries each dictionary = <"routeIndex" : 0,.. route index, "type" : indoor or outdoor,
 * "instruction": array of instruction dictionaries> 
 * each dictionary = <"id" : IDNavInstructions enum type, "text"  : instruction text ,"image" :instruction UIImage>
 * @return Returns instruction list
 */
@property (nonatomic, getter=getInstructionsList, readonly, copy) IDCombinedRoute *instructionsList;

/*!
 * call this method when the navigation have been started, get overviews
 * array of dictionaries 
 * each dictionary = <"overviews" : UIImageView for floormap - contains map + route + start & end points drawed on it",
 * "type" : indoor or outdoor, "title" : floormap title>
 * @return Returns overviews
 */
@property (nonatomic, getter=getRouteOverviews, readonly, copy) NSArray *routeOverviews;

@end
