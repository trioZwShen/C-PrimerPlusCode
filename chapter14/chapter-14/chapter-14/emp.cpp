//
//  emp.cpp
//  chapter-14
//
//  Created by SZW on 2017/9/26.
//  Copyright © 2017年 SZW. All rights reserved.
//

#include "emp.hpp"
using std::cout;
using std::cin;
using std::endl;
/*抽象类方法*/
abstr_emp::abstr_emp()
{}
abstr_emp::abstr_emp(const std::string & fn,const std::string & ln,const std::string & j)
:fname(fn),lname(ln),job(j){}
void abstr_emp::ShowAll()const
{
    cout<<fname<<" * "<<lname<<endl;
    cout<<"JOB: "<<job<<endl;
}
void abstr_emp::SetAll()
{
    cout<<"Enter Your FirstName:";
    cin>>fname;
    cout<<"Enter Your LastName:";
    cin>>lname;
    cout<<"Enter Your Job:";
    cin>>job;
}
std::ostream & operator<<(std::ostream & os,const abstr_emp &e)
{
    os<<e.fname<<" "<<e.lname<<" "<<e.job;
    return os;
}
abstr_emp::~abstr_emp()
{}

/*普通公有继承*/
employee::employee(){}
employee::employee(const std::string & fn,const std::string & ln,const std::string & j)
:abstr_emp(fn,ln,j){}
void employee::ShowAll()const
{
    abstr_emp::ShowAll();
}
void employee::SetAll()
{
    abstr_emp::SetAll();
}

/*虚基类公有继承manager*/
manager::manager(){}
manager::manager(const std::string & fn,const std::string & ln,const std::string & j,int ico)
:abstr_emp(fn,ln,j),inchargeof(ico){}
manager::manager(const abstr_emp & e,int ico)
:abstr_emp(e),inchargeof(ico){}
manager::manager(const manager & m)
:abstr_emp(m),inchargeof(m.inchargeof){}
void manager::ShowAll()const
{
    abstr_emp::ShowAll();
    cout<<"INCHARGEOF: "<<inchargeof<<endl;
}
void manager::SetAll()
{
    abstr_emp::SetAll();
    cout<<"Enter the inchargeof:";
    cin>>inchargeof;
}

/*虚基类公有继承fink*/
fink::fink()
{}
fink::fink(const std::string & fn,const std::string & ln,const std::string & j,const std::string rpo)
:abstr_emp(fn,ln,j),reportsto(rpo){}
fink::fink(const abstr_emp & e,const std::string rpo)
:abstr_emp(e),reportsto(rpo){}
fink::fink(const fink & e)
:abstr_emp(e),reportsto(e.reportsto){}
void fink::ShowAll()const
{
    abstr_emp::ShowAll();
    cout<<"REPORTSTO: "<<reportsto<<endl;
}
void fink::SetAll()
{
    abstr_emp::SetAll();
    cout<<"Enter the reportsto:";
    cin>>reportsto;
}

/*MI*/
highfink::highfink(){}
highfink::highfink(const std::string & fn,const std::string & ln,const std::string & j,const std::string rpo,int ico)
:abstr_emp(fn,ln,j),manager(fn,ln,j,ico),fink(fn,ln,j,rpo){}
highfink::highfink(const abstr_emp &e,const std::string & rpo,int ico)
:abstr_emp(e),manager(e,ico),fink(e,rpo){}
highfink::highfink(const manager & e,const std::string & rpo)
:abstr_emp(e),manager(e),fink(e,rpo){}
highfink::highfink(const fink & e,int ico)
:abstr_emp(e),manager(e,ico),fink(e){}
highfink::highfink(const highfink & e)
:abstr_emp(e),manager(e),fink(e){}
void highfink::ShowAll()const
{
    manager::ShowAll();
    cout<<"REPORTSTO: "<<ReportsTo()<<endl;
}
void highfink::SetAll()
{
    manager::SetAll();
    cout<<"Enter the reportsto:";
    cin>>ReportsTo();
}
