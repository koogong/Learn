##  UIView 动画

>参考：[IOS动画](http://www.jianshu.com/p/6e326068edeb)

[TOC]



### 简单的登录动画

三行代码概括了整个动画发生的事情，虽然刚开始接触看着有点懵。但仔细看完Demo代码后发现的确整个过程就是靠这三行代码。

```objective-c
self.userName.center.x += offset;	//userName进入
self.password.center.x += offset;	//passwor进入
self.login.alpha = 1;				//显示登录按钮
```

整个过程就是通过**位置变化配合UIKit中系统中提供的`animate`标题打头的类方法实现动画效果**，接下来使用**UIKit**的动画API让动画画起来了

```objective-c
//将文本初始位置设置在屏幕左侧
CGPoint accountCenter = self.userName.center;
CGPoint passwordCenter = self.password.center;

accountCenter.x -= 200;
passwordCenter.x -= 200;

self.userName.center = accountCenter;
self.password.center = passwordCenter;

//还原原来坐标
accountCenter.x += 200;
passwordCenter.x += 200;

[UIView animateWithDuration: 0.5 animations: ^{

self.userName.center = accountCenter;
self.password.center = passwordCenter;
self.login.alpha = 1;
} completion: nil];
```

**UIView**中`animate`标题的类方法中每一个这样的类方法都提供了名为`animations`的`block`代码块，这些代码会在方法调用后立刻或延迟一段时间以动画的方式执行。

由于文本框从左侧滑动，按钮也渐变显示出来，但动画效果还不够好。所有通过将三个动画逐个活动，所以在`viewDidAppear:`中如下方法实现了效果：

```objective-c
[UIView animateWithDuration: 0.5 delay: 0.35 options: UIViewAnimationOptionCurveEaseInOut animations: ^{
self.password.center = passwordCenter;
} completion: ^(BOOL finished) {
[UIView animateWithDuration: 0.2 animations: ^{
self.login.alpha = 1;
}];
}];
//密码输入框在延后 0.35 秒之后开始从左侧出来，在持续 0.5 秒的动画之后，开始渐变显示按钮，然后动画完成。
```

- `duration：` 动画时长
- `delay:` 动画延迟多久后执行
- `options:` 决定动画的展示方式
- `animations:` 转换成动画表示的代码
- `completion:` 动画结束后执行得代码块



### 可实现动画的属性

动画的生成属性大致可以分成三大类：

- **坐标尺寸**
- **视图显示**
- **形态变化**

> 不是所有修改属性的操作放到`animations`代码块中都会变成动画实现的——不管你怎么修改一个视图的`tag`,或者`delegate`。因此，可以实现动画的属性必定会导致视图的重新渲染。

#### 坐标尺寸

- `bounds:` 修改这个属性会结合`center`属性重新计算`frame`。建议通过这个属性修改尺 
- `frame:` 修改这个属性通常会导致视图形变的同时也发生移动，然后会重新设置`center`跟`bounds`属性
- `center:` 设置后视图会移动到一个新位置，修改后会结合`bounds`重新计算`frame`

#### 视图显示

- `backgroundColor:` 修改这个属性会产生颜色渐变过渡的效果，本质上是系统不断修改了tintColor来实现的
- `alpha:`修改这个属性会产生淡入淡出的效果
- `hidden:`  修改这个属性可以制作翻页隐藏的效果

#### 形态变化

- `transform:` 修改这个属性可以实现旋转、形变、移动、翻转等动画效果，其通过矩阵运算的方式来实现，因此更加强大



### 动画参数

在动画方法中有一个重要的参数`options`,它能让你高度的自定义动画效果。

下面是这个参数类型的值集合：

- Repeating
- `UIViewAnimationOptionRepeat`动画循环执行
- `UIViewAnimationOptionAutoreverse`动画在执行完毕后会反方向再执行一次

`UIViewAnimationOptionRepeat`参数不仅让动画循环播放，并且还导致了`completion`的回调永远无法执行。



- Easing

- `UIViewAnimationOptionCurveEaseInOut`先加速后减速，默认
- `UIViewAnimationOptionCurveEaseIn`由慢到快
- `UIViewAnimationOptionCurveEaseOut`由快到慢
- `UIViewAnimationOptionCurveLinear`匀速

- Transitionling


我们还能通过传入下面的这些参数来实现一些特殊的动画效果。

-   `UIViewAnimationOptionTransitionNone` 没有效果，默认
- `UIViewAnimationOptionTransitionFlipFromLeft` 从左翻转效果
- `UIViewAnimationOptionTransitionFlipFromRight` 从右翻转效果
- `UIViewAnimationOptionTransitionCurlUp` 从上往下翻页
- `UIViewAnimationOptionTransitionCurlDown` 从下往上翻页
- `UIViewAnimationOptionTransitionCrossDissolve` 旧视图溶解过渡到下一个视图
- `UIViewAnimationOptionTransitionFlipFromTop` 从上翻转效果
- `UIViewAnimationOptionTransitionFlipFromBottom` 从下翻转效果

​


### 弹簧动画

动画效果

![](http://ww1.sinaimg.cn/large/e8298d2dgy1ffrg5wbxm6g208l0f93z4.gif)

- `usingSpringWithDamping:`速度衰减比例。取值范围0 ~ 1，值越低震动越强
- `initialSpringVelocity:`初始化速度，值越高则物品的速度越快

```objective-c
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
```



Swift(Demo)[]

Objective-C(Demo)[]

