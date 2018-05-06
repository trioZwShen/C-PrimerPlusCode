//
//  12_4_string1.cpp
//  chapter12
//
//  Created by SZW on 2018/1/31.
//  Copyright © 2018年 SZW. All rights reserved.
//
#include <iostream>
#include <cstring>
#include "12_4_string1.hpp"
using std::strcpy;
using std::strcmp;
using std::strlen;

int String::_numString=0;

String::String()
{
    _str=new char[4];       //开辟新空间
    strcpy(_str,"szw");
    _len=3;
    _numString++;
}
String::String(const char * str)
{
    _str = new char[strlen(str)+1];
    strcpy(_str,str);
    _len=(int)(strlen(str));
    _numString++;
}

String::String(const String & s)           //复制构造函数
{
    _str = new char[s._len+1];
    strcpy(_str,s._str);
    _len=s._len;
    _numString++;
}
String::~String()
{
    delete [] _str;
    --_numString;
}

/*成员函数重载运算符*/
String & String::operator=(const String & s)    //重载赋值运算符
{
    //防自等
    if(this == &s)
        return *this;
    delete [] _str;         //清除原有空间
    _len=s._len;
    _str=new char [1+_len]; //开辟新空间
    strcpy(_str, s._str);   //赋值
    return *this;           //返回自身引用
}
String & String::operator=(const char * str)
{
    delete [] _str;         //清除原有空间
    _len=int(strlen(str));
    _str=new char [1+_len]; //开辟新空间
    strcpy(_str, str);   //赋值
    return *this;           //返回自身引用
}
char & String::operator[](int i)               //可修改[]
{
    return _str[i];
}
const char & String::operator[](int i)const    //不可修改[]
{
    return _str[i];
}

/*友元函数重载运算符*/
bool operator<(const String & s1, const String & s2)
{
    return (strcmp(s1._str, s2._str)<0);        //如果小于0表示,s1._str小于s2._str
}
bool operator>(const String & s1, const String & s2)
{
    return s2<s1;
}
bool operator==(const String & s1, const String & s2)
{
    return (strcmp(s1._str, s2._str)==0);      //如果等于0表示,s1._str等于s2._str
}
std::ostream & operator<<(std::ostream & os, const String & s2)
{
    os<<s2._str;
    return os;
}
std::istream & operator>>(std::istream & is, String & s2)
{
    char temp[String::_lenMax];
    is.get(temp,String::_lenMax);
    if(is)
        s2=temp;
    while(is && is.get()!='\n')
        continue;
    return is;
}
