//
//  SecondViewController.swift
//  微信登录界面
//
//  Created by 李家豪 on 2017/5/20.
//  Copyright © 2017年 koogong. All rights reserved.
//

import UIKit

let imgTest2 = UIImageView()
let loginTF2 = UITextField()
let passwordTF2 = UITextField()
let loginBtn2 = UIButton()


class SecondViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()

        self.title = "弹簧效果"
        self.view.backgroundColor = UIColor.white
        
        //===========================================================
        //头像设置
        imgTest2.frame = CGRect(x: 0, y: 0, width: 200, height: 200)
        imgTest2.center = CGPoint(x: self.view.bounds.width / 2, y: 200)
        imgTest2.image = UIImage(named: "koogong.JPG")
        
        
        imgTest2.layer.masksToBounds = true
        imgTest2.layer.cornerRadius = 100
        
        
        //===========================================================
        //文本框设置
        loginTF2.frame = CGRect(x: 0, y: 0, width: 300, height: 40)
        passwordTF2.frame = CGRect(x: 0, y: 0, width: 300, height: 40)
        
        loginTF2.center = CGPoint(x: self.view.bounds.width.adding(300), y: 400)
        passwordTF2.center = CGPoint(x: self.view.bounds.width.adding(300), y: 450)
        
        loginTF2.borderStyle = .roundedRect
        passwordTF2.borderStyle = .roundedRect
        
        
        loginTF2.placeholder = "账号"
        passwordTF2.placeholder = "密码"
        
        
        //===========================================================
        //按钮设置
        loginBtn2.frame = CGRect(x: 0, y: 0, width: 150, height: 50)
        loginBtn2.center = CGPoint(x: self.view.bounds.width / 2, y: 620)
        loginBtn2.setTitle("登录", for: .normal)
        loginBtn2.backgroundColor = UIColor.init(red: 233/255, green: 123/255, blue: 123/255, alpha: 1)
        loginBtn2.alpha = 0
        
        
        //动画设置
        UIView.animate(withDuration: 0.5, delay: 0.35, usingSpringWithDamping: 0.5, initialSpringVelocity: 0.1, options: UIViewAnimationOptions.init(rawValue: 0), animations: {
            loginTF2.center = CGPoint(x: self.view.bounds.width / 2, y: 400)
        }, completion: nil)
        
        UIView.animate(withDuration: 0.5, delay: 0.7, usingSpringWithDamping: 0.5, initialSpringVelocity: 0.1, options: UIViewAnimationOptions.init(rawValue: 0), animations: {
            passwordTF2.center = CGPoint(x: self.view.bounds.width / 2, y: 450)
        }, completion: nil)
        
        UIView.animate(withDuration: 0.5, delay: 1, usingSpringWithDamping: 0.5, initialSpringVelocity: 0.1, options: UIViewAnimationOptions.init(rawValue: 0), animations: {
            
            loginBtn2.alpha = 1
            loginBtn2.center = CGPoint(x: self.view.bounds.width / 2, y: loginBtn2.center.y - 100)
            
            
        }, completion: nil)
        
        self.view.addSubview(imgTest2)
        self.view.addSubview(loginTF2)
        self.view.addSubview(passwordTF2)
        self.view.addSubview(loginBtn2)
        
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    

    /*
    // MARK: - Navigation

    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        // Get the new view controller using segue.destinationViewController.
        // Pass the selected object to the new view controller.
    }
    */

}
