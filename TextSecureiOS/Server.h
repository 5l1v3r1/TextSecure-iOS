//
//  Server.h
//  TextSecureiOS
//
//  Created by Christine Corbett Moran on 3/24/13.
//  Copyright (c) 2013 Open Whisper Systems. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Constants.h"
//curl -X POST --header "Content-Length: 0" https://textsecure-gcm.appspot.com/v1/accounts/+41799624499
//curl -X PUT -i -H "Content-Type:application/json" --data "{\"verificationCode\" : \"958525159\", \"authenticationToken\" :\"123456\" , \"gcmRegistrationId\" : \"12345678\"}" https://textsecure-gcm.appspot.com/v1/accounts/+41799624499
@interface Server : NSObject {
	
}
@property (nonatomic,strong) NSMutableData *receivedData;
@property (nonatomic,strong) NSMutableArray *requestQueue;
@property (nonatomic,strong) NSString *number;
@property (nonatomic) int currentRequest;
#pragma mark -
#pragma mark server request queue methods
-(void) doNextRequest;
-(void) pushSecureRequest:(NSString*) request;

-(NSURL*) createRequestURL:(NSString*)requestStr withServer:(NSString*)server withAPI:(NSString*) api;
-(void) serverAuthenticatedRequest:(NSURL*)requestUrl withData:(NSData*)requestData requestType:(NSString*)method;
-(void) serverEmptyPost:(NSURL*)requestUrl;
-(void) serverPut:(NSURL*)requestUrl withData:(NSData*)requestData;
#pragma mark -
#pragma mark TextSecure verbs
- (NSData*) jsonDataFromDict:(NSDictionary*)parameters;
-(void) doCreateAccount:(NSNotification*) notification;
-(void) doVerifyAccount:(NSNotification*) notification;
-(void) doSendAPN:(NSNotification *)notification;

#pragma mark -
#pragma mark connection delegate methods
-(void) connection:(NSURLConnection*)connection didReceiveData:(NSData*)data;
- (void)connectionDidFinishLoading:(NSURLConnection *)connection;
@end
