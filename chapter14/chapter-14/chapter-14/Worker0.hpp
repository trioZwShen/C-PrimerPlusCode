//
//  Worker0.hpp
//  chapter-14
//
//  Created by SZW on 2017/9/20.
//  Copyright © 2017年 SZW. All rights reserved.
//

#ifndef Worker0_hpp
#define Worker0_hpp

#include <stdio.h>
#include<string>
class Worker    /*ABC Class*/
{
private:
    std::string fullname;
    long id;
public:
    Worker():fullname("no one"),id(0L){}
    Worker(const std::string & s,long n):fullname(s),id(n){}
    virtual ~Worker()=0;    //纯虚析构函数
    virtual void Set();
    virtual void Show()const;
};

class Waiter:public Worker  /*派生类1*/
{
private:
    int panache;
public:
    Waiter():Worker(),panache(0){}
    Waiter(const std::string & s,long n,int m=0):Worker(s,n),panache(m){}
    Waiter(const Worker & w,int m=0):Worker(w),panache(m){}
    void Set();
    void Show()const;
};

class Singer:public Worker  /*派生类2*/
{
protected:
    enum{other,alto,contralto,soprano,bass,baritone,tenor};
    enum{Vtypes=7};
private:
    static char *pv[Vtypes];
    int voice;
public:
    Singer():Worker(),voice(other){}
    Singer(const std::string & s,long n,int m=other):Worker(s,n),voice(m){}
    Singer(const Worker & w,int m=other):Worker(w),voice(m){}
    void Set();
    void Show()const;
};
#endif /* Worker0_hpp */
