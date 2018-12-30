//
//  IDCategory.h
//  IOSSpreoSDKDual
//
//  Created by Dmitry Pliushchai on 2/23/17.
//  Copyright © 2017 Spreo LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface IDCategory : NSObject

/*!
 *  The Category Name.
 */
@property (nonatomic, strong) NSString *name;

/*!
 * @brief Show category in categories.
 */
@property (nonatomic, assign) BOOL showInCategories;

/*!
 * @brief Show category in map filter.
 */
@property (nonatomic, assign) BOOL showInMapFilter;

/*!
 * @brief The Category Image.
 */
@property (nonatomic, strong) UIImage *image;

@end
