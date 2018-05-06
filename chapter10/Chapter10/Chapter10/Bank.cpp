//
//  Bank.cpp
//  Chapter10
//
//  Created by SZW on 2018/1/24.
//  Copyright © 2018年 SZW. All rights reserved.
//
#include<iostream>
#include "Bank.hpp"

//构造函数
Bank::Bank(const char * name,const char * account,double balance)
{
    int i;
    for(i=0;name[i]!='\0';++i)
        _name[i]=name[i];
    _name[i]='\0';
    for(i=0;account[i]!='\0';++i)
        _account[i]=account[i];
    _account[i]='\0';
    _balance=balance;
}


//显示
void Bank::Show()const
{
    std::cout<<_name<<"'s account is "<<_account<<" balance is "<<_balance<<std::endl;
}
//存入指定存款
void Bank::Deposit(double money)
{
    if(money<0)
        std::cout<<"ERROR!\n";
    else
        _balance+=money;
}
//取出
void Bank::Withdraw(double money)
{
    if(money>_balance)
        std::cout<<"Not enough\n";
    else
        _balance-=money;
}
