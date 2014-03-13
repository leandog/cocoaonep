//
//  EXOOnepCreateDataportRequest.h
//
//  Created by Michael Conrad Tadpol Tilstra.
//  Copyright (c) 2014 Exosite. All rights reserved.
//

#import "EXOOnepResource.h"

enum EXOOnepDataportFormat_e {
    EXOOnepDataportFormatString = 0,
    EXOOnepDataportFormatFloat,
    EXOOnepDataportFormatInteger,
};
typedef enum EXOOnepDataportFormat_e EXOOnepDataportFormat_t;

@interface EXOOnepDataportResource : EXOOnepResource
@property(assign) EXOOnepDataportFormat_t format;
@property(strong) NSArray *preprocess;
@property(strong) EXOOnepResourceID *subscribe;
@property(copy) NSNumber *retentionCount;
@property(copy) NSNumber *retentionDuration;

@end