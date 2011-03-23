//
//  CEPubnub.h
//  PubNubLib
//
//  Created by Chad Etzel on 3/21/11.
//  Copyright 2011 Phrygian Labs, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "JSON.h"
#import "CEPubnubRequest.h"

@interface CEPubnub : NSObject {
    NSString* publish_key;
    NSString* subscribe_key;
    NSString* secret_key;
    NSString* scheme;
    NSString* host;
    NSMutableDictionary* subscriptions;
    SBJsonParser* parser;
    SBJsonWriter* writer;
}

@property (nonatomic, copy) NSString *publish_key;
@property (nonatomic, copy) NSString *subscribe_key;
@property (nonatomic, copy) NSString *secret_key;
@property (nonatomic, copy) NSString *scheme;
@property (nonatomic, copy) NSString *host;
@property (nonatomic, retain) NSMutableDictionary *subscriptions;
@property (nonatomic, retain) SBJsonParser *parser;
@property (nonatomic, retain) SBJsonWriter *writer;

-(CEPubnub*)
	publishKey:   (NSString*) pub_key
	subscribeKey: (NSString*) sub_key
	secretKey:    (NSString*) sec_key
	sslOn:        (BOOL)      ssl_on
	origin:       (NSString*) origin;

-(void)
	publish:  (NSString*) channel
	message:  (id)        message
	delegate: (id)        delegate;

-(void)
	subscribe: (NSString*) channel
	delegate:  (id)        delegate;

-(void) subscribe: (NSDictionary*) args;
-(BOOL) subscribed: (NSString*) channel;

-(void)
	history:  (NSString*) channel
	limit:    (int)       limit
	delegate: (id)        delegate;

-(void) unsubscribe: (NSString*) channel;
-(void) time: (id) delegate;
-(void) shutdown;
@end

@interface CEPubnubSubscribeDelegate: CEPubnubResponse @end
@interface CEPubnubHistoryDelegate: CEPubnubResponse @end
@interface CEPubnubPublishDelegate: CEPubnubResponse @end
@interface CEPubnubTimeDelegate:      CEPubnubResponse @end

