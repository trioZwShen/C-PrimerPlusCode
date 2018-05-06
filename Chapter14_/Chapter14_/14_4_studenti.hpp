//
//  14_4_studenti.hpp
//  Chapter14_
//
//  Created by SZW on 2018/3/3.
//  Copyright © 2018年 SZW. All rights reserved.
//

#ifndef _4_4_studenti_hpp
#define _4_4_studenti_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <valarray>

class Student:  private std::string, private std::valarray<double>
{
private:
    typedef std::valarray<double> ArrayDb;
    std::ostream & arr_out(std::ostream & os) const;
public:
    //构造与析构
    Student():std::string("Null Student"),ArrayDb(){}  //(1)默认构造函数
    explicit Student(const std::string & s):std::string(s),ArrayDb(){} //(2)显示转换构造函数
    explicit Student(int n):std::string("Nully"),ArrayDb(n){} //(3)显示转换构造函数
    Student(const std::string & s, int n):std::string(s),ArrayDb(n){} //(4)构造函数
    Student(const std::string & s, const ArrayDb & a):std::string(s),ArrayDb(a){}//(5)构造函数
    Student(const std::string & s, const double* pd, int n):std::string(s),ArrayDb(pd,n){}//(6)构造函数
    ~Student(){}
    //普通方法
    double Average()const;
    const std::string & Name()const;
    double & operator[](int i);
    double operator[](int i)const;
    //友元函数
    friend std::istream & operator>>(std::istream & is, Student & s);
    friend std::istream & getline(std::istream & is, Student & s);
    friend std::ostream & operator<<(std::ostream & is, const Student & s);
};
#endif /* _4_4_studenti_hpp */
