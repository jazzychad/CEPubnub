//
//  CEPubnubDelegate.h
//  PubNubLib
//
//  Created by Chad Etzel on 3/21/11.
//  Copyright 2011 Phrygian Labs, Inc. All rights reserved.
//

#import <UIKit/UIKit.h>

@class CEPubnub;

@protocol CEPubnubDelegate <NSObject>

@optional
- (void)pubnub:(CEPubnub *)pubnub subscriptionDidReceiveDictionary:(NSDictionary *)response onChannel:(NSString *)channel;
- (void)pubnub:(CEPubnub *)pubnub subscriptionDidReceiveArray:(NSArray *)response onChannel:(NSString *)channel;
- (void)pubnub:(CEPubnub *)pubnub subscriptionDidReceiveString:(NSString *)response onChannel:(NSString *)channel;
- (void)pubnub:(CEPubnub *)pubnub subscriptionDidFailWithResponse:(NSString *)response onChannel:(NSString *)channel;

- (void)pubnub:(CEPubnub *)pubnub subscriptionDidReceiveHistoryArray:(NSArray *)response onChannel:(NSString *)channel;

- (void)pubnub:(CEPubnub *)pubnub publishDidSucceedWithResponse:(NSString *)response onChannel:(NSString *)channel;
- (void)pubnub:(CEPubnub *)pubnub publishDidFailWithResponse:(NSString *)response onChannel:(NSString *)channel;

- (void)pubnub:(CEPubnub *)pubnub didReceiveTime:(NSString *)timestamp;



@end
