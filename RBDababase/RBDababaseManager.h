//
//  RBFMDB.h
//  Pods
//
//  Created by baxiang on 2017/10/17.
//

#import <Foundation/Foundation.h>

@interface RBDababaseManager : NSObject
/**
 *  @author gitKong
 *
 *  单例创建，项目唯一
 */
+ (instancetype)shareManager:(NSString *)dbName;

#pragma mark -- 创表

/**
 *
 *  根据类名创建表，如果有则跳过，没有才创建
 
 *  flag：YES表示创建表格操作执行成功 或者 表格已经存在，NO则失败
 
 *  注意：此方法创建表格后不会自动关闭数据库，当开发者执行其他操作（删除数据库除外）后会自动关闭数据库
 
 *  建议使用insert创建表格并添加数据
 */
- (void)createTable:(Class)modelClass complete:(void(^)(BOOL flag))complete;


#pragma mark -- 插入

/**
 *
 *
 *  @param model 插入单个模型或者模型数组,如果此时传入的模型对应的FLDBID在表中已经存在，则替换更新旧的
 
 *  flag：YES表示插入数据操作执行成功，NO则失败
 
 *  注意：如果此时没创建表就自动先创建，表名为模型类名，数据插入完毕后会自动关闭数据库
 
 *  建议直接使用insert创建表格并添加数据，因为create方法执行完不会自动关闭数据库
 */
- (void)insertModel:(id)model complete:(void(^)( BOOL flag))complete;

#pragma mark -- 查询

/**
 *  查询指定表是否存在
 
 *  flag：YES表示操作执行成功并且 modelClass 表格存在，NO则操作失败或者 modelClass 表格不存在
 
 *  注意：操作执行完毕会自动关闭数据库
 */
- (void)isExitTable:(Class)modelClass complete:(void(^)( BOOL flag))complete;
/**
 *
 *
 *  查找指定表中指定DBID的模型
 
 *  model：不等于nil，表示查询数据操作执行成功并有数据，返回查询成功的模型数据，nil则表示查询操作失败 或者 查询成功但数据为空 或者 对应的表格不存在
 
 *  注意：操作执行完毕会自动关闭数据库
 */
- (void)searchModel:(Class)modelClass byID:(NSString *)FLDBID complete:(void(^)(id model))complete;
/**
 *
 *  查找指定表中模型数组（所有的）
 
 *  modelArr：不等于nil，表示查询数据操作执行成功并有数据，返回查询成功的模型数据，nil则表示查询操作失败 或者 查询成功但数据为空 或者 对应的表格不存在
 
 *  注意：操作执行完毕会自动关闭数据库
 */
- (void)searchModelArr:(Class)modelClass complete:(void(^)(NSArray *modelArr))complete;

#pragma mark -- 修改

/**
 *  修改指定DBID的模型
 
 *  flag：YES表示更新操作执行成功，NO则操作失败 或者 对应的表格不存在
 
 *  注意：操作执行完毕会自动关闭数据库
 */

- (void)modifyModel:(id)model byID:(NSString *)FLDBID complete:(void(^)(BOOL flag))complete;


#pragma mark -- 删除
/**
 *  删除指定表
 
 *  flag：YES表示删除操作执行成功，NO则操作失败 或者 对应的表格不存在
 
 *  注意：操作执行完毕会自动关闭数据库
 */
- (void)dropTable:(Class)modelClass complete:(void(^)(BOOL flag))complete;
/**
 *
 *  删除数据库
 *  注意：操作不涉及到数据库操作，如果你通过create创建后执行此操作，不会关闭数据库
 
 *  @return YES 表示删除成功，NO则删除失败
 */
- (BOOL)dropDB;
/**
 *
 *  删除指定表格的所有数据
 
 *  flag：YES表示删除操作执行成功，NO则操作失败 或者 对应的表格不存在 或者 没有对应数据可以删除
 
 *  注意：操作执行完毕会自动关闭数据库
 */
- (void)deleteAllModel:(Class)modelClass complete:(void(^)(BOOL flag))complete;

/**
 *  删除指定表中指定DBID的模型
 
 *  flag：YES表示删除操作执行成功，NO则操作失败 或者 对应的表格不存在 或者 没有对应数据可以删除
 
 *  注意：操作执行完毕会自动关闭数据库
 */
- (void)deleteModel:(Class)modelClass byId:(NSString *)FLDBID complete:(void(^)( BOOL flag))complete;
@end
