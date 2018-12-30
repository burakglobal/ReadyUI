//
//  IDPoiDistance.h
//  IndoorKit
//
//  Created by Nikita Smolyanchenko on 11/27/17.
//  Copyright © 2017 Spreo LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
@class IDPoi;

////////////////////////////////////////////////////////////////////////////////////////////
//
// IDPoiDistance
/*!
 * The Indoor Kit Poi Distance Class.
 */

@interface IDPoiDistance : NSObject
/*!
 * @brief The Poi.
 */
@property (nonatomic, strong) IDPoi *poi;

/*!
 * @brief distance to the poi.
 */
@property (nonatomic, assign) CLLocationDistance distance;

@end
