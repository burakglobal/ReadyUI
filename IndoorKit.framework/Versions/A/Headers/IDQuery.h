//
//  IDQuery.h
//  IOSSpreoSDK
//
//  Created by Hasan Sa on 8/23/15.
//  Copyright (c) 2016 Spreo LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
@class IDError;

#ifndef NS_ENUM
@import Foundation;
#endif

/*! 
 * IDQuery
 * The data update status.query conditions type
 */
typedef NS_ENUM(NSInteger, IDQueryType) {
    /*! * Begins with query condition type */
    kQueryBEGINSWITH,
    
    /*! * Contains query condition type */
    kQueryCONTAINS,
    
    /*! * Ends with query condition type */
    kQueryENDSWITH,
    
    /*! * Like query condition type */
    kQueryLIKE,
    
    /*! * Matches with query condition type */
    kQueryMATCHES,
    
    /*! * Like query condition type */
    kQueryGRATERTHAN,
    
    /*! * Like query condition type */
    kQueryLESSTHAN
};


/*!
 * IDQuery Class is to be used in order to filter and search IDKit data moudels Objects [IDPoi, IDGeofence]
 * this class can be used with any NSObject subclass data module Class but in order to filter and search
 * your objects you must use - fetchObjectsFromDataArray: OR fetchObjectsFromDataArray:withBlock:
 */
@interface IDQuery : NSObject

/*!
 * Call this method to init the IDQery Object in order to filter and search IDKit data Objects for.
 * i.e IDPoi Class
 * @param aClass the class to search data Objects for.
 * @code     IDQuery* myQuery = [IDQuery queryWithClass:IDPoi.class];
 */
+ (instancetype)queryWithClass:(Class)aClass;


/*!
 * Call this method in order to add search condition.
 * @param param data to search for - "myPOITitle"
 * @param propertykey add the class property name - like title, ...
 * @param type IDQueryType the query conditions type - like kQueryCONTAINS.
 * @code  [myQuery addQueryParameter:@"myPoiTitle" 
                   whereProperty:@"title"
                   withType:kQueryCONTAINS];
 */
- (void)addQueryParameter:(id)param whereProperty:(NSString*)propertykey withType:(IDQueryType)type;


/*!
 * Call this method in order to search and fetch objects.
 * available for IDPoi and IDGeofence Classes only
 * @return with the filtered objects data Array resultby the query conditions.
 * @code IDPoi* queryPoi = [[myQuery fetchObjects] firstObject];
 */
- (NSArray <id> *)fetchObjects;


/*!
 * Call this method in order to search and fetch objects.
 * available for any NSObject subclass data module Class
 * @param dataArray to search within.
 * @return with the filtered objects data Array result by the query conditions.
 * @code IDPoi* queryPoi = [[myQuery fetchObjectsFromDataArray: myDataArry] firstObject];
 */
- (NSArray <id> *)fetchObjectsFromDataArray:(NSArray*)dataArray;


/*!
 * Call this method in order to search and fetch objects.
 * available for IDPoi and IDGeofence Classes only
 * @param result block with the filtered objects data Array result by the query conditions.
 */
- (void)fetchObjectsWithBlock:(void (^) (NSArray <id> *dataObjects))result;


/*!
 * Call this method in order to search and fetch objects.
 * available for any NSObject subclass data module Class
 * @param dataArray to search within.
 * @param result block with the filtered objects data Array by the query conditions.
 */
- (void)fetchObjectsFromDataArray:(NSArray <id> *)dataArray
                        withBlock:(void (^) (NSArray <id> *dataObjects))result;

@end
