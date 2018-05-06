#ifndef 10_1_stock00_hpp
#define 10_1_stock00_hpp

#include<string>

class Stock
{
private:
	std::stirng company;
	long shares;
	double share_val;
	double total_val;
	void set_tot(){total_val=shares*share_val;}	//类中定义的函数默认为内敛函数
public:
	void acquire(const std::string & co,long n,double pr);
	void buy(long num,double price);
	void sell(long num,double price);
	void updata(double price);
	void show();
};
#end_if