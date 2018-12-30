//
//  IDPoiViewRegioning.h
//  IndoorKit
//
//  Copyright (c) 2016 Spreo LLC. All rights reserved.
//

@class IDPoi;

////////////////////////////////////////////////////////////////////////////////////////////
// IDPoiViewRegioning
//
/*! 
 * The IDPoiViewRegioning protocol provides feedback on the poi region status.
 */

@protocol IDPoiViewRegioning <NSObject>

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - didEnterRegionOfPOI:
//
/*!
 * when user position did enter region of Poi
 * @param aPoi poi region
 */
- (void)didEnterRegionOfPOI:(IDPoi *)aPoi;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// - didExitRegionOfPOI:
//
/*!
 * when user position did exit region of Poi
 * @param aPoi poi region
 */
- (void)didExitRegionOfPOI:(IDPoi *)aPoi;

@end
