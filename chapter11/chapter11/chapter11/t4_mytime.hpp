//
//  11_7_mytime.hpp
//  chapter11
//
//  Created by SZW on 2018/1/24.
//  Copyright © 2018年 SZW. All rights reserved.
//

#ifndef _1_7_mytime_hpp
#define _1_7_mytime_hpp

#include <stdio.h>
#include <iostream>

class Time
{
private:
    int _hours;
    int _mintes;
public:
    //构造函数
    Time();
    Time(int h,int m=0);
    //析构函数
    virtual ~Time(){}
    //成员函数
    void AddMin(int m);
    void AddHr(int h);
    void Reset(int h=0,int m=0);
    void Show()const;
    
    //友元函数运算符重载
    friend Time operator+(const Time & p,const Time & t);
    friend Time operator*(const Time & t, double x);
    friend Time operator*(double x, const Time & t);
    friend Time operator-(const Time & p,const Time & t);
    friend std::ostream & operator<<(std::ostream & os, const Time & t);
};




#endif /* _1_7_mytime_hpp */
