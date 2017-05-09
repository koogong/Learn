//
//  ViewController.m
//  LottieDemo
//
//  2017/4/28.
//  Copyright © 2017年 koogong. All rights reserved.
//

#import "ViewController.h"

#import <Lottie/Lottie.h>



@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    //URL koogong
//    LAAnimationView *lottieView = [LAAnimationView animationNamed:@"koogong"];
//    lottieView.contentMode = UIViewContentModeScaleAspectFill;
//    [self.view addSubview:lottieView];
    
#pragma mark Lottie
    //需要呈现的代码段，Lottie有一个类名 LOTAnimationView，它加载了JSON文件中的动画数据。
    //要显示动画，必须 LOTAnimaationView使用之前下载的JSON文件创建一个对象
    LOTAnimationView *animation = [LOTAnimationView animationNamed:@"servishero_loading"];
    [self.view addSubview:animation];
    //animation.frame = CGRectMake(0, 0, 400, 400);
    animation.center = self.view.center;
    animation.loopAnimation = true;//循环动画
    //animation.animationSpeed = 0.5;//动画的速度
    
    //animation.transform = CGAffineTransformRotate(self.view.transform, 45.0);//旋转45度
    
    [animation playWithCompletion:^(BOOL animationFinished) {
        //do Something
        
        
    }];
    
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
