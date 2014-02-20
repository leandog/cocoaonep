//
//  EXOOnepDataruleCount.m
//
//  Created by Michael Conrad Tadpol Tilstra.
//  Copyright (c) 2014 Exosite. All rights reserved.
//

#import "EXOOnepDataruleCount.h"

@interface EXOOnepDataruleCount ()
@property(nonatomic,assign) EXOOnepDataruleComparison_t comparison;
@property(nonatomic,copy) NSNumber *constant;
@property(nonatomic,copy) NSNumber *count;
@property(nonatomic,copy) NSNumber *timeout;
@property(nonatomic,assign) BOOL repeat;
@end

@implementation EXOOnepDataruleCount

+ (EXOOnepDataruleCount *)dataruleCountWithCompare:(EXOOnepDataruleComparison_t)comparison constant:(NSNumber *)constant count:(NSNumber*)count timeout:(NSNumber *)timeout repeat:(BOOL)repeat
{
    return [[EXOOnepDataruleCount alloc] initWithCompare:comparison constant:constant count:count timeout:timeout repeat:repeat];
}

- (id)initWithCompare:(EXOOnepDataruleComparison_t)comparison constant:(NSNumber *)constant count:(NSNumber*)count timeout:(NSNumber *)timeout repeat:(BOOL)repeat
{
    if (self = [super init]) {
        self.comparison = comparison;
        self.constant = constant;
        self.timeout = timeout;
        self.repeat = repeat;
    }
    return self;
}

- (id)init
{
    return nil;
}

- (NSDictionary *)plistValue
{
    return @{@"count": @{@"comparison": [self stringFromComparison:self.comparison], @"constant": self.constant, @"count": self.count, @"timeout": self.timeout, @"repeat": self.repeat?@"true":@"false"}};
}

- (BOOL)isEqual:(id)object
{
    if (![object isKindOfClass:[self class]]) {
        return NO;
    }
    EXOOnepDataruleCount *obj = object;
    return (self.comparison == obj.comparison &&
            [self.constant isEqualToNumber:obj.constant] &&
            [self.timeout isEqualToNumber:obj.timeout] &&
            [self.count isEqualToNumber:obj.count] &&
            self.repeat == obj.repeat
            );
}

- (NSUInteger)hash
{
    return self.comparison ^ self.constant.hash ^ self.timeout.hash ^ self.count.hash ^ self.repeat;
}

@end
