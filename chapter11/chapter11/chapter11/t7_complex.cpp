//
//  t7_complex.cpp
//  chapter11
//
//  Created by SZW on 2018/1/29.
//  Copyright © 2018年 SZW. All rights reserved.
//
#include <iostream>
#include "t7_complex.hpp"

//成员函数重载运算符
Complex & Complex::operator~()
{
    _im=-_im;
    return *this;
}
Complex Complex::operator+(const Complex & c) const
{
    Complex out;
    out._re=_re + c._re;
    out._im=_im + c._im;
    return out;
}
Complex Complex::operator-(const Complex & c) const
{
    Complex out;
    out._re=_re - c._re;
    out._im=_im - c._im;
    return out;
}
Complex Complex::operator*(double x) const
{
    Complex out;
    out._re=_re*x;
    out._im=_im*x;
    return out;
}

//友元函数重载运算符
Complex operator*(double x,const Complex & c)
{
    Complex out;
    out._re=c._re*x;
    out._im=c._im*x;
    return out;
}
std::istream & operator>>(std::istream & is,Complex & c)
{
    std::cout<<"\n实部: ";
    is>>c._re;
    std::cout<<"虚部: ";
    is>>c._im;
    return is;
}
std::ostream & operator<<(std::ostream & os,const Complex & c)
{
    os<<"("<<c._re<<" , "<<c._im<<"i)";
    return os;
}

