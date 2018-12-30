//
//  IDCalloutsProtocol.h
//  IOSSpreoSDK
//
//  Created by Hasan Sa on 8/10/15.
//  Copyright (c) 2016 Spreo LLC. All rights reserved.
//

#ifndef IOSSpreoSDK_IDCalloutsProtocol_h
#define IOSSpreoSDK_IDCalloutsProtocol_h

////////////////////////////////////////////////////////////////////////////////////////////
// IDPoiViewProtocol
//
/*! 
 * The IDPoiViewProtocol protocol provides feedback on the poi
 * with user location and region from poi on map.
 * with bubble view (callout) presentation;
 */


#ifndef NS_ENUM
@import Foundation;
#endif
typedef NS_ENUM(NSInteger, IDCalloutMode) {
    IDCalloutRegioning,
    IDCalloutSelection
};

@protocol IDCalloutsProtocol <NSObject>

@required
/*!
 * @brief bubblesLayerView
 */
@property (nonatomic, strong) UIView* bubblesLayerView;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - shouldResponseToLocationRegioning
//
/*!
 * @return YES in order to allow The Indoor Kit to call presentBubbleViewWithMode:
     with IDCalloutsRegioning when user enters region Of POI.
 * @see bubbleView
 * @see presentBubbleViewWithMode:
 * @see dismissBubbleView
 */
- (BOOL)shouldResponseToLocationRegioning;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - bubbleView
//
/*!
 * when user position did enter region of Poi
 * @return your custom bubble view in order to allow The Indoor Kit to change bubble scale or bubble rotation if needed.
 */
- (UIView*)bubbleView;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - presentBubbleViewWithMode
//
/*!
 * when user position enters region of Poi
 * you shoud prsents the bubble view in bubblesLayerView
 *  bubble view in order to allow The Indoor Kit to change bubble scale or bubble rotation if nedded.
 * @param aMode IDCalloutsMode nither Regioning when user enters poi region
 * or Selection you call @code [self.mapVC showBubbleForPoi:aPoi];
 */
- (void)presentBubbleViewWithMode:(IDCalloutMode)aMode;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - dismissBubbleView
//
/*!
 * when user position exits region of Poi
 *  bubble view in order to allow The Indoor Kit to change bubble scale or bubble rotation if nedded.
 */
- (void)dismissBubbleView;

@end


#endif
