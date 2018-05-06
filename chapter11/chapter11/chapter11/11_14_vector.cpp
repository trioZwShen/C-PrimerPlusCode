//
//  11_14_vector.cpp
//  chapter11
//
//  Created by SZW on 2018/1/25.
//  Copyright © 2018年 SZW. All rights reserved.
//
#define JINDU 0.0000001
#include<cmath>
#include<iostream>
#include "11_14_vector.hpp"
using std::sqrt;
using std::endl;
using std::cout;
using std::cin;
using std::atan;
using std::cos;
using std::sin;
using std::atan2;

namespace VECTOR
{
    const double Rad_to_deg=45.0/atan(1.0);
    //私有成员函数
    void Vector::set_mag()
    {
        _mag=sqrt(_x*_x+_y*_y);
    }
    void Vector::set_ang()
    {
        //x与y都是0时
        if((_x<JINDU && _x>-JINDU) && (_y<JINDU && _y>-JINDU))
            _ang=0.0;
        else
            _ang=atan2(_x,_y);
    }
    void Vector::set_x()
    {
        _x=_mag*cos(_ang);
    }
    void Vector::set_y()
    {
        _y=_mag*sin(_ang);
    }
    
    //公有成员函数
    Vector::Vector()
    {
        _x=0.0;
        _y=0.0;
        _ang=0.0;
        _mag=0.0;
        _mode=RECT;
    }
    Vector::Vector(double n1,double n2,Mode form)
    {
        _mode=form;
        if(form==RECT)
        {
            _x=n1;
            _y=n2;
            set_mag();
            set_ang();
        }
        else if(form==POL)
        {
            _mag=n1;
            _ang=n2/Rad_to_deg;
            set_x();
            set_y();
        }
        else
        {
            printf("不存在该模式!\n");
            _x=_y=_ang=_mag=0.0;
            _mode=RECT;
        }
    }
    Vector::~Vector()
    {
    }
    
    void Vector::reset(double n1,double n2,Mode form)
    {
        _mode=form;
        if(form==RECT)
        {
            _x=n1;
            _y=n2;
            set_mag();
            set_ang();
        }
        else if(form==POL)
        {
            _mag=n1;
            _ang=n2/Rad_to_deg;
            set_x();
            set_y();
        }
        else
        {
            printf("不存在该模式!\n");
            _x=_y=_ang=_mag=0.0;
            _mode=RECT;
        }
    }
    
    //成员函数重载运算符
    Vector Vector::operator+(const Vector & b)const
    {
        return Vector(_x+b._x,_y+b._y);
    }
    Vector Vector::operator-(const Vector & b)const
    {
        return Vector(_x-b._x,_y-b._y);
    }
    Vector Vector::operator-()const
    {
        return Vector(-_x,-_y);
    }
    Vector Vector::operator*(double n)const
    {
        return Vector(n*_x,n*_y);
    }
    
    //友元函数重载运算符
    Vector operator*(double n,const Vector & a)
    {
        return Vector(n*a._x,n*a._y);
    }
    std::ostream & operator<<(std::ostream & os,const Vector & v)
    {
        if(v._mode==Vector::RECT)
            os<<"(x, y)=("<<v._x<<", "<<v._y<<")";
        else if(v._mode==Vector::POL)
            printf("(m, a)=(%f, %f)",v._mag,v._ang);
        else
            printf("出错啦!");
        return os;
    }
}

