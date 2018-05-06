//
//  Workermi.hpp
//  chapter-14
//
//  Created by SZW on 2017/9/20.
//  Copyright © 2017年 SZW. All rights reserved.
//

#ifndef Workermi_hpp
#define Workermi_hpp

#include <stdio.h>
#include<string>
class Worker    /*ABC Class*/
{
private:
    std::string fullname;
    long id;
protected:                          //Show()和Set()的辅助方法
    virtual void Data()const;
    virtual void Get();
public:
    Worker():fullname("no one"),id(0L){}
    Worker(const std::string & s,long n):fullname(s),id(n){}
    virtual ~Worker()=0;
    virtual void Set()=0;
    virtual void Show()const=0;
};

class Waiter:public virtual Worker  /*派生类1*/
{
private:
    int panache;
protected:
    void Data()const;
    void Get();
public:
    Waiter():Worker(),panache(0){}
    Waiter(const std::string & s,long n,int m=0):Worker(s,n),panache(m){}
    Waiter(const Worker & w,int m=0):Worker(w),panache(m){}
    void Set();
    void Show()const;
};

class Singer:public virtual Worker  /*派生类2*/
{
protected:
    enum{other,alto,contralto,soprano,bass,baritone,tenor};
    enum{Vtypes=7};
    void Data()const;
    void Get();
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

class SingingWaiter:public Singer,public Waiter /*MI派生类*/
{
protected:
    void Data()const;
    void Get();
public:
    SingingWaiter(){}
    SingingWaiter(const std::string & s,long n,int p=0,int v=other):
    Worker(s,n),Waiter(s,n,p),Singer(s,n,v){}
    SingingWaiter(const Worker &wk,int p=0,int v=other):
    Worker(wk),Waiter(wk,p),Singer(wk,v){}
    SingingWaiter(const Waiter & wa,int v=other):
    Worker(wa),Waiter(wa),Singer(wa,v){}
    SingingWaiter(const Singer ws,int p=0):
    Worker(ws),Waiter(ws,p),Singer(ws){}
    
    void Set();
    void Show()const;
};
#endif /* Workermi_hpp */
