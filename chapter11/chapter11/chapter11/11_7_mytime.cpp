//
//  11_7_mytime.cpp
//  chapter11
//
//  Created by SZW on 2018/1/24.
//  Copyright © 2018年 SZW. All rights reserved.
//
#include<iostream>
#include "11_7_mytime.hpp"

//构造函数
Time::Time()
{
    _hours=0;
    _mintes=0;
}
Time::Time(int h,int m)
{
    _hours=h;
    _mintes=m;
}

//成员函数
void Time::AddMin(int m)
{
    _mintes+=m;
    _hours=_mintes/60;
    _mintes=_mintes%60;
}
void Time::AddHr(int h)
{
    _hours+=h;
}
void Time::Reset(int h,int m)
{
    _hours=h;
    _mintes=m;
}
void Time::Show()const
{
    std::cout<<_hours<<":"<<_mintes<<std::endl;
}

//运算符重载
Time Time::operator+(const Time & t) const
{
    Time sum;
    sum._mintes=_mintes+t._mintes;
    sum._hours=_hours+t._hours+sum._mintes/60;
    sum._mintes= sum._mintes%60;
    return sum;
}
Time Time::operator*(double t) const
{
    Time re;
    int lll=(_hours*60+_mintes)*t;
    re._mintes=lll%60;
    re._hours=lll/60;
    return re;
}
Time Time::operator-(const Time & t) const
{
    Time diff;
    int tot1=_hours*60+_mintes;
    int tot2=t._hours*60+t._mintes;
    diff._mintes=(tot1-tot2)%60;
    diff._hours=(tot1-tot2)/60;
    return diff;
}
