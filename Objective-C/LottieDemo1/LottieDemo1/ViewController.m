//
//  ViewController.m
//  LottieDemo1
//
//  Created by 李家豪 on 2017/5/9.
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
    
#pragma Lottie
    LOTAnimationView *animation = [LOTAnimationView animationNamed:@"servishero_loading"];
    [self.view addSubview:animation];
    
    animation.center = self.view.center;
    animation.loopAnimation = true;
    
    [animation playWithCompletion:^(BOOL animationFinsihed) {
       //do Something
    }];
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
