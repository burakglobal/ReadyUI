//
//  IDKit.h
//  IndoorKit
//
//  Copyright (c) 2016 Spreo LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
//
#import <IndoorKit/IDDataUpdateDelegate.h>
#import <IndoorKit/IDError.h>
//
#import <IndoorKit/IDQuery.h>
//
#import <IndoorKit/IDUser.h>
//
#import <IndoorKit/IDGeofence.h>
//
#import <IndoorKit/IDGeofenceDelegate.h>
//
#import <IndoorKit/IDLocation.h>
#import <IndoorKit/IDConvertedLocation.h>
//
#import <IndoorKit/IDPoi.h>
#import <IndoorKit/IDFriend.h>

//
#import <IndoorKit/IDNavigationType.h>
#import <IndoorKit/IDRoute.h>
//
#import <IndoorKit/IDNavigationDelegate.h>
#import <IndoorKit/IDLocationListener.h>
#import <IndoorKit/IDConvertedLocationListener.h>
//
#import <IndoorKit/IDMapViewController.h>
#import <IndoorKit/IDMapViewControllerDelegate.h>
//
#import <IndoorKit/IDDualMapViewController.h>
#import <IndoorKit/IDDualMapViewControllerDelegate.h>
//
#import <IndoorKit/IDInstructionsViewController.h>
#import <IndoorKit/IDInstructionsControllerDelegate.h>
//
#import <IndoorKit/IDZoneDetectionListener.h>
//
#import "IndoorKit/IDProjectLocation.h"

#import "IDCategory.h"
#import "IDPoiDistance.h"


#ifndef __IDKIT_AVAILABLE_BUT_DEPRECATED
#define __IDKIT_AVAILABLE_BUT_DEPRECATED __deprecated
#endif

////////////////////////////////////////////////////////////////////////////////////////
// IDKit
//
/*!
 * The Indoor Navigation System SDK effectively uses these components to ensure power
 * conservation and resource management.
 * The system is multi threaded using several threads for several tasks.
 * All calls between The Indoor Kit and the applications are done within the main thread.
 * The Indoor Kit uses the iOS device components and frameworks
 * to achieve the best indoor and outdoor location within a facility or campus.
 */


@interface IDKit : NSObject


////////////////////////////////////////////////////////////////////////////////////////
// + version
/*!
 * The method returns the version string of the IndoorKit SDK
 * @return  Version string
 */

+ (NSString *_Nonnull)version;

#pragma mark - APIKey, Data Update & Initialization

////////////////////////////////////////////////////////////////////////////////////////
// + setAPIKey:
/*!
 * The method register to services and enables the application to use the
 corresponding location, navigation and geofence services without server communication.
 * @param   anAPIKey app api key
 */
+ (void)setAPIKey:(NSString *_Nonnull)anAPIKey;


////////////////////////////////////////////////////////////////////////////////////////
// + setAPIKey:error:
/*!
 * The method register to services and enables the application to use the
 corresponding location, navigation and geofence services with server communication.
 * @param   anAPIKey app api key
 * @param   anError if an error occurs, upon return contains an IDError object that describes the problem.
 */
+ (void)setAPIKey:(NSString *_Nullable)anAPIKey error:(IDError *_Nullable *_Nullable)anError;


////////////////////////////////////////////////////////////////////////////////////////
// + checkForDataUpdatesAndInitialiseWithDelegate:
//
/*!
 * The method initialises the check of remote data update on the specified
 server and data module initialisation. The data download is done on a
 back thread and the status is updated using the delegate protocol.
 * @param   aDelegate object that implements the delegation protocol.
 */

+ (void)checkForDataUpdatesAndInitialiseWithDelegate:(nullable id<IDDataUpdateDelegate>)aDelegate;


////////////////////////////////////////////////////////////////////////////////////////
// + initializeDataWithDelegate:
//
/*!
 * The method initialises the check of remote data update on the specified
 server and data module initialisation. The data download is done on a
 back thread and the status is updated using the delegate protocol.
 * @param   aDelegate object that implements the delegation protocol.
 */

+ (void)initializeDataWithDelegate:(nullable id<IDDataUpdateDelegate>)aDelegate;



#pragma mark - Statistics & Analytics

////////////////////////////////////////////////////////////////////////////////////////
// + setUserID:
//
/*!
 * The method set a user id for the system, that user id will be used on all
 statistics and server interactions, in case that that method is not called
 or a nil value is received, the system generate a random uuid that will
 represent the user.
 * @param   anIdentifier user identifier string.
 * \code    [IDKit setUserID:@"<PUT YOUR USER ID HERE>”];
 */

+ (void)setUserID:(NSString *_Nullable)anIdentifier;



////////////////////////////////////////////////////////////////////////////////////////
// + setUserLocationSharingMode:
//
/*!
 * The method enables / disables the user location sharing mode.
 * interval in seconds between updates is 300 seconds (5 min).
 * @param   aMode BOOL value
 */

+ (void)setUserLocationSharingMode:(BOOL)aMode;




////////////////////////////////////////////////////////////////////////////////////////
// + setUserLocationSharingMode:withInterval:
//
/*!
 * The method sets the user location sharing time interval updates, 300 seconds (default)
 * @param interval Interval in seconds between updates. MUST be grater than 0
 */
+ (void)setUserLocationSharingTimeInterval:(NSTimeInterval)interval;




////////////////////////////////////////////////////////////////////////////////////////
// + startPollingtUsersLocationSharingDataWithInterval:forUserIds:update:
/*!
 *  @abstract Start users location at certain intervals.
 *
 *  @param interval Interval in seconds between updates.
 *  @param userIds   filter users with specific Ids.
 *  @param update   A block object to be executed when the request operation finishes successfully with result. This block has no return value and takes one argument : the users data array of IDUser objects.
 *  @see IDUser
 *  @param failure  A block object to be executed when the request operation finishes unsuccessfully. This block has no return value and takes one argument : the error IDError.
 */
+ (void)startPollingtUsersLocationSharingDataWithInterval:(NSTimeInterval)interval
                                              forUserIds:(NSArray<NSString *> *_Nullable)userIds
                                                  update:(nullable void (^) (NSArray<IDUser *> *_Nonnull users))update
                                                 failure:(nullable void (^) (IDError *_Nonnull error))failure;


////////////////////////////////////////////////////////////////////////////////////////
// + stopPollingUsersLocationSharingData
/*!
 *  @abstract Stop users location sharing polling data at certain intervals.
 */
+ (void)stopPollingUsersLocationSharingData;


////////////////////////////////////////////////////////////////////////////////////////
// + setLocationReportLimitation:
//
/*!
 With this method you can limit analytics location update with
 type = 0 - Always
 type = 1 - Indoor
 type = 2 - In Campus
 */
+ (void)setLocationReportLimitation: (ReportLimitation)reportLimit;

////////////////////////////////////////////////////////////////////////////////////////
// + setMonitoringMode:
//
/*!
 The method enables / disables the monitoring mode,when its enabled
 beacons data will be uploaded to the server
 , in case that that method is not called
 or a NO value is received, the statistics will not be upload any data to the server.
 @param   aMode BOOL value
 */

+ (void)setMonitoringMode:(BOOL)aMode;

////////////////////////////////////////////////////////////////////////////////////////
// + setAutomaticReRoute:
+ (void)setAutomaticReRoute:(BOOL)aMode;


////////////////////////////////////////////////////////////////////////
// + setZipPackageWithoutMaps:
//

+ (void)setZipPackageWithoutMaps:(BOOL)aMode;


////////////////////////////////////////////////////////////////////////
// + setMotionDR:
//

+ (void)setMotionDR:(BOOL)aMode;

////////////////////////////////////////////////////////////////////////
// + setNoOutdoorCampus:
//

+ (void)setNoOutdoorCampus:(BOOL)aMode;

////////////////////////////////////////////////////////////////////////
// + setTileCaching:
//

 + (void)setTileCaching:(BOOL)aMode;

////////////////////////////////////////////////////////////////////////
// + setExitCloseToOrigin:
//

+ (void)setExitCloseToOrigin:(BOOL)aMode;

////////////////////////////////////////////////////////////////////////////////////////
// + setAnalyticsMode:
//
/*!
 The method enables / disables the analytics mode,when its enabled
 statistics data will be uploaded to the server
 , in case that that method is not called
 or a NO value is received, the statistics will not be upload any data to the server.
 @param   aMode BOOL value
 */

+ (void)setAnalyticsMode:(BOOL)aMode;


////////////////////////////////////////////////////////////////////////////////////////
// + setAnalyticsTimeInterval:
//
/*!
 The method set a time interval in minutes for the system, the time interval will be used for
 data upload timer, in case nil value is received, 300 sec 5 minutes is default.
 @param   aTimeInterval integer value time interval in minutes.
 */

+ (void)setAnalyticsTimeInterval:(CGFloat)aTimeInterval;



////////////////////////////////////////////////////////////////////////////////////////
// + sendAnalyticsReportWithAction:andTitle:
//
/*!
 * The method sends analytics data to server, use this API when user did search for
 poi or did navigate for poi, using this API updates the server analyitcs data.
 * @param anAction string
 * @param aTitle title to send.
 * @code [IDKit sendAnalyticsReportWithAction:kAnalyticsActionSearch andTitle:@"apoiId"];
 @endcode
 */
+ (void)sendAnalyticsReportWithAction:(NSString *_Nullable )anAction andTitle:(NSString *_Nullable)aTitle;

////////////////////////////////////////////////////////////////////////////////////////
// + enableLogging:
//
/*!
 * Enables console log output for the SDK.
 * @param yesOrNo NO by default.
 */
+ (void)enableLogging:(BOOL)yesOrNo;

////////////////////////////////////////////////////////////////////////////////////////
// + setLoggerWithMode:
//
/*!
 * The method sets the logger mode to File | Server.
 * YES will engage the logger, and NO will turn it off.
 * @param   aMode YES / NO
 */
+ (void)setLoggerWithMode:(BOOL)aMode;

////////////////////////////////////////////////////////////////////////////////////////
// + monitorCampusRegion:
//
/*!
 * The method sets or removes the region monitoring for the project campuses
 * @param   aMode YES / NO
 */

+ (void)monitorCampusesRegion:(BOOL)aMode;

#pragma mark - Location Tracking APIs

////////////////////////////////////////////////////////////////////////////////////////
// + startUserLocationTrack
//
/*!
 * The method starts user location track, location updates and geofence
 awareness starts. The methods return YES, in case it succeed to start the
 location tracking, otherwise NO is returned.
 * @return  Success indication faile / succeeded
 */

+ (BOOL)startUserLocationTrack;



////////////////////////////////////////////////////////////////////////////////////////
// + startUserLocationTrackWithCLLocationManager:
//
/*!
 * The method starts user location track, location updates and geofence
 * awareness starts, with your custom location manager. 
 * The methods return YES, in case it succeed to start the
 * location tracking, otherwise NO is returned.
 * note in order to recive the CLLocation manager changes anupdates use @code[IDKit registerToCLLocationManagerDelegateWithDelegate:self]
 * @endcode insteate @code aLocationManager.delegate = self@endcode
 * @param aLocationManager initialazed CLLocationManager instance
 * @return  Success indication faile / succeeded
 */

+ (BOOL)startUserLocationTrackWithCLLocationManager:(CLLocationManager *_Nullable)aLocationManager;


////////////////////////////////////////////////////////////////////////////////////////
// + registerToCLLocationManagerDelegateWithDelegate:
//
/*!
 * to receive location and heading updates from a CLLocationManager object.
 * Upon receiving a successful location or heading update, you can use the result to update your user interface or perform other actions. 
 * If the location or heading could not be determined, you might want to stop updates for a short period of time and try again later.
 * @param aDelegate the CLLocationManagerDelegate to add.
 * @return  Success indication register failed / succeeded
 */
+ (BOOL)registerToCLLocationManagerDelegateWithDelegate:(nullable id<CLLocationManagerDelegate>)aDelegate;


////////////////////////////////////////////////////////////////////////////////////////
// + unregisterToCLLocationManagerDelegateWithDelegate:
//
/*!
 * to stop receiveing the location and heading updates from a CLLocationManager object.
 * @param aDelegate the CLLocationManagerDelegate to remove.
 * @return  Success indication unregister failed / succeeded
 */
+ (BOOL)unregisterToCLLocationManagerDelegateWithDelegate:(nullable id<CLLocationManagerDelegate>)aDelegate;



////////////////////////////////////////////////////////////////////////////////////////
// + stopUserLocationTrack
//
/*!
 The method stop user location track, location updates and geofence
 awareness stop. The methods return YES, in case it succeed to stop the
 location tracking, otherwise NO is returned.
 @return  Success indication faile / succeeded
 */

+ (BOOL)stopUserLocationTrack;



////////////////////////////////////////////////////////////////////////////////////////
// + resetUserLocationTrack
//
/*!
 The method reset user location track, location updates and geofence
 awareness start again. The methods return YES, in case it succeed to restart again the
 location tracking, otherwise NO is returned.
 @return  Success indication faile / succeeded
 */

+ (BOOL)resetUserLocationTrack;


////////////////////////////////////////////////////////////////////////////////////////
// + moveToBackgroundAndContinueScanning
//
/*!
 Notify SDK that the app is moving to background and you want the RF to shutoff or not
 */

+ (void)moveToBackgroundAndContinueScanning:(BOOL)keepScan;



////////////////////////////////////////////////////////////////////////////////////////
// + moveToForeground
//
/*!
 Notify SDK When the app is in foreground event
 */

+ (void)moveToForeground;


#pragma mark - Location Listener APIs


////////////////////////////////////////////////////////////////////////////////////////
// + registerToLocationListenerWithDelegate:
//
/*!
 * The method add the object that implements the IDNavigationDelegate protocol
 * @param   aDelegate object that implements the location delegation protocol
 */
+ (void)registerToLocationListenerWithDelegate:(nullable id<IDLocationListener>)aDelegate;



////////////////////////////////////////////////////////////////////////////////////////
// + unregisterLocationListenerDelegate:
//
/*!
 * The method remove the object that implements the IDNavigationDelegate protocol
 * @param   aDelegate object that implements the location delegation protocol
 */
+ (void)unregisterLocationListenerDelegate:(nullable id<IDLocationListener>)aDelegate;



////////////////////////////////////////////////////////////////////////////////////////
// + registerToConvertedLocationListenerWithDelegate:
//
/*!
 * The method add the object that implements the IDConvertedLocationListener protocol
 * @param   aDelegate object that implements the converted location delegation protocol
 */
+ (void)registerToConvertedLocationListenerWithDelegate:(nullable id<IDConvertedLocationListener>)aDelegate;



////////////////////////////////////////////////////////////////////////////////////////
// + unregisterConvertedLocationListenerDelegate:
//
/*!
 * The method remove the object that implements the IDConvertedLocationListener protocol
 * @param   aDelegate object that implements the converted location delegation protocol
 */
+ (void)unregisterConvertedLocationListenerDelegate:(nullable id<IDConvertedLocationListener>)aDelegate;


#pragma mark - Navigation & Simulation APIs

////////////////////////////////////////////////////////////////////////////////////////
// + setNavigationDelegate:
//
/*!
 * The method set the object that implements the IDNavigationDelegate protocol
 * @param   aDelegate object that implements the navigation delegation protocol
 */

+ (void)setNavigationDelegate:(nullable id<IDNavigationDelegate>)aDelegate;

/*!
 * The method is to set the Navigation distance info unit to meters/feet
 * @param isFeet YES/ NO default to NO;
 */
//this mode in order to load filtered instructions plist data.
+ (void)setNavigationDistanceUnitToFeet:(BOOL)isFeet;

/*!
 * The method is to set the Navigation simplified instruction status when the navigiation mode starts
 * @param aSimplifiedStatus YES/ NO default to NO;
 */
//this mode in order to load filtered instructions plist data.
+ (void)setNavigationSimplifiedInstructionStatus:(BOOL)aSimplifiedStatus;


////////////////////////////////////////////////////////////////////////////////////////
// + isDuringNavigation:
//
/*!
 * The method returns a is during navigation,
 * @return  BOOL value YES in case during navigation / NO otherwise
 */

+ (BOOL)isDuringNavigation;

////////////////////////////////////////////////////////////////////////////////////////
// + navigationDistanceUnitIsFeet:
//
/*!
 * The method returns a is distance info unit feet,
 * @return  BOOL value YES in case unit is feet / NO otherwise
 */
+ (BOOL)navigationDistanceUnitIsFeet;


////////////////////////////////////////////////////////////////////////////////////////
// + isDuringSimulation:
//
/*!
 * The method returns a is during navigation,
 * @return  BOOL value YES in case during simulation navigation / location  , NO otherwise
 */

+ (BOOL)isDuringSimulation;


////////////////////////////////////////////////////////////////////////////////////////
// + startNavigateToLocation:withOptions:andDelegate:
//
/*!
 * The method starts a navigation session to the destination location,
 * @param   aLocation destination location
 * @param   aNavigationOption navigation options
 * @param   aDelegate object that implements the navigation delegation protocol
 * @return  Success indication faile / succeeded
 * \code    [IDKit startNavigateToLocation:aPoi.location withOptions:kNavigationOptionRegular andDelegate:self];
 */

+ (BOOL)startNavigateToLocation:(IDLocation *_Nonnull)aLocation
                    withOptions:(IDNavigationOptions)aNavigationOption
                    andDelegate:(nullable id<IDNavigationDelegate>)aDelegate;


////////////////////////////////////////////////////////////////////////////////////////
// + startSimulationNavigationToLocation:fromLocation:withOptions:andDelegate:
//
/*!
 * The method starts a navigation simulation session to the destination location.
 * @param   aLocation destination location
 * @param   anOrigionLocation origion location
 * @param   aNavigationOption navigation options
 * @param   aDelegate object that implements the navigation delegation protocol
 * @return  Success indication faile / succeeded
 * \code    [IDKit startSimulationNavigationToLocation:aLocation
 fromLocation:[IDKit getUserLocation]
 withOptions:kNavigationOptionRegular
 andDelegate:self];
 */

+ (BOOL)startSimulationNavigationToLocation:(IDLocation *_Nonnull)aLocation
                               fromLocation:(IDLocation *_Nonnull)anOrigionLocation
                                withOptions:(IDNavigationOptions)aNavigationOption
                                andDelegate:(nullable id<IDNavigationDelegate>)aDelegate;


////////////////////////////////////////////////////////////////////////////////////////
// + startNavigateToLocations:withOptions:andDelegate:
//
/*!
 * The method starts a navigation session to multiple destinations locations
 * when arrive to destination location of the aLocations destinations Array
 * IDNavigationDelegate navigationArriveToLocation: Method will be called
 * @param   aLocations array of destinations locations
 * @param   aNavigationOption navigation options
 * @param   aDelegate object that implements the navigation delegation protocol
 * @return  Success indication faile / succeeded
 */

+ (BOOL)startNavigateToLocations:(NSArray <IDLocation *> *_Nonnull)aLocations
                     withOptions:(IDNavigationOptions)aNavigationOption
                     andDelegate:(nullable id<IDNavigationDelegate>)aDelegate;



////////////////////////////////////////////////////////////////////////////////////////
// + getCurrentNavigationRoute

+ (IDRoute * _Nullable)getCurrentNavigationRoute;

- (IDRoute * _Nullable)getNavigationRoute;

////////////////////////////////////////////////////////////////////////////////////////
// + startSimulationNavigationToLocations:withOptions:andDelegate:
//
/*!
 * The method starts a navigation simulation session to the destination location
 * when arrive to destination location of the aLocations destinations Array
 * IDNavigationDelegate navigationArriveToLocation: Method will be called.
 * @param   aDestLocations array of destination locations
 * @param   anOrigionLocation origion location
 * @param   aNavigationOption navigation options
 * @param   aDelegate object that implements the navigation delegation protocol
 * @return  Success indication faile / succeeded
 */

+ (BOOL)startSimulationNavigationToLocations:(NSArray <IDLocation *> *_Nonnull)aDestLocations
                                fromLocation:(IDLocation *_Nonnull)anOrigionLocation
                                 withOptions:(IDNavigationOptions)aNavigationOption
                                 andDelegate:(nullable id<IDNavigationDelegate>)aDelegate;


////////////////////////////////////////////////////////////////////////////////////////
// + continueWithLocations:
//
/*!
 * The method continue the navigation to the next (first object) location in the
 received array. That method is to be called after that arrive to location
 delegation method was call
 * @param   aLocations array of destinations locations to continue with
 * @return  Success indication faile / succeeded
 */

+ (BOOL)continueWithLocations:(NSArray <IDLocation *> *_Nonnull)aLocations;


////////////////////////////////////////////////////////////////////////////////////////
// + stopNavigation
//
/*!
 * The method stops the navigation session
 * @return  Success indication faile / succeeded
 */

+ (BOOL)stopNavigation;

////////////////////////////////////////////////////////////////////////////////////////
/*!
 * The method sets or removes the navigation markers
 * @param  show YES / NO
 */
+ (void) setShowNavigationMarkers:(BOOL)show;

/*!
 * The methods return YES, in case markers is enabled.
 * @return BOOL.
 */
+ (BOOL) getShowNavigationMarkers;

#pragma mark - Itinerary POIs APIs


////////////////////////////////////////////////////////////////////////////////////////
// + orderItineraryPoisList:addSwitchFloorsPois:addParkingPoi:
//
/*!
 * The method order a POI's destinations as best as it should be (from origin location of the user location if valid location, otherwise the first POI location).
 * @param   aPoisList array of pois destinations.
 * @param   addParking YES to add saved Parking location if exists.
 * in case USER LOCATION is Indoor and PARKING LOCATION EXISTS.
 The returned array will order Pois by USER LOCATION as origin location,
 the returned array will add Parking POI with exist PARKING LOCATION as last item.
 * in case user location is outdoor and PARKING LOCATION EXISTS,
 The returned array will order Pois by FIRST POI LOCATION as origin location.
 the returned array will add Parking Poi with exist PARKING LOCATION as FIRST and LAST item.
 * in case user location is outdoor and PARKING LOCATION NOT EXISTS,
 the returned array will be ordered by FIRST POI LOCATION as origin location.
 * @warning in case addParking YES added Parking Poi identifier isEqualToString:@"kParkingId"
 * @return  ordered Poi's by user Location.
 */
+ (NSArray <IDPoi *> *_Nonnull)orderItineraryPoisList:(NSArray <IDPoi *> *_Nonnull)aPoisList addSwitchFloorsPois:(BOOL)addSwitchFloors addParkingPoi:(BOOL)addParking;



////////////////////////////////////////////////////////////////////////////////////////
// + itineraryPoisList:addSwitchFloorsPois:addParkingPoi:
//
/*!
 * The method will add switch floors POIs if TRUE, and parking location as aprking POI if TRUE
 @param aPoisList IDPoi list
 @parap addSwitchFloors allow the method to add switch floors POIs if needed.
 @param addParking allow the method to add parking POI if needed.
 @return NSArray <IDPoi *> * with switch floors POIs and parking POI if TRUE.
 */
+ (NSArray <IDPoi *> *_Nonnull)itineraryPoisList:(NSArray <IDPoi *> *_Nonnull)aPoisList addSwitchFloorsPois:(BOOL)addSwitchFloors addParkingPoi:(BOOL)addParking;


#pragma mark - Geofences APIs


////////////////////////////////////////////////////////////////////////////////////////
// + getAllGeofencesList
//
/*!
 * The method returns all the cms geofence objects (IDGeofence) in array.
 * @return  array of IDGeofence objects
 */

+ (NSArray <IDGeofence *> *_Nonnull)getAllGeofencesList;

////////////////////////////////////////////////////////////////////////////////////////
// + registerForGeofenceTypes:withDelegate:
//
/*!
 * The method register the IDGeofenceDelegate delegate for custom geofences types.
 * @param   aTypes array of strings that represents the geofences types
 * @param   aDelegate object that implements the geofence delegation protocol
 * \code    [IDKit registerForGeofenceTypes:@[@"banner", @"Macy's"] withDelegate:self];
 */

+ (void)registerForGeofenceTypes:(NSArray <NSString *> *_Nonnull)aTypes withDelegate:(nullable id<IDGeofenceDelegate>)aDelegate;



////////////////////////////////////////////////////////////////////////////////////////
// + unRegisterForGeofenceTypes:withDelegate:
//
/*!
 * The method unregister the IDGeofenceDelegate delegate for custom geofences types.
 * @param   aTypes array of strings that represents the geofences types
 * @param   aDelegate object that implements the geofence delegation protocol
 * \code    [IDKit unRegisterForGeofenceTypes:@[@"bloomingdales"] withDelegate:self];
 */

+ (void)unRegisterForGeofenceTypes:(NSArray <NSString *> *_Nonnull)aTypes withDelegate:(nullable id<IDGeofenceDelegate> )aDelegate;


#pragma mark - ViewControllers APIs

////////////////////////////////////////////////////////////////////////////////////////
// + getMapViewController
//
/*!
 * The method returns the map container controller.
 * @return  Map map view controller
 */

+ (IDMapViewController *_Nonnull)getMapViewController;


////////////////////////////////////////////////////////////////////////////////////////
// + getDualMapViewController
//
/*!
 * The method returns the dual map container controller.
 * @return map view controller
 */
+ (IDDualMapViewController *_Nonnull)getDualMapViewController;

////////////////////////////////////////////////////////////////////////////////////////
// + getInstructionsController
//
/*!
 * The method returns the map container controller.
 * @return  Instractions controller
 */

+ (IDInstructionsViewController *_Nonnull)getInstructionsController;


#pragma mark - User Location APIs

////////////////////////////////////////////////////////////////////////////////////////
// + convertLocation:
//
/*!
 The method converts location from IDLocation Object to IDConvertedLocation Object.
 */
+ (IDConvertedLocation *_Nonnull)convertLocation:(IDLocation *_Nonnull)aLocation;


////////////////////////////////////////////////////////////////////////////////////////
// + getUserLocation
//
/*!
 * The method returns user location object.
 * @return  Location user location
 */

+ (IDUserLocation *_Nonnull)getUserLocation;

////////////////////////////////////////////////////////////////////////////////////////
// + setUserLocation:
//
/*!
 * The method sets the user location object. That location will be valid
 until the method is called with nil parameter.
 * @param   aUserLocation user location
 * \code    IDUserLocation* newLocation = [IDKit getUserLocation];
 newLocation.inCoordinate = CGPointMake(700, 700);
 newLocation.floorId = 0;
 [IDKit setUserLocation:newLocation];
 */

+ (void)setUserLocation:(IDUserLocation *_Nullable)aUserLocation;

////////////////////////////////////////////////////////////////////////////////////////
// + setCurrentUserLocation:
//
/*!
 * The method sets the current user location.
 [IDKit setCurrentUserLocation];
 */
+ (void)setCurrentUserLocation;


////////////////////////////////////////////////////////////////////////////////////////
// + setForceFixToUserLocation:
//
/*!
 * The method force a fix to the current user location object.
 * @param   aUserLocation user location
 * \code    IDUserLocation * fixedLocation = [IDKit getUserLocation];
 fixedLocation.floorId = 2;
 [IDKit setForceFixToUserLocation:fixedLocation];
 */

+ (void)setForceFixToUserLocation:(IDUserLocation *_Nonnull)aUserLocation;


////////////////////////////////////////////////////////////////////////////////////////
// + setForceFixToUserLocation:
//
/*!
 * The method checks if user locating in Campus.
 * @param   maxDistanceFromCampus this is max distance between current user location and campus location
 * if distance less then maxDistanceFromCampus, then user in the campus
 */

+ (BOOL)isUserInCampus:(NSInteger)maxDistanceFromCampus;

////////////////////////////////////////////////////////////////////////////////////////
// + getDistanceToPoi:
//
/*!
 * The calculates the distance between your location and the poi.
 * @param   poi that you want to get distance to
 * @param   location from you want to start distance calculation
 * @return  distance between two points
 */
+ (CLLocationDistance)getDistanceToPoi:(IDPoi *_Nonnull)poi fromLocation:(IDLocation *_Nonnull)location;

////////////////////////////////////////////////////////////////////////////////////////
// + getDistanceToPoiList:
//
/*!
 * The calculates the distance between your location and the list of pois.
 * @param   poiList that you want to get distance to
 * @param   location from you want to start distance calculation
 * @param   isSortedByDistance indicates if the result should be sorted by distance
 * @return  array of IDPoi objects with updated property poiDistance
 * this method returns the list of IDPoi instances, containing IDPoiDistance object.
 */
+ (NSArray <IDPoi *> *_Nonnull)getDistanceToPoiList:(NSArray *_Nonnull)poiList fromLocation:(IDLocation *_Nonnull)location sortedByDistance:(BOOL)isSortedByDistance;


#pragma mark - Parking APIs

////////////////////////////////////////////////////////////////////////////////////////
// + setParkingLocation:
//
/*!
 * The method set the location as parking location.
 * @param aLocation the location to set.
 */

+ (void)setParkingLocation:(IDLocation *_Nullable)aLocation;

////////////////////////////////////////////////////////////////////////////////////////
// + setCurrentLocationAsParking
//
/*!
 * The method set the current location as parking location.
 * @code use [setParkingLocation:[IDKit getUserLocation]]; @endcode
 */

+ (void)setCurrentLocationAsParking;


////////////////////////////////////////////////////////////////////////////////////////
// + getParkingLocation
//
/*!
 The method returns parking location. the returned location value is what you have saved.
 @return saved parking location.
 */

+ (IDLocation *_Nonnull)getParkingLocation;



////////////////////////////////////////////////////////////////////////////////////////
// + removeParkingLocation
//
/*!
 The method removes the parking location.
 */

+ (void)removeParkingLocation;


////////////////////////////////////////////////////////////////////////////////////////
// + getNearbyParkingForPoi:
//
/*!
 * The method returns closest parking Poi.
 * @param aPoi the current Poi.
 */

+ (IDPoi*_Nullable)getNearbyParkingForPoi:(IDPoi*_Nullable)aPoi;

#pragma mark - Campus, Facility & Floor Info APIs

////////////////////////////////////////////////////////////////////////////////////////
// + getCampusIDs
//
/*!
 * The method returns an array of campus id's.
 * @return  Array of all project campusses ids
 */

+ (NSArray <NSString *> *_Nonnull)getCampusIDs;


////////////////////////////////////////////////////////////////////////////////////////
// + getInfoForCampusWithID:
//
/*!
 * The method returns a dictionary with short information on the campus.
 * @param   aCampusId campus identifier string
 * @return  Information dictionary contaning information on provided campus id
 * \code  { @"location" of type CLLocation,
 @"subtitle" of type NSString,
 @"title" of type NSString,
 @"overlay" of type UIImage (if existed),
 @"perimeter"  of type NSDictionary {
 @"bottom_right_coordinate" of type CLLocation, @"top_left_coordinate" of type CLLocation}
 }
 */

+ (NSDictionary *_Nonnull)getInfoForCampusWithID:(NSString *_Nonnull)aCampusId;


////////////////////////////////////////////////////////////////////////////////////////
// + getFacilityIDsForCampusID:
//
/*!
 * The method returns an array of facility ids associated with the provided campus id.
 * @param   aCampusId campus identifier string
 * @return  Array array of facilits identifiers associated with the provided campus
 id
 */

+ (NSArray <NSString *> *_Nonnull)getFacilityIDsForCampusID:(NSString *_Nonnull)aCampusId;


////////////////////////////////////////////////////////////////////////////////////////
// + getInfoForFacilityWithID:atCmpusWithID:
//
/*!
 * The method returns a dictionary with short information of the facility at campus.
 * @param   aFacilityId facility identifier string
 * @param   aCampusId campus identifier string
 * @return  Information dictionary contaning information on refered facility
 @code {@"title": facility.title,
 @"subtitle": facility.subtitle,
 @"location": location,
 @"perimeter" : @{@"top_left_coordinate_lat": @(facility.upperLeftCoordinate.latitude),
 @"top_left_coordinate_lon": @(facility.upperLeftCoordinate.longitude),
 @"bottom_right_coordinate_lat": @(facility.lowerRightCoordinate.latitude),
 @"bottom_right_coordinate_lon": @(facility.lowerRightCoordinate.longitude)                    
 @"rot_angle": @(facility.rotationAngle),
 @"entrance_floor": @(facility.entranceFloor),
 @"floors_count": @(facility.floors.count)}
 */

+ (NSDictionary *_Nonnull)getInfoForFacilityWithID:(NSString *_Nonnull)aFacilityId
                             atCmpusWithID:(NSString *_Nonnull)aCampusId;


////////////////////////////////////////////////////////////////////////////////////////
// + getInfoForFloorID:inFacilityWithID:atCmpusWithID:
//
/*!
 * The method returns a dictionary with short information on the floor in facility at
 campus.
 * @param   aFloorId floor identifier integer
 * @param   aFacilityId facility identifier string
 * @param   aCampusId campus identifier string
 * @return  Information dictionary contaning information on refered floor
 * \code  { @"title" of type NSString,
 @"map" of type UIImage,
 @"gis" array of NSDictionary objects {@"start", @"end", @"angle"}
 }
 */

+ (NSDictionary *_Nonnull)getInfoForFloorID:(NSInteger)aFloorId
                   inFacilityWithID:(NSString *_Nonnull)aFacilityId
                      atCmpusWithID:(NSString *_Nonnull)aCampusId;


+ (NSArray *) getListOfProjectLocationsForCurrentAPIKey;

+ (NSArray *) getListOfProjectLocationsForAPIKey:(NSString*)apiKey;

#pragma mark - POIs Data & Sorting APIs

////////////////////////////////////////////////////////////////////////////////////////
// + getPOIsWithID:
//
/*!
 * The method returns array of IDPoi objects for each suitable founded poi.
 * @param   aPoiId string identifier for the required POI
 * @return  Array of IDPoi objects coresponds to the provided identifier
 * \code     [IDKit getPOIsWithID:@"campusId.facilityId"];
 */

+ (NSArray <IDPoi *> *_Nonnull)getPOIsWithID:(NSString *_Nonnull)aPoiId;


////////////////////////////////////////////////////////////////////////////////////////
// + sortPOIsAlphabeticallyWithPathID:
//
/*!
 * The method returns sorted array alphabetically of IDPoi objects for each suitable founded poi.
 * @param   aPathID string identifier for the required POI
 * @return  Array of IDPoi objects coresponds to the provided identifier
 * \code     [IDKit sortPOIsAlphabeticallyWithPathID:@"campusId.facilityId"];
 */

+ (NSArray <IDPoi *> *_Nonnull)sortPOIsAlphabeticallyWithPathID:(NSString *_Nonnull)aPathID;


////////////////////////////////////////////////////////////////////////////////////////
// + sortPOIsDistantlyWithPathID:fromLocation:
//
/*!
 * The method returns sorted array of IDPoi objects for each suitable fonded poi by distance of location.
 * @param   aPathID string identifier for the required POI
 * @param   aLocation the location to sort ditance from, in case the location was nil,
 the system will sort poi's by user location.
 * @return  Array of IDPoi objects coresponds to the provided identifier
 * \code     [IDKit sortPOIsDistantlyWithPathID:@"campusId.facilityId" fromLocation:nil];
 */

+ (NSArray <IDPoi *> *_Nonnull)sortPOIsDistantlyWithPathID:(NSString *_Nonnull)aPathID fromLocation:(IDLocation *_Nonnull)aLocation;


////////////////////////////////////////////////////////////////////////////////////////
// + sortPOIsDistantly:fromLocation:
//
/*!
 * The method returns sorted array of IDPoi objects for each suitable fonded poi by distance of location.
 * @param   aPOIs array of POIs
 * @param   aLocation the location to sort ditance from, in case the location was nil,
 the system will sort poi's by user location.
 * @return  Array of IDPoi objects sorted by distance
 */

+ (NSArray <IDPoi *> *_Nonnull)sortPOIsDistantly:(NSArray *_Nonnull)aPOIs fromLocation:(IDLocation *_Nonnull)aLocation;


////////////////////////////////////////////////////////////////////////////////////////
// + getPOIsWithCategories:atPathID:
//
/*!
 * The method returns array of IDPoi objects that holds the category string specified
 at the specified path id.
 * @param   aCategories array of strings that identify the category
 * @param   aPathID string that identify the association hierarchy of the POIs
 * @return  Array of founded IDPoi objects
 * \code    [IDKit getPOIsWithCategory:@[@"Services"] atPathID:@"campusId.facilityId"];
 */

+ (NSArray <IDPoi *> *_Nonnull)getPOIsWithCategories:(NSArray <NSString *> *_Nonnull)aCategories atPathID:(NSString *_Nonnull)aPathID;



////////////////////////////////////////////////////////////////////////////////////////
// + sortPOIsAlphabeticallyWithCategories:atPathID:
//
/*!
 * The method returns sorted array alphabetically of IDPoi objects that holds
 the categories strings specified at the specified path id.
 * @param   aCategories array of strings that identify the category
 * @param   aPathID string that identify the association hierarchy of the POIs
 * @return  Array of IDPoi objects coresponds to the provided identifier
 * \code    [IDKit sortPOIsAlphabeticallyWithCategories:@[@"Services"] atPathID:@"campusId.facilityId"];
 */

+ (NSArray <IDPoi *> *_Nonnull)sortPOIsAlphabeticallyWithCategories:(NSArray <NSString *> *_Nonnull)aCategories atPathID:(NSString *_Nonnull)aPathID;



////////////////////////////////////////////////////////////////////////////////////////
// + sortPOIsDistantlyWithCategories:atPathID:fromLocation
//
/*!
 * The method returns sorted array of IDPoi objects for each suitable fonded poi by distance of location.
 of IDPoi objects that holds the categories strings specified at the specified path id.
 * @param   aCategories array of strings that identify the category
 * @param   aPathID string that identify the association hierarchy of the POIs
 * @param   aLocation the location to sort ditance from, in case the location was nil,
 the system will sort poi's by user location.
 * @return  Array of IDPoi objects coresponds to the provided identifier
 * \code    [IDKit sortPOIsDistantlyWithCategoriesy:@[@"Services"] atPathID:@"campusId.facilityId" fromLocation:nil];
 */

+ (NSArray <IDPoi *> *_Nonnull)sortPOIsDistantlyWithCategories:(NSArray <NSString *> *_Nonnull)aCategories atPathID:(NSString *_Nonnull)aPathID fromLocation:(IDLocation *_Nonnull)aLocation;


////////////////////////////////////////////////////////////////////////////////////////
// + getPOIsCategoriesListForPathID:
//
/*!
 * The method associates the poi's categories in array with the object path set.
 * @param   aPathID string that identify the association hierarchy for the POIs
 * @code    [IDKit getPOIsCategoriesListForPathID:@"campusId.facilityId"];
 */
+ (NSArray <NSString *> *_Nonnull)getPOIsCategoriesListWithPathID:(NSString *_Nonnull)aPathID;

+ (NSArray <IDCategory *> *_Nonnull)getPOIsCategoriesWithFiltersListWithPathID:(NSString *_Nonnull)aPathID;


#pragma mark - Category Icons APIs

////////////////////////////////////////////////////////////////////////////////////////
// + getIconsKeysNamesList
//
/*!
 * Call This method in order to get all downloaded icons names.
 * @return  [NSString] list of all downloaded icons names.
 */
+ (NSArray <NSString *> *_Nonnull)getIconsKeysNamesList;



////////////////////////////////////////////////////////////////////////////////////////
// + didReceiveLocalNotification:
//
/*!
 * Call This method in order to get icon image for key of downloaded if exist.
 * @param aKeyName the icon image name;
 * @return UIImage image for keyName.
 */
+ (nullable UIImage *)getIconByKeyName:(NSString *_Nonnull)aKeyName;

#pragma mark - App Settings

////////////////////////////////////////////////////////////////////////////////////////
// + getDefaultAppSettings
//
/*!
 * Call This method in order to get downloaded settings for application.
 * @return  [NSDictionary] application settings.
 */
+ (nullable NSDictionary*)getDefaultAppSettings;

#pragma mark - Local Notification APIs

////////////////////////////////////////////////////////////////////////////////////////
// + didReceiveLocalNotification:
//
/*!
 * The method is to be calle from the implementation of the AppDelegate method
 didReceiveLocalNotification
 * @param   aNotification local notification object
 */

+ (void)didReceiveLocalNotification:(UILocalNotification *_Nonnull)aNotification;


////////////////////////////////////////////////////////////////////////////////////////
// + setLocalNotificationText:
//
/*!
 * The method is to be called to set the localNotification text
 * @param   aText the local notification text
 * \code    [IDKit setLocalNotificationText:@"welcome to the campus"];
 */
+ (void)setLocalNotificationText:(NSString *_Nonnull)aText;

#pragma mark - Languages APIs

////////////////////////////////////////////////////////////////////////////////////////
// + supportedLanguages:
//
/*!
 * The method returns array of strings for supported languages @[@"en", @"es", @"ch", etc...]
 * @return  array strings of supported languages
 */
+ (NSArray <NSString *> *_Nonnull)supportedLanguages;


////////////////////////////////////////////////////////////////////////////////////////
// + getCurrentLanguage:
//
/*!
 * The method returns The Indoor Kit current language,
 * @return  string The Indoor Kit current language like @"en", @"es", @"ch", etc...
 */
+ (NSString *_Nonnull)getCurrentLanguage;


////////////////////////////////////////////////////////////////////////////////////////
// + setCurrentLanguage:
//
/*!
 * The method is to be called to set The Indoor Kit current language,
 * some things can vary by the selected language, like poi's data, map labels if founded, etc...,
 * Then the map will reload all the pois on map by selected current language.
 * @param   aLanguage string that represent The Indoor Kit language @"en", @"es", @"ch", etc...
 * @return  YES if aLanguage supported
 * \code    [IDKit setCurrentLanguage:@"es"];
 */
+ (BOOL)setCurrentLanguage:( NSString *_Nonnull)aLanguage;


////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Zone Detection

////////////////////////////////////////////////////////////////////////////////////////
// + registerToZoneDetectionListenerWithDelegate:
//
/*!
 * to receive zone updates from a IDKit Zone Detector Manger.
 * @param aDelegate the IDZoneDetectionListener to add.
 * @return  Success indication register failed / succeeded
 */
+ (BOOL)registerToZoneDetectionListenerWithDelegate:(id<IDZoneDetectionListener> _Nullable)aDelegate;



////////////////////////////////////////////////////////////////////////////////////////
// + unregisterToZoneDetectionListenerWithDelegate:
//
/*!
 * to stop receiving zone updates from a IDKit Zone Detector Manger.
 * @param aDelegate the IDZoneDetectionListener to aremove.
 * @return  Success indication unregister failed / succeeded
 */
+ (BOOL)unregisterToZoneDetectionListenerWithDelegate:(id<IDZoneDetectionListener> _Nullable)aDelegate;



////////////////////////////////////////////////////////////////////////////////////////
// + startZoneDetection
//
/*!
 * to start the IDKit Zone Detector Manger zone updates.
 * @return  Success indication of start detection session failed / succeeded
 */
+ (BOOL)startZoneDetection;


////////////////////////////////////////////////////////////////////////////////////////
// + startInitialZoneDetection
//
/*!
 * to start the IDKit Zone Detector Manger initial zone updates.
 */
+ (void)startInitialZoneDetection;


////////////////////////////////////////////////////////////////////////////////////////
// + stopZoneDetection
//
/*!
 * to stop the IDKit Zone Detector Manger initial zone updates.
 */
+ (void)stopZoneDetection;


////////////////////////////////////////////////////////////////////////////////////////
// + setZoneStatus
//
/*!
 * to change the IDKit Zone Detector Manger current zone.
 * @note this change will be active until the IDKit Zone Detector Manger detects a Zone change
 */
+ (void)setZoneStatus:(IDZoneStatus)aZoneStatus;



////////////////////////////////////////////////////////////////////////////////////////
// + getTheftProtectionState
//
/*!
 * if the BLE scanner filtered Beacons that belongs as the project BLE devices IDs List.
 * @return true in case the filtered devices count > the project exit facility param, otherwise false.
 */
+ (BOOL)getTheftProtectionState;

////////////////////////////////////////////////////////////////////////////////////////
// + getMaxVenueIdFloorsCountAtCampusId
//
/*!
 * search for the venue with max number of floors.
 * @param campusId the IDZoneDetectionListener to aremove.
 * @return the venue Id that has the max number of floors
 */
+ (NSString* _Nonnull) getMaxVenueIdFloorsCountAtCampusId:(NSString *_Nullable)campusId;

+ (void)setLowPowerMode:(BOOL)lowPowerMode;


////////////////////////////////////////////////////////////////////////////////////////
// + setDefaultUserLocation
//

/*!
 * The method sets the user default location.
 * @param coordinates is the CLLocationCoordinate2D type.
 */
+ (void)setDefaultUserLocation:(CLLocationCoordinate2D)coordinates;

/*!
 * The method sets  the DisplayUserLocationIcon
 * @param dispayUserLocationIcon is the BOOL type.
 */
+ (void)setDisplayUserLocationIcon:(BOOL)dispayUserLocationIcon;

/*!
 * The method sets  the custom user location icon
 * @param userLocationIcon is the BOOL type.
 */
+ (void)setCustomUserLocationIcon:(UIImage *_Nullable)userLocationIcon;

/*!
 * The method returns the  user location icon.
 * @return UIImage .
 */
+ (UIImage *_Nullable)getCustomUserLocationIcon;

/*!
 * The method returns the project location type.
 * @return projectLocationType is the IDProjectLocationType .
 */

+ (IDProjectLocationType)getProjectLocationType;

/*!
 * The method sets the project location type.
 * @param aProjectLocationType is the IDProjectLocationType .
 */

+ (void)setProjectLocationType:(IDProjectLocationType)aProjectLocationType;

/*!
 * The method save the server url.
 * @param serverURL is the NSString type.
 */
+ (void)setServerURL:(NSString *_Nullable)serverURL;

/*!
 * The method returns the saved server url.
 * @return NSString.
 */
+ (NSString *_Nullable)getServerURL;

/*!
 * The method checks the availability of the location services
 * @return BOOL
 */
+ (BOOL)locationServicesEnabled;

/*!
 * The method returns the saved project id.
 * @return NSString.
 */
+ (NSString *_Nullable)getProjectId;

#pragma mark - Custom markers

// + addCustomMarkersWithPOIs:pois
//
/*!
 * The method will add custom markers
 @param aPOIs IDPoi list
 * @return NSArray.
 */
+ (NSArray*_Nonnull)addCustomMarkersWithPOIs:(NSArray*_Nonnull)aPOIs;

// + showCustomMarkersWithIds:markersIds
//
/*!
 * The method will show markers on the map
 * If markersIds = nil will show all exist custom markers
 @param markersIds markers identifiers list
 */
+ (void)showCustomMarkersWithIds:(NSArray*_Nullable)markersIds;

// + IDFriendManager : Update Friend, Remove All Friends
+ (void)updateFriends:(NSArray *_Nullable)frds;
+ (void)removeFriends:(NSArray *_Nullable)frds;
+ (void)removeFriend:(IDFriend*_Nonnull)frd;
+ (void)getFriendsForFloorId:(NSInteger)floorId;
+ (void)showAllFriends;
+ (void)hideAllFriends;
+ (void)removeAllFriends;
+ (void)showFriendsForFloorId:(NSInteger)floorId;
/*!
 * The method will add/remove Friend markers
 */

// + removeCustomMarkersWithIds:markersIds
//
/*!
 * The method will remove markers from the map
 * If markersIds = nil will remove all exist custom markers
 @param markersIds markers identifiers list
 */
+ (void)removeCustomMarkersWithIds:(NSArray*_Nullable)markersIds;

+ (void)addCustomPois:(NSArray *_Nullable)pois;
+ (void)removeCustomPois:(NSArray *_Nullable)pois;
+ (NSArray *_Nonnull)allCustomPois;
+ (void)setClusterLabel:(BOOL)aMode;



/*!
 * When it's turned on, Navigation route line will show dashed/dotted
 */
+ (void)setDashedRoute:(BOOL)aMode;
+ (void)setDictionaryForMultiPoints:(BOOL)aMode;
+ (void)setForceStop:(BOOL)forceStop;
+ (void)setColorForRoute:(UIColor*)aColor;
+ (void)setStrokeWidthForRoute:(int)aWidth;




@end
