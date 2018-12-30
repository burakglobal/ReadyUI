//
//  IDDataUpdateDelegate.h
//  IndoorKit
//
//  Copyright (c) 2016 Spreo LLC. All rights reserved.
//

////////////////////////////////////////////////////////////////////////////////////////////
// IDDataUpdateStatus
//
@class IDError;


#ifndef NS_ENUM
@import Foundation;
#endif

/*! 
 * @typedef IDDataUpdateStatus
 * @discussion The data update status.
 */

typedef NS_ENUM(NSInteger, IDDataUpdateStatus) {
    kIDDataUpdateCheckForUpdates,
    kIDDataUpdateCopyFiles,
    kIDDataUpdateDataDownload,
    kIDDataUpdateInitialising,
    kIDDataUpdateDone
};

////////////////////////////////////////////////////////////////////////////////////////////
// IDDataUpdateDelegate
//
/*!
 * The IDDataUpdateDelegate protocol provides feedback on the data update phase process.
 */
@protocol IDDataUpdateDelegate <NSObject>

///////////////////////////////////////////////////////////////////////////////////////////
// - dataUpdateStatus:
/*!
 *  To get the data download status
 * @param aStatus IDDataUpdateStatus enum type
 */
- (void)dataUpdateStatus:(IDDataUpdateStatus)aStatus;



///////////////////////////////////////////////////////////////////////////////////////////
// - dataUpdateFailedWithError:
/*!
 *  To get the data download failed error description
 * @param anError error description IDError
 */
- (void)dataUpdateFailedWithError:(IDError*)anError;

@end
