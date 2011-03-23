//
//  CEPubnubRequest.m
//  PubNubLib
//
//  Created by Chad Etzel on 3/21/11.
//  Copyright 2011 Phrygian Labs, Inc. All rights reserved.
//

#import "CEPubnubRequest.h"




@implementation CEPubnubRequest

@synthesize response, connection;

-(void)
scheme:   (NSString*) scheme
host:     (NSString*) host
path:     (NSString*) path
callback: (CEPubnubResponse*) callback;
{
    //pool     = [[NSAutoreleasePool alloc] init];
	response = nil;
	receivedData = [[NSMutableData alloc] initWithLength:0];
	
    delegate = callback;
	[delegate retain];
	//NSLog(@"callback retainCount: %d", [delegate retainCount]);
	
    NSURL *url = [NSURL
				  URLWithString: [NSString
								  stringWithFormat: @"%@://%@%@",
								  scheme,
								  host,
								  path
								  ]
				  ];
	
		
    NSMutableURLRequest *request = [NSMutableURLRequest
									requestWithURL:  url 
									cachePolicy:     NSURLRequestReloadIgnoringCacheData 
									timeoutInterval: 200
									];
    [request setValue:@"close" forHTTPHeaderField:@"Connection"];
    [request setValue:@"Accept-Encoding" forHTTPHeaderField:@"gzip"];
    connection = [[NSURLConnection alloc]
				  initWithRequest:  request
				  delegate:         self
				  ];
	
    
}

-(void)
connection:     (NSURLConnection*) aConnection
didReceiveData: (NSData*) data
{
	[receivedData appendData:data];
	
}

-(void)
connectionDidFinishLoading: (NSURLConnection *) aConnection
{
	response = [[NSString alloc]
				initWithData: receivedData
				encoding: NSUTF8StringEncoding
				];
	
    [delegate callback: response];
	[delegate release];
	delegate = nil;
	
}

-(void)
connection:       (NSURLConnection*) connection
didFailWithError: (NSError *) error
{
	
    [delegate fail: response];
	[delegate release];
	delegate = nil;
	
}

- (void) dealloc 
{
	//NSLog(@"CALLING DEALLOC of CEPubnubRequest!!");
	if (delegate) {
		[delegate release];
	}
	if (response) {
		[response release];
	}
	[receivedData release];
	[connection release];
	[super dealloc];
}

@end

@implementation CEPubnubResponse

@synthesize parser, pubnub, channel;

-(CEPubnubResponse *)
finished: (id)      callback
pubnub:   (CEPubnub*) pubnub_o
{
    self     = [super init];
    delegate = callback;
    parser   = [SBJsonParser new];
    [self setPubnub:pubnub_o];
	channel  = nil;
    return self;
}


-(CEPubnubResponse *)
finished: (id)        callback
pubnub:   (CEPubnub*)   pubnub_o
channel:  (NSString*) channel_o
{
    self     = [super init];
    delegate = callback;
    parser   = [SBJsonParser new];
    //pubnub   = pubnub_o;
	[self setPubnub:pubnub_o];
    channel  = channel_o;
    return self;
}


-(CEPubnubResponse *)
pubnub:   (CEPubnub*)   pubnub_o
channel:  (NSString*) channel_o
{
    self     = [super init];
    delegate = nil;
    parser   = [SBJsonParser new];
    //pubnub   = pubnub_o;
	[self setPubnub:pubnub_o];
    channel  = channel_o;
    return self;
}


-(void) callback: (id) response {
    //[delegate callback: [parser objectWithString: response]];
	logit(@"x");
	//override in subclass
	/*
	if (delegate) {
		logit(@"calling delegate!");
		[delegate pubub:pubnub subscriptionDidReceiveObject:response onChannel:channel];
	}
	 */
}


-(void) fail: (id) response {
    //[delegate fail: response];
	logit(@"x");
	// override in subclass
	/*
	if (delegate) {
		logit(@"calling delegate fail");
		[delegate pubnub:pubnub subscriptionDidFailWithResponse:response onChannel:channel];
	}
	 */
}


-(void) dealloc
{
	//NSLog(@"CALLING DEALLOC!!");
	if (parser) {
		[parser release];
	}
	if (pubnub) {
		[pubnub release];
		pubnub = nil;
	}
	//[channel release];
	
	[super dealloc];
}

@end


