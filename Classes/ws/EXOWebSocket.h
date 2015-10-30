//
//  EXOWebSocket.h
//  Pods
//
//  Created by Michael Conrad Tadpol Tilstra on 10/29/15.
//
//

#import <Foundation/Foundation.h>
#import "EXORpcActivateRequest.h"
#import "EXORpcAuthKey.h"
#import "EXORpcClientResource.h"
#import "EXORpcCloneResource.h"
#import "EXORpcCreateRequest.h"
#import "EXORpcDataportResource.h"
#import "EXORpcDataruleResource.h"
#import "EXORpcDispatchResource.h"
#import "EXORpcDeactivateRequest.h"
#import "EXORpcDropRequest.h"
#import "EXORpcFlushRequest.h"
#import "EXORpcInfoRequest.h"
#import "EXORpcListingRequest.h"
#import "EXORpcLookupRequest.h"
#import "EXORpcMapRequest.h"
#import "EXORpcReadRequest.h"
#import "EXORpcRecordRequest.h"
#import "EXORpcRevokeRequest.h"
#import "EXORpcShareRequest.h"
#import "EXORpcUnmapRequest.h"
#import "EXORpcUpdateRequest.h"
#import "EXORpcUsageRequest.h"
#import "EXORpcValue.h"
#import "EXORpcWaitRequest.h"
#import "EXORpcWriteRequest.h"

NS_ASSUME_NONNULL_BEGIN
/**
 Key for Errors specific to EXOWebSocket.
 */
extern NSString *EXOWebSocketErrorDomain;

/**
 EXORpc error codes
 */
typedef NS_ENUM(NSInteger, EXOWebSocketError) {
    EXOWebSocketError_UnknownResponse = -1,
    EXOWebSocketError_MissingAuthKey = -2,
    EXOWebSocketError_NoRequests = -3,
};

/**
 Callback for the completion of a RPC exchange

 @param err If not nil, then the error generated by the failed network calls
 */
typedef void(^EXOWebSocketComplete)(NSError * __nullable error);


/**
 * The WebSocket
 */
@interface EXOWebSocket : NSObject

/**
 Which base URL is being used for the One Platform requests.
 */
@property(nonatomic,copy,readonly) NSURL *domain;

@property (copy,nonatomic,readonly) EXORpcAuthKey* auth;
/**
 Initialize a One Platform WebSocket object with a specific domain.

 @param auth The authentication for this websocket
 @param domain Which base URL to use for the API requests. Passing nil uses the default.

 @return The WebSocket object
 */
- (instancetype)initWithAuth:(EXORpcAuthKey*)auth domain:(nullable NSURL *)domain NS_DESIGNATED_INITIALIZER;

/**
 Initialize a One Platform WebSocket object with a specific domain.

 @param auth The authentication for this websocket

 @return The WebSocket object
 */
- (instancetype)initWithAuth:(EXORpcAuthKey*)auth;

@end

NS_ASSUME_NONNULL_END
