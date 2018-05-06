//
//  11_7_mytime.cpp
//  chapter11
//
//  Created by SZW on 2018/1/24.
//  Copyright © 2018年 SZW. All rights reserved.
//
#include<iostream>
#include "t4_mytime.hpp"

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

//友元运算符重载

Time operator+(const Time & p,const Time & t)
{
    Time sum;
    sum._mintes=p._mintes+t._mintes;
    sum._hours=p._hours+t._hours+sum._mintes/60;
    sum._mintes=sum._mintes%60;
    return sum;
}
Time operator*(const Time & t, double x)
{
    int tempT=x*(t._hours*60+t._mintes);
    
    return Time(tempT/60,tempT%60);
}
Time operator*(double x, const Time & t)
{
    return t*x;
}
Time operator-(const Time & p,const Time & t)
{
    int tempP,tempT;
    tempP=p._hours*60+p._mintes;
    tempT=t._hours*60+t._mintes;
    
    return Time((tempP-tempT)/60,(tempP-tempT)%60);
}
std::ostream & operator<<(std::ostream & os, const Time & t)
{
    os<<t._hours<<" : "<<t._mintes;
    return os;
}
