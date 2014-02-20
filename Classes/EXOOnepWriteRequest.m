//
//  EXOOnepWriteRequest.m
//
//  Created by Michael Conrad Tadpol Tilstra.
//  Copyright (c) 2014 Exosite. All rights reserved.
//

#import "EXOOnepWriteRequest.h"

@interface EXOOnepWriteRequest ()
@property(nonatomic,strong) id value;
@property(nonatomic,copy) EXOOnepRequestComplete complete;
@end

@implementation EXOOnepWriteRequest

+ (EXOOnepWriteRequest *)writeWithRID:(EXOOnepResourceID *)rid string:(NSString *)value complete:(EXOOnepRequestComplete)complete
{
    return [[EXOOnepWriteRequest alloc] initWithRID:rid value:value complete:complete];
}

+ (EXOOnepWriteRequest *)writeWithRID:(EXOOnepResourceID *)rid number:(NSNumber *)value complete:(EXOOnepRequestComplete)complete
{
    return [[EXOOnepWriteRequest alloc] initWithRID:rid value:value complete:complete];
}

- (instancetype)initWithRID:(EXOOnepResourceID *)rid value:(id)value complete:(EXOOnepRequestComplete)complete
{
    if (self = [super init]) {
        self.rid = rid;
        self.value = value;
        self.complete = complete;
    }
    return self;
}

- (id)init
{
    return nil;
}

- (void)doResult:(NSDictionary *)result error:(NSError *)error
{
    if (self.complete) {
        NSError *err = [self errorFromStatus:result];
        if (err) {
            self.complete(err);
        } else {
            self.complete(nil);
        }
    }
}

- (NSDictionary *)asCall
{
    return @{@"procedure": @"write", @"arguments": @[[self.rid asCall], [self.value stringValue]]};
}

- (id)copyWithZone:(NSZone *)zone
{
    return self;
}

@end
