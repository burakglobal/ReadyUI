//
//  IDError.h
//  IndoorKit
//
//  Copyright (c) 2016 Spreo LLC. All rights reserved.
//

////////////////////////////////////////////////////////////////////////////////////////////
// IDErrorId
//


#ifndef NS_ENUM
@import Foundation;
#endif

/*!
 * @typedef IDErrorId
 * @discussion The error types.
 */
typedef NS_ENUM(NSInteger, IDErrorId) {
    kIDErrorNetworkNotReachable         = 4004,
    kIDErrorNetworkRequestTimeout       = 4001,
    kIDErrorNoValidData                 = 4008,
    kIDErrorNoValidResponse             = 4005,
    kIDErrorNoPermission                = 4000,
    kIDErrorCustom                      = 4002,
    kIDErrorUnknown                     = 4003
};

////////////////////////////////////////////////////////////////////////////////////////////
//
// IDError
/*!
 * The Indoor Kit Erorr Class.
 */

@interface IDError : NSError

@end
