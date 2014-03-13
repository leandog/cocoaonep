//
//  EXORpc.h
//
//  Created by Michael Conrad Tadpol Tilstra.
//  Copyright (c) 2014 Exosite. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "EXORpcAuthKey.h"
#import "EXORpcReadRequest.h"
#import "EXORpcWriteRequest.h"
#import "EXORpcActivateRequest.h"
#import "EXORpcClientResource.h"
#import "EXORpcDataportResource.h"
#import "EXORpcDataruleResource.h"
#import "EXORpcDispatchResource.h"
#import "EXORpcCloneResource.h"
#import "EXORpcDeactivateRequest.h"
#import "EXORpcDropRequest.h"
#import "EXORpcFlushRequest.h"
#import "EXORpcInfoRequest.h"
#import "EXORpcListingRequest.h"
#import "EXORpcLookupRequest.h"
#import "EXORpcMapRequest.h"
#import "EXORpcRecordRequest.h"
#import "EXORpcRevokeRequest.h"
#import "EXORpcShareRequest.h"
#import "EXORpcUnmapRequest.h"
#import "EXORpcUpdateRequest.h"
#import "EXORpcUsageRequest.h"

extern NSString *EXORpcDeviceErrorDomain;

typedef void(^EXORpcRPCComplete)(NSError*err);

@interface EXORpc : NSObject
@property(nonatomic,copy,readonly) NSURL *host;
@property(nonatomic,strong) NSOperationQueue *queue;
@property(nonatomic,copy) EXORpcAuthKey *auth;

+ (EXORpc*)rpc;
+ (EXORpc*)rpcWithHost:(NSURL*)host;

- (instancetype)initWithAuth:(EXORpcAuthKey *)auth Host:(NSURL *)host;

- (void)doRPCwithRequests:(NSArray*)calls complete:(EXORpcRPCComplete)complete;
- (void)doRPCwithAuth:(EXORpcAuthKey*)auth requests:(NSArray*)calls complete:(EXORpcRPCComplete)complete;

- (NSOperation *)operationWithAuth:(EXORpcAuthKey *)auth requests:(NSArray *)calls complete:(EXORpcRPCComplete)complete;

@end