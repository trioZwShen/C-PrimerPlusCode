//
//  dma.hpp
//  chapter13
//
//  Created by SZW on 2017/8/24.
//  Copyright © 2017年 SZW. All rights reserved.
//

#ifndef dma_hpp
#define dma_hpp

#include <stdio.h>
#include<iostream>
class baseDMA       //基类
{
private:
    char * label;
    int rating;
public:
    baseDMA(const char * l ="null",int r=0);
    baseDMA(const baseDMA & rs);
    virtual ~baseDMA();
    baseDMA & operator=(const baseDMA & rs);
    friend std::ostream & operator<<(std::ostream & os,const baseDMA & rs);
};

class lacksDMA : public baseDMA         //不使用new的派生类示例
{
private:
    enum{COL_LEN=40};
    char color[COL_LEN];
public:
    lacksDMA(const char * c="blank",const char * l ="null",int r=0);
    lacksDMA(const char * c,const baseDMA & rs);
    friend std::ostream & operator<<(std::ostream & os,const lacksDMA & rs);
};

class hasDMA:public baseDMA                 //使用new的派生类示例
{
private:
    char * style;
public:
    hasDMA(const char * s="none",const char * l ="null",int r=0);   //构造函数
    hasDMA(const char * s,const baseDMA & rs);                      //构造函数
    hasDMA(const hasDMA & hs);                                      //复制构造函数
    ~hasDMA();                                                      //析构函数
    hasDMA & operator=(const hasDMA & rs);                          //重载赋值运算符
    friend std::ostream & operator<<(std::ostream & os,const hasDMA & rs);
};

#endif /* dma_hpp */
