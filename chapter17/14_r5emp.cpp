#include<iostream>
#include<string>
#include"14_t5emp.h"

//abstr_emp的方法
abstr_emp::abstr_emp()
{
	fname="FFF";
	lname="LLL";
	job="JJJ";
}
abstr_emp::abstr_emp(const std::string & fn, const std::string & ln, 
		const std::string & j)
{
	fname=fn;
	lname=ln;
	job=j;
}
void abstr_emp::ShowAll() const
{
	std::cout<<"First name: "<<fname<<std::endl;
	std::cout<<"Last name:  "<<lname<<std::endl;
	std::cout<<"Job:        "<<job<<std::endl;
	
}	
void abstr_emp::SetAll()
{
	std::cout<<"Please enter your first name: ";
	getline(std::cin,fname);
	std::cout<<"Please enter your last name: ";
	getline(std::cin,lname);
	std::cout<<"Please enter your job: ";
	getline(std::cin,job);
}

abstr_emp::~abstr_emp(){}

void abstr_emp::WriteAll(std::ofstream & os) const
{
    os<<fname<<std::endl;   //存入数据
    os<<lname<<std::endl;
    os<<job<<std::endl;
}

void abstr_emp::GetAll(std::ifstream & is)
{
    getline(is,fname);
    getline(is,lname);
    getline(is,job);
}

std::ostream & operator<<(std::ostream & os,
		const abstr_emp & e)
{
	os<<"First name: "<<e.fname<<" & Last name:  "<<e.lname;
	return os;
}


//employee方法定义
employee::employee():abstr_emp()
{}
employee::employee(const std::string & fn, const std::string & ln,
		const std::string & j):abstr_emp(fn,ln,j)
{}
void employee::ShowAll()const
{
	abstr_emp::ShowAll();
}
void employee::SetAll()
{
	abstr_emp::SetAll();
}

void employee::WriteAll(std::ofstream & os) const
{
    os<<'e'<<std::endl;   //首先写入标志位,并换行
    abstr_emp::WriteAll(os);
}
void employee::GetAll(std::ifstream & is)
{
    abstr_emp::GetAll(is);
}

//manager方法定义
manager::manager():abstr_emp(),inchargeof(0)
{}
manager::manager(const std::string & fn, const std::string & ln,
	const std::string & j, int ico)
	:abstr_emp(fn,ln,j),inchargeof(ico)
{}
manager::manager(const abstr_emp & e, int ico)
	:abstr_emp(e),inchargeof(ico)
{}
manager::manager(const manager & m)
	:abstr_emp(m),inchargeof(m.inchargeof)
{}
void manager::ShowAll()const
{
	abstr_emp::ShowAll();
	std::cout<<"inchargeof: "<<inchargeof<<std::endl;
}
void manager::SetAll()
{
	abstr_emp::SetAll();
	std::cout<<"Please enter your inchargeof: ";
	(std::cin>>inchargeof).get();
    
}

void manager::WriteAll(std::ofstream & os) const
{
    os<<'m'<<std::endl;   //首先写入标志位,并换行
    abstr_emp::WriteAll(os);
    os<<inchargeof<<std::endl;
}

void manager::GetAll(std::ifstream & is)
{
    abstr_emp::GetAll(is);
    (is>>inchargeof).get();
}

//fink方法定义
fink::fink():abstr_emp(),reportsto("RRR")
{}
fink::fink(const std::string & fn, const std::string & ln,
	const std::string & j, const std::string & rpo)
	:abstr_emp(fn,ln,j),reportsto(rpo)
{}
fink::fink(const abstr_emp & e, const std::string & rpo)
	:abstr_emp(e),reportsto(rpo)
{}
fink::fink(const fink & f)
	:abstr_emp(f),reportsto(f.reportsto)
{}
void fink::ShowAll()const
{
	abstr_emp::ShowAll();
	std::cout<<"reportsto:  "<<reportsto<<std::endl;
}
void fink::SetAll()
{
	abstr_emp::SetAll();
	std::cout<<"Please enter your reportsto: ";
	getline(std::cin,reportsto);
}

void fink::WriteAll(std::ofstream & os) const
{
    os<<'f'<<std::endl;   //首先写入标志位,并换行
    abstr_emp::WriteAll(os);
    os<<reportsto<<std::endl;
}

void fink::GetAll(std::ifstream & is)
{
    abstr_emp::GetAll(is);
    getline(is,reportsto);
}

//highfink方法定义
highfink::highfink()
	:abstr_emp(),manager(),fink()
{}
highfink::highfink(const std::string & fn, const std::string & ln,
	const std::string & j, const std::string & rpo,
	int ico)
	:abstr_emp(fn,ln,j),manager(fn,ln,j,ico),fink(fn,ln,j,rpo)
{}
highfink::highfink(const abstr_emp & e, const std::string & rpo,
	int ico)
	:abstr_emp(e),manager(e,ico),fink(e,rpo)
{}
highfink::highfink(const manager & m, const std::string & rpo)
	:abstr_emp(m),manager(m),fink(m,rpo)
{}
highfink::highfink(const fink & f, int ico)
	:abstr_emp(f),fink(f),manager(f,ico)
{}
highfink::highfink(const highfink & h)
	:abstr_emp(h),manager(h),fink(h)
{}
void highfink::ShowAll()const
{
    abstr_emp::ShowAll();
    std::cout<<"reportsto:  "<<ReportsTo()<<std::endl;
    std::cout<<"inchargeof: "<<InChargeof()<<std::endl;
}
void highfink::SetAll()
{
    abstr_emp::SetAll();
    std::cout<<"Please enter your reportsto: ";
    getline(std::cin,ReportsTo());
    std::cout<<"Please enter your inchargeof: ";
    (std::cin>>InChargeof()).get();
}
void highfink::WriteAll(std::ofstream & os) const
{
    os<<'h'<<std::endl;   //首先写入标志位,并换行
    abstr_emp::WriteAll(os);
    os<<ReportsTo()<<std::endl;
    os<<InChargeof()<<std::endl;
}

void highfink::GetAll(std::ifstream & is)
{
    abstr_emp::GetAll(is);
    getline(is,ReportsTo());
    (is>>InChargeof()).get();
}
