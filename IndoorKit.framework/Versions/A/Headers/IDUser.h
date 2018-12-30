//
//  IDUser.h
//  IOSSpreoSDK
//
//  Created by Hasan Sa on 8/4/15.
//  Copyright (c) 2016 Spreo LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
@class IDLocation;

////////////////////////////////////////////////////////////////////////////////////////////
//
// IDUser
/*!
 * The Indoor Kit User Class.
 */

@interface IDUser : NSObject


/*!
 * @brief The User Unique Identifier.
 */
@property (nonatomic, strong) NSString* identifier;

/*!
 * @brief The User Title.
 */
@property (nonatomic, strong) NSString* title;


/*!
 * @brief The User Location. IDLocation Class.
 */
@property (nonatomic, strong) IDLocation* location;



/*!
 *  User designated Intitializer
 *
 *  @param anId the user identifier
 *  @param aTitle    the user title
 *  @param aLocation the user location
 *
 *  @return IDUser
 */
- (instancetype)initUserWithId:(NSString*)anId
                         title:(NSString*)aTitle
                   andLocation:(IDLocation*)aLocation NS_DESIGNATED_INITIALIZER;

@end
