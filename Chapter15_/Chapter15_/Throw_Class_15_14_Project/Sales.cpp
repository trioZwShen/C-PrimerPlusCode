#include <iostream>
#include <string>
#include "sales.hpp"


/*Sales类*/
//嵌套类bad_index类的构造函数
Sales::bad_index::bad_index(int ix, const std::string & s)
    :std::logic_error(s),bi(ix){
}

//Sales类的构造函数
Sales::Sales(int yy){
	year=yy;
	for(int i=0;i<MOUTHS;++i)
		gross[i]=0;
}
//Sales类的构造函数
Sales::Sales(int yy, const double * gr, int n){
	year=yy;
	int len=n>MOUTHS?MOUTHS:n;
	int i;
	for(i=0;i<len;++i)
		gross[i]=gr[i];
	for(;i<MOUTHS;++i)
		gross[i]=0;
}

double Sales::operator[](int i)const{
	if(i<0 || i>=MOUTHS)
		throw bad_index(i);
	return gross[i];
}
double & Sales::operator[](int i){
	if(i<0 || i>=MOUTHS)
		throw bad_index(i);
	return gross[i];
}

/*LabelSales类*/
LabeledSales::nbad_index::nbad_index(const std::string & lb, int ix,
			 const std::string & s)
	:bad_index(ix,s),lbl(lb){}


LabeledSales::LabeledSales(const std::string & lb,
	 int yy):Sales(yy){
	label=lb;
}


LabeledSales::LabeledSales(const std::string & lb, 
		int yy, const double * gr, int n):Sales(yy,gr,n){
	label=lb;
}

double LabeledSales::operator[](int i)const{
	if(i<0 || i>MOUTHS)
		throw nbad_index(Label(),i);
	return Sales::operator[](i);
}
double & LabeledSales::operator[](int i){
	if(i<0 || i>MOUTHS)
		throw nbad_index(Label(),i);
	return Sales::operator[](i);
}

