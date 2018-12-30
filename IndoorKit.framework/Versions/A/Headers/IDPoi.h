//
//  IDPoi.h
//  IndoorKit
//
//  Copyright (c) 2016 Spreo LLC. All rights reserved.
//

@class IDLocation;
@class IDCategory;
@class IDPoiDistance;

////////////////////////////////////////////////////////////////////////////////////////////
//
// IDPoi
/*!
 * The Indoor Kit Poi Class.
 */

@interface IDPoi : NSObject <NSCoding, NSCopying>

/*!
 * @brief The Poi Title.
 */
@property (nonatomic, readonly, copy) NSString *title;


/*!
 * @brief The Poi Subtitle.
 */
@property (nonatomic, readonly, copy) NSString *subtitle;


/*!
 * @brief The Poi Unique Identifier.
 */
@property (nonatomic, strong, readonly) NSString *identifier;


/*!
 * @brief The Poi Categories Array.
 */
@property (nonatomic, strong, readonly) NSArray<NSString *> *categories;

/*!
 * @brief The Poi CategoriesWithFilters Array.
 */
@property (nonatomic, strong) NSArray<IDCategory *> *categoriesWithFilters;


/*!
 * @brief The Poi Location. IDLocation Class.
 */
@property (nonatomic) IDLocation *location;


/*!
 * @brief The Poi Distance Infor from current user location.
 */
@property (nonatomic, strong) NSDictionary *info;

@property (nonatomic) BOOL labelAlgorithm;
@property (nonatomic) BOOL isShowIcon;
@property (nonatomic) BOOL isShowLabel;
@property (nonatomic) int showType;
@property (nonatomic, strong) UIImage* iconWithTitle;
@property (nonatomic, strong) UIImage* iconJustTitle;

/*!
 * @brief The Poi Info Dictionary.
 */
@property (nonatomic, strong) IDPoiDistance *poiDistance;
 

/*!
 *  IDPoi designated Intitializer
 *
 *  @param aDictionary the POI data dictionary
 *  @param aLocation the POI location <IDLocation>
 *
 *  @return IDPoi instance
 */
- (instancetype)initPoiWithDictionary:(NSDictionary *)aDictionary
                          andLocation:(IDLocation *)aLocation NS_DESIGNATED_INITIALIZER;


/*!
 *  IDPoi designated Intitializer
 *
 *  @param aTitle the POI title NSString
 *  @param aSubtitle the POI subtitle NSString
 *  @param aDescription the POI description NSString
 *  @param anIdentifier the POI identifier NSString
 *  @param categories the POI categories NSArray<NSString *>
 *  @param aLocation the POI location <IDLocation>
 *  @param aDictionary the POI info data dictionary NSDictionary
 *
 *  @return IDPoi instance
 */
- (instancetype)initPoiWithTitle:(NSString *)aTitle
                        subtitle:(NSString *)aSubtitle
                     description:(NSString *)aDescription
                      identifier:(NSString *)anIdentifier
                      categories:(NSArray<NSString *> *)categories
                        location:(IDLocation *)aLocation
                         andInfo:(NSDictionary *)aDictionary NS_DESIGNATED_INITIALIZER;

@end
