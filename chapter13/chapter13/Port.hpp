//
//  Port.hpp
//  chapter13
//
//  Created by SZW on 2017/9/3.
//  Copyright © 2017年 SZW. All rights reserved.
//

#ifndef Port_hpp
#define Port_hpp
#include<iostream>
#include <stdio.h>
class Port
{
private:
    char * brand;
    char style[20];
    int bottles;
public:
    Port(const char * br="none",const char * st="none",int b=0);
    Port(const Port & p);
    virtual ~Port(){delete [] brand;}
    Port & operator=(const Port &p);
    Port & operator+=(int b);
    Port & operator-=(int b);
    int BottleCount()const{return bottles;}
    virtual void Show()const;
    friend std::ostream & operator<<(std::ostream & os,const Port & p);
};

class VintagePort : public Port
{
private:
    char * nickame;
    int year;
public:
    VintagePort();
    VintagePort(const char *br,const char *st,int b,const char *nn,int y);
    VintagePort(const VintagePort &vp);
    virtual ~VintagePort(){delete [] nickame;}
    VintagePort & operator=(const VintagePort &vp);
    virtual void Show() const;
    friend std::ostream & operator<<(std::ostream & os, const VintagePort & vp);
};
#endif /* Port_hpp */
