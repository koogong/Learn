//
//  LOTAnimationView
//  LottieAnimator
//
//  Created by Brandon Withrow on 12/14/15.
//  Copyright © 2015 Brandon Withrow. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LOTAnimationView_Compat.h"

typedef void (^LOTAnimationCompletionBlock)(BOOL animationFinished);

@interface LOTAnimationView : LOTView

+ (instancetype)animationNamed:(NSString *)animationName NS_SWIFT_NAME(init(name:));
+ (instancetype)animationNamed:(NSString *)animationName inBundle:(NSBundle *)bundle NS_SWIFT_NAME(init(name:bundle:));
+ (instancetype)animationFromJSON:(NSDictionary *)animationJSON NS_SWIFT_NAME(init(json:));

- (instancetype)initWithContentsOfURL:(NSURL *)url;

@property (nonatomic, readonly) BOOL isAnimationPlaying;//是否在动画
@property (nonatomic, assign) BOOL loopAnimation;//是否循环播放动画
@property (nonatomic, assign) CGFloat animationProgress;//动画执行进度
@property (nonatomic, assign) CGFloat animationSpeed;//动画速度
@property (nonatomic, readonly) CGFloat animationDuration;//动画时间

//实例方法
- (void)playWithCompletion:(LOTAnimationCompletionBlock)completion;//动画结束后可以执行一个block
- (void)play;//播放
- (void)pause;//暂停

- (void)addSubview:(LOTView *)view
      toLayerNamed:(NSString *)layer;

#if !TARGET_OS_IPHONE && !TARGET_IPHONE_SIMULATOR
@property (nonatomic) LOTViewContentMode contentMode;
#endif

@end
