//
//  t7_complex.hpp
//  chapter11
//
//  Created by SZW on 2018/1/29.
//  Copyright © 2018年 SZW. All rights reserved.
//

#ifndef t7_complex_hpp
#define t7_complex_hpp

#include <stdio.h>
#include <iostream>

class Complex
{
private:
    double _re;
    double _im;
public:
    Complex(double re=0.0,double im=0.0):_re(re),_im(im){}
    ~Complex(){}
    
    //成员函数重载运算符
    Complex & operator~();
    Complex operator+(const Complex & c)const;
    Complex operator-(const Complex & c)const;
    Complex operator*(double x)const;
    
    //友元函数重载运算符
    friend Complex operator*(double x,const Complex & c);
    friend std::istream & operator>>(std::istream & is,Complex & c);
    friend std::ostream & operator<<(std::ostream & os,const Complex & c);
    
};




#endif /* t7_complex_hpp */
