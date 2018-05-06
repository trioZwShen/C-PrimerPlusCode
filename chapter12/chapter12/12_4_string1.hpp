//
//  12_4_string1.hpp
//  chapter12
//
//  Created by SZW on 2018/1/31.
//  Copyright © 2018年 SZW. All rights reserved.
//

#ifndef _2_4_string1_hpp
#define _2_4_string1_hpp
#include <iostream>
#include <stdio.h>

class String
{
private:
    char * _str;            //字符串
    int _len;               //字符串长度
    static int _numString;  //用于记录字符串的个数
    static const int _lenMax=80;
public:
    String();
    String(const char * str);
    String(const String & s);           //复制构造函数
    ~String();
    int length() const {return _len;}
    
    /*成员函数重载运算符*/
    String & operator=(const String & s);
    String & operator=(const char * str);
    char & operator[](int i);               //可修改[]
    const char & operator[](int i)const;    //不可修改[]
    
    /*友元函数重载运算符*/
    friend bool operator<(const String & s1, const String & s2);
    friend bool operator>(const String & s1, const String & s2);
    friend bool operator==(const String & s1, const String & s2);
    friend std::ostream & operator<<(std::ostream & os, const String & s2);
    friend std::istream & operator>>(std::istream & is, String & s2);
    
    /*静态成员函数*/
    static int HowMany() {return _numString;}
};
#endif /* _2_4_string1_hpp */
