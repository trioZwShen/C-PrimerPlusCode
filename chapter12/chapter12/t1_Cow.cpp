//
//  t1_Cow.cpp
//  chapter12
//
//  Created by SZW on 2018/2/5.
//  Copyright © 2018年 SZW. All rights reserved.
//
#include <iostream>
#include <cstring>
#include <iomanip>
#include "t1_Cow.hpp"
//构造函数1,默认构造函数
Cow::Cow()
{
    std::strcpy(_name,"No name");
    _hobby=new char[9];
    std::strcpy(_hobby,"No hobby");
    _weight=0.0;
}
//构造函数2
Cow::Cow(const char * nm, const char * ho, double wt)
{
    std::strcpy(_name,nm);
    _hobby=new char[std::strlen(ho)+1];
    std::strcpy(_hobby,ho);
    _weight=wt;
}
//构造函数3,复制构造函数
Cow::Cow(const Cow &c)
{
    std::strcpy(_name,c._name);
    _hobby=new char[std::strlen(c._hobby)+1];
    std::strcpy(_hobby,c._hobby);
    _weight=c._weight;
}
//析构函数
Cow::~Cow()
{
    //std::cout<<_name<<std::endl;
    delete [] _hobby;
}
//重载赋值运算符,高级版
Cow & Cow::operator=(const Cow & c)
{
    if(this!=&c)
    {
        Cow tempOb(c);              //创建一个临时变量
        char * tempHobby=tempOb._hobby;  //暂存临时变量的_hobby
        tempOb._hobby=_hobby;       //临时变量的_hobby指向本对象的_hobby
        _hobby=tempHobby;           //将对象的_hobby指向临时变量的_hobby
        strcpy(_name,tempOb._name);
        _weight=tempOb._weight;
    }                               //代码块结束时,将会销毁临时变量
    return *this;
}
//显示类
void Cow::ShowCow()const
{
    std::cout<<std::setw(8)<<"Name: "<<std::setw(10)<<_name
            <<std::setw(10)<<"Hobby: "<<std::setw(10)<<_hobby
            <<std::setw(10)<<"Weight: "<<std::setw(10)<<_weight<<std::endl;
}
