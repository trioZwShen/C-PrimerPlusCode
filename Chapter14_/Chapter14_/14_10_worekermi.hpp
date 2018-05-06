//
//  14_10_worekermi.hpp
//  Chapter14_
//
//  Created by SZW on 2018/3/4.
//  Copyright © 2018年 SZW. All rights reserved.
//

#ifndef _4_10_worekermi_hpp
#define _4_10_worekermi_hpp

#include <stdio.h>
#include <iostream>
#include <string>

/*抽象基类*/
class Worker{
protected:
    //保护成员
    virtual void subShow()const;                                //辅助函数
    virtual void subSet();
private:
    std::string fullname;   //姓名
    long id;                //ID
public:
    //构造函数与析构函数
    Worker():fullname("no one"),id(0L){}                        //1.1默认构造函数
    Worker(const std::string & s, long n):fullname(s),id(n){}   //1.2构造函数
    virtual ~Worker()=0;                                        //1.3纯虚析构函数
    //普通公有方法
    virtual void Show() const=0;                                //1.4虚函数
    virtual void Set()=0;                                       //1.5虚函数
};

/*第一层派生*/
/*派生类1,虚基类派生*/
class Waiter: virtual public Worker{
protected:
    virtual void subShow()const;                                //辅助函数
    virtual void subSet();
private:
    int panache;
public:
    //构造函数
    Waiter():Worker(),panache(0){}                              //2.1默认构造函数
    Waiter(const std::string & s, long n, int pan=0)            //2.2构造函数
        :Worker(s,n),panache(pan){}
    Waiter(const Worker & wk, int pan=0)                        //2.3构造函数
        :Worker(wk),panache(pan){}
    //普通公有方法
    virtual void Show() const;                                  //2.4虚函数
    virtual void Set();                                         //2.5虚函数
};

/*派生类2,虚基类派生*/
class Singer:virtual public Worker{
protected:
    virtual void subShow()const;                                //辅助函数
    virtual void subSet();
    enum{other,alto,contralto,soprano,bass,baritone,tenor};     //枚举类型,静态
    enum{Vtypes=7};                                             //枚举类型,静态
private:
    static char * pv[Vtypes];                                   //静态数据成员
    int voice;
public:
    //构造函数
    Singer():Worker(),voice(0){}                                //3.1默认构造函数
    Singer(const std::string & s, long n, int v=other)          //3.2构造函数
        :Worker(s,n),voice(v){}
    Singer(const Worker & wk, int v=other)                      //3.3构造函数
        :Worker(wk),voice(v){}
    //普通公有方法
    virtual void Show() const;                                  //3.4虚函数
    virtual void Set();                                         //3.5虚函数
};

/*第二层派生*/
/*MI多重继承*/
class SingingWaiter: public Waiter, public Singer{
protected:
    virtual void subShow()const;                                //辅助函数
    virtual void subSet();
public:
    //构造函数
    SingingWaiter():Worker(),Waiter(),Singer(){}                //4.1默认构造函数,显示调用下层,也可以隐式
    SingingWaiter(const std::string & s, long n, int pan=0, int v=other)
        :Worker(s,n),Waiter(s,n,pan),Singer(s,n,v){}            //4.2构造函数
    SingingWaiter(const Worker & wk, int pan=0, int v=other)    //4.3构造函数
        :Worker(wk),Waiter(wk,pan),Singer(wk,v){}
    SingingWaiter(const Waiter & wa, int v=other)               //4.3构造函数,其中wa虽然是Waiter的引用
        :Worker(wa),Waiter(wa),Singer(wa,v){}                   //但是wa可以被隐式转换为Worker的引用
    SingingWaiter(const Singer & sg, int pan=0)                 //4.4构造函数,与上同理
        :Worker(sg),Waiter(sg,pan),Singer(sg){}
    //普通公有方法
    virtual void Show() const;                                  //3.4虚函数
    virtual void Set();                                         //3.5虚函数
};
#endif /* _4_10_worekermi_hpp */
