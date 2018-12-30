//
//  IDFriendManager.h
//  IndoorKit
//
//  Created by Spreo on 2/26/18.
//  Copyright © 2018 Spreo LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

@class IDFriend;

@interface IDFriendManager : NSObject

+ (instancetype _Nonnull)defaultManager;
- (void)updateFriends:(NSArray<IDFriend *> *_Nullable)frd;
- (void)removeFriends:(NSArray<IDFriend *> *_Nullable)frd;
- (void)removeAllFriends;
- (void)removeFriend:(IDFriend *_Nullable)frd;
- (void)showAllFriends;
- (void)hideAllFriends;
- (void)showFriendsForFloorId:(NSInteger)floorId;
- (NSArray<IDFriend *> *_Nonnull)allFriends;
- (NSArray*_Nonnull)getFriendsForFloorId:(NSInteger)floorId;

@end


