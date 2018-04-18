//
//  YBImageBrowserModel.h
//  YBImageBrowserDemo
//
//  Created by 杨波 on 2018/4/10.
//  Copyright © 2018年 杨波. All rights reserved.
//

#import "YBImageBrowserUtilities.h"

NS_ASSUME_NONNULL_BEGIN

@class YBImageBrowserModel;

typedef void(^YBImageBrowserModelProgressBlock)(YBImageBrowserModel *backModel, NSInteger receivedSize, NSInteger expectedSize, NSURL * _Nullable targetURL);
typedef void(^YBImageBrowserModelSuccessBlock)(YBImageBrowserModel *backModel, UIImage * _Nullable image, NSData * _Nullable data, BOOL finished);
typedef void(^YBImageBrowserModelFailedBlock)(YBImageBrowserModel *backModel, NSError * _Nullable error, BOOL finished);

FOUNDATION_EXTERN NSString * const YBImageBrowserModel_KVCKey_isLoading;
FOUNDATION_EXTERN NSString * const YBImageBrowserModel_KVCKey_isLoadFailed;
FOUNDATION_EXTERN char * const YBImageBrowserModel_SELName_download;

@interface YBImageBrowserModel : NSObject

/**
 本地图片
 （若图片不在 Assets 中，尽量使用 setImageWithFileName:fileType: 以避免图片缓存过多导致内存飙升）
 */
@property (nonatomic, strong, nullable) UIImage *image;
- (void)setImageWithFileName:(NSString *)fileName fileType:(NSString *)type;

/**
 本地 gif 名字
 （请不要带后缀）
 */
@property (nonatomic, copy, nullable) NSString *gifName;

/**
 网络图片 url
 （setUrlWithDownloadInAdvance: 设置 url 的时候异步预下载）
 */
@property (nonatomic, strong, nullable) NSURL *url;
- (void)setUrlWithDownloadInAdvance:(NSURL *)url;

/**
 本地或者网络 gif 最终转换类型
 */
@property (nonatomic, strong, nullable) FLAnimatedImage *animatedImage;

/**
 来源图片视图
 （用于做 YBImageBrowserAnimationMove 类型的动效）
 */
@property (nonatomic, strong, nullable) UIImageView *sourceImageView;

/**
 预览缩略图
 */
@property (nonatomic, strong, nullable) YBImageBrowserModel *previewModel;


@end

NS_ASSUME_NONNULL_END
