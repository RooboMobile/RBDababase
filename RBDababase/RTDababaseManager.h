//
//  RTDababaseManager.h
//  Pods
//
//  Created by baxiang on 2017/10/18.
//

#import <Foundation/Foundation.h>
#import "RBUserModel.h"



#define RT_DEFAULT_NAME @"RBStoryToy"
#define RTDBManager [RTDababaseManager shareManager:RT_DEFAULT_NAME]
@interface RTDababaseManager : NSObject
+ (instancetype)shareManager:(NSString *)dbName;
-(void)insertUser:(RBUserModel*)model;
@end
