//
//  t1_Cow.hpp
//  chapter12
//
//  Created by SZW on 2018/2/5.
//  Copyright © 2018年 SZW. All rights reserved.
//

#ifndef t1_Cow_hpp
#define t1_Cow_hpp
#include <iostream>
#include <stdio.h>

class Cow{
private:
    char _name[20];
    char * _hobby;
    double _weight;
public:
    //构造函数1,默认构造函数
    Cow();
    //构造函数2
    Cow(const char * nm, const char * ho, double wt);
    //构造函数3,复制构造函数
    Cow(const Cow &c);
    //析构函数
    ~Cow();
    //重载赋值运算符
    Cow & operator=(const Cow & c);
    //显示类
    void ShowCow()const;
    
};
#endif /* t1_Cow_hpp */
