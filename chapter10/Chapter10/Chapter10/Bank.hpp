//
//  Bank.hpp
//  Chapter10
//
//  Created by SZW on 2018/1/24.
//  Copyright © 2018年 SZW. All rights reserved.
//

#ifndef Bank_hpp
#define Bank_hpp
#define MAX 20
#include <stdio.h>
class Bank
{
private:
    //姓名
    char _name[MAX];
    //账号
    char _account[MAX];
    //存款
    double _balance;
    
public:
    //构造函数
    Bank(const char * name="NULL",const char * account="NULL",double balance=0.0);
    //虚析构函数
    ~Bank(){};
    //显示
    void Show()const;
    //存入指定存款
    void Deposit(double money);
    //取出
    void Withdraw(double money);
};





#endif /* Bank_hpp */
