//
//  RootViewController.swift
//  微信登录界面
//
//  Created by 李家豪 on 2017/5/20.
//  Copyright © 2017年 koogong. All rights reserved.
//

import UIKit

let firstVC = FirstViewController()
let secondVC = SecondViewController()

let imgTest = UIImageView()
let lable = UILabel()
let loginSucc = UILabel()
let password = UITextField()
let loginBtn = UIButton()

class RootViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()

        self.view.backgroundColor = UIColor.white
        self.title = "Root"
        
        //left
        let leftItem = UIBarButtonItem(title: "Left", style: .plain, target: self, action: #selector(leftClicked))
        
        self.navigationItem.leftBarButtonItem = leftItem
        
        //Right
        let rightItem = UIBarButtonItem(title: "Right", style: .plain, target: self, action: #selector(rightClicked))
        self.navigationItem.rightBarButtonItem = rightItem
        
        //设置头像
        imgTest.frame = CGRect(x: 0, y: 0, width: 200, height: 200)
        imgTest.center = CGPoint(x: self.view.bounds.width / 2, y: 200)
        imgTest.image = UIImage(named: "koogong.JPG")
        
        //圆角
        imgTest.layer.masksToBounds = true
        imgTest.layer.cornerRadius = 100
        
        //文本框
        lable.frame = CGRect(x: 0, y: 0, width: 300, height: 40);
        lable.center = CGPoint(x: self.view.bounds.width / 2, y: 400);
        lable.text = "+86 1857905****"
        lable.font = UIFont.boldSystemFont(ofSize: 24)
        lable.textAlignment = .center
        
        //密码框
        password.frame = CGRect(x: 0, y: 0, width: 300, height: 40)
        password.center = CGPoint(x: self.view.bounds.width / 2, y: 450)
        password.borderStyle = .roundedRect
        
        password.placeholder = "密码 请填写密码"
        
        //登录按钮
        loginBtn.frame = CGRect(x: 0, y: 0, width: 150, height: 50)
        loginBtn.center = CGPoint(x: self.view.bounds.width / 2, y: 520)
        loginBtn.backgroundColor = UIColor.init(red: 9/255, green: 187/255, blue: 7/255, alpha: 1)
        loginBtn.setTitle("登录", for: .normal)
        
        loginBtn.addTarget(self, action: #selector(loginBtnClicked), for: .touchUpInside)
        
        //登录成功
        loginSucc.frame = CGRect(x: 0, y: 0, width: 300, height: 300)
        loginSucc.center = CGPoint(x: self.view.bounds.width / 2, y: self.view.bounds.height / 2)
        loginSucc.textAlignment = .center
        loginSucc.text = "登录成功"
        loginSucc.textColor = UIColor.init(red: 123/255, green: 123/255, blue: 123/255, alpha: 1)
        loginSucc.font = UIFont.boldSystemFont(ofSize: 40)
        loginSucc.alpha = 0

        
        
        self.view.addSubview(imgTest)
        self.view.addSubview(lable)
        self.view.addSubview(password)
        self.view.addSubview(loginBtn)
        self.view.addSubview(loginSucc)
        
        
    }
    
    func loginBtnClicked() {
        //登录成功
        imgTest.alpha = 0
        lable.alpha = 0
        password.alpha = 0
        loginBtn.alpha = 0
        
        loginSucc.alpha = 1
    }
    
    func leftClicked() {
        self.navigationController?.pushViewController(firstVC, animated: true)
    }
    
    func rightClicked() {
        self.navigationController?.pushViewController(secondVC, animated: true)
    }
    
    
    override func touchesEnded(_ touches: Set<UITouch>, with event: UIEvent?) {
        self.view.endEditing(true)
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
