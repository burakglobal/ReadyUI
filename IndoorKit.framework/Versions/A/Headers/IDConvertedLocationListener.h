//
//  IDConvertedLocationListener.h
//  IOSSpreoSDK
//
//  Created by Hasan Sa on 8/18/15.
//  Copyright (c) 2016 Spreo LLC. All rights reserved.
//

@class IDConvertedLocation;

////////////////////////////////////////////////////////////////////////////////////////////
//******************************************************************************************
// IDConvertedLocationListener
//
/*!
 * The IDLocationListener protocol provides feedback on the converted location updates.
 */

@protocol IDConvertedLocationListener <NSObject>

@optional
////////////////////////////////////////////////////////////////////////////////////////
// - updateUserLocationWithLocation:
/*!
 * This method is to be called when the user location be updated
 * @param aLocation IDUserLocation class
 */
- (void)updateUserConvertedLocation:(IDConvertedLocation *)aLocation;

@end
