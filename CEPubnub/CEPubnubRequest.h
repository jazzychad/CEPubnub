//
//  CEPubnubRequest.h
//  PubNubLib
//
//  Created by Chad Etzel on 3/21/11.
//  Copyright 2011 Phrygian Labs, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>


#import "JSON.h"

#import "CEPubnubDelegate.h"

@class CEPubnub;

@interface CEPubnubResponse: NSObject {
    id <CEPubnubDelegate> delegate;
    SBJsonParser* parser;
    CEPubnub* pubnub;
    NSString* channel;
	
}

@property (nonatomic, retain) SBJsonParser *parser;
@property (nonatomic, retain) CEPubnub *pubnub;
@property (nonatomic, copy) NSString *channel;


-(CEPubnubResponse *)
finished: (id)        callback
pubnub:   (CEPubnub*)   pubnub_o;

-(CEPubnubResponse *)
finished: (id)        callback
pubnub:   (CEPubnub*)   pubnub_o
channel:  (NSString*) channel_o;

-(CEPubnubResponse *)
pubnub:  (CEPubnub*)   pubnub_o
channel: (NSString*) channel_o;

-(void)      callback: (id) response;
-(void)      fail:     (id) response;
@end





//CEPubnubRequest

@interface CEPubnubRequest: NSObject {
    id delegate;
	
    NSString *response;
	NSURLConnection *connection;
    //NSAutoreleasePool *pool;
	
@private
	NSMutableData *receivedData;
}

@property (nonatomic, copy) NSString *response;
@property (nonatomic, retain) NSURLConnection *connection;

-(void)
scheme:   (NSString*) scheme
host:     (NSString*) host
path:     (NSString*) path
callback: (CEPubnubResponse *) callback;
@end

