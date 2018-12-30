//
//  IDLabel.h
//  IOSSpreoSDK
//
//  
//  Copyright (c) 2016 Spreo LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IDLabel_Keys.h"

@interface IDLabel : NSObject

/*!
 * @brief The Label identifier.
 */
@property (nonatomic, strong, readonly) NSString* identifier;

/*!
 * @brief The Label frame.
 */
@property (nonatomic, assign, readonly) CGRect rect;

/*!
 * @brief The Label center.
 */
@property (nonatomic, assign, readonly) CGPoint center;

/*!
 * @brief The Label floor.
 */
@property (nonatomic, assign, readonly) NSInteger floor;


/*!
 * @brief The Label text.
 */
@property (nonatomic, strong, readonly) NSString* text;


/*!
 * @brief The Label attitude default label rotaion angle.
 */
@property (nonatomic, assign, readonly) CLLocationDegrees attitude;

/*!
 * @brief The Label attitude default label rotaion angle.
 */
@property (nonatomic, assign, readonly) CLLocationDegrees currentAttitude;


/*!
 * @brief The Label style data as dictionary.
 * @code {  @"background_color": background_color, @"border_color": border_color, @"text_color": foreground_color,
            @"border_round_courner": @(border_round_courner), @"border_width": @(border_width), @"text_size": @(text_size),
            @"font": font}
 *
 *
 */
@property (nonatomic, strong, readonly) NSDictionary* styleInfo;


/*!
 * @brief The Label reference object
 */
@property (nonatomic, strong) id reference;



/*!
 * @brief is visible property 
 */
@property BOOL visible;



/*!
 *  IDLabel designated Intitializer
 *
 *  @param aText the label Text
 *  @param anIdentifier the label uniqie identifier
 *  @param aRect the label region position on map
 *  @param aFloor the label floor on map
 *  @param anAttitude the label rotation attitude
 *  @param aStyleInfo the label custom style i.e : {  @"background_color": background_color, @"border_color": border_color, @"text_color": foreground_color,
 *                           @"border_round_courner": @(border_round_courner), @"border_width": @(border_width), @"text_size": @(text_size),
 *   @"font": font}
 *
 *  @return IDLabel new instance
 */
- (instancetype)initWithText:(NSString *)aText
                  identifier:(NSString *)anIdentifier
                        rect:(CGRect)aRect
                     atFloor:(NSInteger)aFloor
                withAttitude:(CLLocationDegrees)anAttitude
               withStyleInfo:(NSDictionary *)aStyleInfo NS_DESIGNATED_INITIALIZER;


@end
