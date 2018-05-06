//
//  14_4_studenti.cpp
//  Chapter14_
//
//  Created by SZW on 2018/3/3.
//  Copyright © 2018年 SZW. All rights reserved.
//

#include <iostream>
#include "14_4_studenti.hpp"

//私有方法
std::ostream & Student::arr_out(std::ostream & os) const{
    int i;
    int lim=int(ArrayDb::size());       //作用域解析运算符,访问基类公有方法
    if(lim>0){
        for(i=0;i<lim;++i){
            os<<ArrayDb::operator[](i)<<" ";
            if(i%5==4)
                os<<std::endl;
        }
        if(i%5!=0)
            os<<std::endl;
    }
    else
        os<<" empty array ";
    return os;
}

//普通方法
double Student::Average()const{
    if (ArrayDb::size()>0){
        return ArrayDb::sum()/ArrayDb::size();  //使用作用域解析运算符来调用私有继承的公有方法,访问基类方法
    }
    else{
        return 0;
    }
}
const std::string & Student::Name()const{
    return (const std::string &)*this;  //使用强制类型转换,将派生类对象转换为string对象,访问基类对象
}
double & Student::operator[](int i){
    return ArrayDb::operator[](i);
}
double Student::operator[](int i)const{
    return ArrayDb::operator[](i);
}

//友元函数
std::istream & operator>>(std::istream & is, Student & s){
    is>>(std::string &)s;   //使用强制类型转换来访问基类的友元函数
    return is;
}
std::istream & getline(std::istream & is, Student & s){
    getline(is, (std::string &)s);
    return is;
}
std::ostream & operator<<(std::ostream & os, const Student & s){
    os<<(const std::string &)s<<std::endl;
    s.arr_out(os);
    return os;
}
