//
//  ViewController.m
//  Animations
//
//  Created by 李家豪 on 2017/5/17.
//  Copyright © 2017年 koogong. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@property (nonatomic, strong) UITextField *userName;
@property (nonatomic, strong) UITextField *password;
@property (nonatomic, strong) UIButton *login;



@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    [self.view addSubview: self.userName];
    [self.view addSubview: self.password];
    [self.view addSubview: self.login];

}


- (void)viewDidAppear:(BOOL)animated
{
    [super viewDidAppear:animated];
    
    const CGFloat offset = CGRectGetWidth([UIScreen mainScreen].bounds);
    
    CGPoint accountCenter = self.userName.center;//将居中位置赋给 accountCenter
    CGPoint passwordCenter = self.password.center;//赋值给 passwordCenter
    
    CGPoint starAccountCenter = CGPointMake(self.userName.center.x - offset, self.userName.center.y);//定义初始位置
    CGPoint starPassWordCenter = CGPointMake(self.password.center.x - offset, self.password.center.y);//定义初始位置
    
    self.userName.center = starAccountCenter;//替换原本位置
    self.password.center = starPassWordCenter;
    
//    [UIView animateWithDuration: 0.5 animations:^{
//        self.userName.center = accountCenter;
//    } completion: nil];
    
    // o
    [UIView animateWithDuration: 0.5 delay: 0 options:UIViewAnimationOptionCurveEaseInOut animations:^{
        self.userName.center = accountCenter;
    } completion:nil];
    
    // duration: 动画时长
    // delay: 决定了动画延迟多久之后执行
    // options: 用来决定动画的展示方法
    // animations: 转换成动画表示的代码
    // completion: 动画结束后执行得代码块
    
    
    [UIView animateWithDuration: 0.5 delay: 0.35 options: UIViewAnimationOptionCurveEaseInOut animations:^{
        self.password.center = passwordCenter;
    } completion:^(BOOL finished) {
        [UIView animateWithDuration: 0.2 delay: 0 usingSpringWithDamping: 0.5 initialSpringVelocity: 0 options: 0 animations:^{
            self.login.alpha = 1;
            CGPoint center = self.login.center;
            center.y -= 100;
            self.login.center = center;
        } completion:nil];
    }];
    
    
    
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}



- (UITextField *)commonTextFieldWithPlaceholder: (NSString *)placeholder size:(CGSize)size {
    
    UITextField *textField = [[UITextField alloc] initWithFrame:CGRectMake( 0,  0 ,  size.width, size.height)];
    
    textField.placeholder =placeholder;
    textField.borderStyle = UITextBorderStyleRoundedRect;
    
    return textField;
}



- (UITextField *) userName {
    
    if (!_userName) {
        _userName = [self commonTextFieldWithPlaceholder:@"用户名" size:CGSizeMake(CGRectGetWidth([UIScreen mainScreen].bounds) - 100 , 25)];
        
        _userName.center = CGPointMake(self.view.center.x, 200);
    }
    return _userName;
}

- (UITextField *) password {
    
    if (!_password) {
        _password = [self commonTextFieldWithPlaceholder:@"密码" size:CGSizeMake(CGRectGetWidth([UIScreen mainScreen].bounds) - 100 , 25)];
        
        _password.center = CGPointMake(self.view.center.x, 250);
    }
    return _password;
}

- (UIButton *) login {
    
    if (!_login) {
        _login = [[UIButton alloc] initWithFrame:CGRectMake(0, 0, 120, 30)];
        _login.backgroundColor = [UIColor colorWithRed:233/255. green:123/255. blue:123/255. alpha:1];
        
        [_login setTitle:@"登录" forState:UIControlStateNormal];
        _login.center = CGPointMake(self.view.center.x, 400);
        _login.alpha = 0;
    }
    return _login;
}


@end






