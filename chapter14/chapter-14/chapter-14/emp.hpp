//
//  emp.hpp
//  chapter-14
//
//  Created by SZW on 2017/9/26.
//  Copyright © 2017年 SZW. All rights reserved.
//

#ifndef emp_hpp
#define emp_hpp

#include<iostream>
#include<string>
#include <stdio.h>

class abstr_emp //抽象类
{
private:
    std::string fname;
    std::string lname;
    std::string job;
public:
    abstr_emp();
    abstr_emp(const std::string & fn,const std::string & ln,const std::string & j);
    virtual void ShowAll()const;
    virtual void SetAll();
    friend std::ostream & operator<<(std::ostream & os,const abstr_emp &e);
    virtual ~abstr_emp()=0;
};

/*普通公有继承*/
class employee :public abstr_emp
{
public:
    employee();
    employee(const std::string & fn,const std::string & ln,const std::string & j);
    virtual void ShowAll()const;
    virtual void SetAll();
};

/*虚基类公有继承*/
class manager:public virtual abstr_emp
{
private:
    int inchargeof;
protected:
    int InChargeOf()const{return inchargeof;}
    int & InChargeOf(){return inchargeof;}
public:
    manager();
    manager(const std::string & fn,const std::string & ln,const std::string & j,int ico=0);
    manager(const abstr_emp & e,int ico);
    manager(const manager & m);
    virtual void ShowAll()const;
    virtual void SetAll();
};

/*虚基类公有继承*/
class fink:public virtual abstr_emp
{
private:
    std::string reportsto;
protected:
    const std::string ReportsTo()const{return reportsto;}
    std::string & ReportsTo() {return reportsto;}
public:
    fink();
    fink(const std::string & fn,const std::string & ln,const std::string & j,const std::string rpo);
    fink(const abstr_emp & e,const std::string rpo);
    fink(const fink & e);
    virtual void ShowAll()const;
    virtual void SetAll();
};

/*MI*/
class highfink:public fink,public manager
{
public:
    highfink();
    highfink(const std::string & fn,const std::string & ln,const std::string & j,const std::string rpo,int ico);
    highfink(const abstr_emp &e,const std::string & rpo,int ico);
    highfink(const manager & e,const std::string & rpo);
    highfink(const fink & e,int ico);
    highfink(const highfink & e);
    virtual void ShowAll()const;
    virtual void SetAll();
};
#endif /* emp_hpp */
