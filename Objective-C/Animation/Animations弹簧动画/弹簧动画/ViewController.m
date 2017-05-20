//
//  ViewController.m
//  弹簧动画
//
//  Created by 李家豪 on 2017/5/19.
//  Copyright © 2017年 koogong. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@property (nonatomic, strong) UIButton *btn;
@property (nonatomic, strong) UIButton *btn1;
@property (nonatomic, strong) UIButton *btn2;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    
    [self.view addSubview:self.btn];
    
    [self.view addSubview:self.btn1];
    
    [self.view addSubview:self.btn2];
    
}

- (void)viewDidAppear:(BOOL)animated
{
    [super viewDidAppear:animated];
    
    
}

- (UIButton *) btn {
    
    if (!_btn) {
        
        //位置
        _btn = [[UIButton alloc] initWithFrame:CGRectMake(0, 0, 100, 100)];
        _btn.center = CGPointMake(self.view.center.x, self.view.center.y * 2 + 100);
        
        //图形
        _btn.layer.masksToBounds = true;
        _btn.layer.cornerRadius = 50;
        
        [_btn setTitle:@"1" forState:UIControlStateNormal];
        _btn.backgroundColor = [UIColor colorWithRed:233/255. green:123/255. blue:123/255. alpha:1];
        [UIView animateWithDuration: 0.5 delay: 0.35 usingSpringWithDamping: 0.6 initialSpringVelocity: 0 options: UIViewAnimationOptionCurveLinear animations:^{
            
            CGPoint center = self.view.center;
            
            _btn.center = center;
            
        } completion: nil];
    }
    return  _btn;
}


- (UIButton *) btn1 {
    
    if (!_btn1) {
        
        //位置以及大小
        _btn1 = [[UIButton alloc] initWithFrame:CGRectMake( 0 , 0 , 100, 100)];
        _btn1.center = CGPointMake(self.view.center.x, self.view.center.y * 2 + 100);
        
        //圆形
        _btn1.layer.masksToBounds = true;
        _btn1.layer.cornerRadius = 50;
        
        
        
        [_btn1 setTitle:@"2" forState:UIControlStateNormal];
        _btn1.backgroundColor = [UIColor colorWithRed:233/255. green:123/255. blue:123/255. alpha:1];

        
        [UIView animateWithDuration: 0.5 delay: 0.7 usingSpringWithDamping: 0.9 initialSpringVelocity:0 options: UIViewAnimationOptionCurveLinear animations:^{
            
            CGPoint center = self.view.center;
            center = CGPointMake( self.view.center.x, self.view.center.y - 110);

            _btn1.center = center;
            
        } completion: nil];
        
    }
    
    return _btn1;
}


- (UIButton *) btn2 {
    
    _btn2 = [[UIButton alloc] initWithFrame:CGRectMake( 0 ,  0 , 100, 100)];
    _btn2.center = CGPointMake( self.view.center.x, self.view.center.y * 2 + 100);
    
    _btn2.layer.masksToBounds = true;
    _btn2.layer.cornerRadius = 50;
    
    
    [_btn2 setTitle:@"3" forState:UIControlStateNormal];
    _btn2.backgroundColor = [UIColor colorWithRed:233/255. green:123/255. blue:123/255. alpha:1];
    
    [UIView animateWithDuration: 0.5 delay: 1.0 usingSpringWithDamping: 1.2 initialSpringVelocity:0 options: UIViewAnimationOptionCurveLinear animations:^{
        
        CGPoint center = self.view.center;
        center = CGPointMake(self.view.center.x , self.view.center.y - 220);
        
        
        _btn2.center = center;
    } completion: nil];
    
    return _btn2;
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
