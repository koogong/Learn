//
//  FirstViewController.swift
//  微信登录界面
//
//  Created by 李家豪 on 2017/5/20.
//  Copyright © 2017年 koogong. All rights reserved.
//

import UIKit

let imgTest1 = UIImageView()
let loginTF = UITextField()
let passwordTF = UITextField()
let loginBtn1 = UIButton()

class FirstViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()

        self.title = "划入效果"
        self.view.backgroundColor = UIColor.white
        
        //设置头像位置
        imgTest1.frame = CGRect(x: 0, y: 0, width: 200, height: 200)
        imgTest1.center = CGPoint(x: self.view.bounds.width / 2, y: 200)
        imgTest1.image = UIImage(named: "koogong.JPG")
        
//        UIView.animate(withDuration: 0.5, delay: 0.35, options: UIViewAnimationOptions.curveEaseInOut, animations: {
//            imgTest1.center = CGPoint(x: self.view.bounds.width / 2, y: 200)
//        }, completion: nil)
        
        //圆角
        imgTest.layer.masksToBounds = true
        imgTest.layer.cornerRadius = 100
        
        //设置边框
        imgTest.layer.borderWidth = 1
        
        imgTest.layer.borderColor = UIColor.black.cgColor
        
        //=====================================================
        //文本框
        
        loginTF.frame = CGRect(x: 0, y: 0, width: 300, height: 40)
        passwordTF.frame = CGRect(x: 0, y: 0, width: 300, height: 40)
        
        loginTF.center = CGPoint(x: -300, y: 400)
        passwordTF.center = CGPoint(x: -300, y: 450)
        
        loginTF.borderStyle = .roundedRect
        passwordTF.borderStyle = .roundedRect
        
        
        UIView .animate(withDuration: 0.5, delay: 0.35, options: UIViewAnimationOptions.curveEaseInOut, animations: {
            loginTF.center = CGPoint(x: self.view.bounds.width / 2, y: 400)
        }, completion: nil)
        
        UIView .animate(withDuration: 0.5, delay: 0.7, options: UIViewAnimationOptions.curveEaseInOut, animations: {
            passwordTF.center = CGPoint(x: self.view.bounds.width / 2, y: 450)
        }, completion: nil)
        
        loginTF.placeholder = "账号"
        passwordTF.placeholder = "密码"
        
        //=======================================================
        //登录按钮
        loginBtn1.frame = CGRect(x: 0, y: 0, width: 150, height: 50)
        loginBtn1.center = CGPoint(x: self.view.bounds.width / 2, y: 620)
        loginBtn1.backgroundColor = UIColor.init(red: 233/255, green: 123/255, blue: 123/255, alpha: 1)
        loginBtn1.setTitle("登录", for: .normal)
        loginBtn1.alpha = 0
        UIView.animate(withDuration: 2, delay: 0.35, usingSpringWithDamping: 0.3, initialSpringVelocity: 0, options: UIViewAnimationOptions.init(rawValue: 0), animations: {
            
            loginBtn1.alpha = 1
            loginBtn1.center = CGPoint(x: self.view.bounds.width / 2, y: loginBtn1.center.y - 100)
            
            
        }, completion: nil)
        
        
        self.view.addSubview(imgTest1)
        self.view.addSubview(loginTF)
        self.view.addSubview(passwordTF)
        self.view.addSubview(loginBtn1)
        
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
