//
//  13_11_acctabc.hpp
//  CHAPTER13_
//
//  Created by SZW on 2018/2/14.
//  Copyright © 2018年 SZW. All rights reserved.
//

#ifndef _3_11_acctabc_hpp
#define _3_11_acctabc_hpp
#include <iostream>
#include <string>
/*抽象基类*/
class AcctABC
{
/*私有成员*/
private:
    std::string _fullname;
    long _acctNum;
    double _balance;
/*保护成员*/
protected:
    struct Formatting   //类内声明结构类型
    {
        std::ios_base::fmtflags flag;
        std::streamsize pr;
    };
    const std::string & FullName()const {return _fullname;}
    long acctNum()const {return _acctNum;}
    Formatting setFormat()const;
    void Restore(Formatting & f)const;
/*公有成员*/
public:
    AcctABC(const std::string & fullname="Nobody", long acctNum=-1, double balance=0.0);
    void Deposit(double amt);
    virtual void withdraw(double amt)=0;    //纯虚函数
    
};

class Brass: public AcctABC
{};

class BrassPlus: public AcctABC
{};

#endif

