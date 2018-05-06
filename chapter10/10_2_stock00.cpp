#include<iostream>
#include"10_1_stock00.hpp"

void Stock::acquire(const std::string & co,long n,double pr)	//设置参数
{
	company=co;
	if(n<0)
	{
		std::cout<<"Number of shares can't be negative;"
		<<company<<" shares set to 0.\n";

		shares=0;
	}
	else
		shares=n;
	share_val=pr;
	set_tot();
}
void Stock::buy(long num,double price)
{
	if(num<0)
	{
		std::cout<<"Number of shares purchased can't be negative. "
			<<"Transaction is aborted.\n";
	}
	else	//买进
	{
		shares+=num;
		share_val=price;
		set_tot();
	}
}
void Stock::sell(long num,double price)
{
	if(num>shares)
	{
		std::cout<<"你没有那么多\n";
	}
	else
	{
        shares-=num;
        share_val=price;
        set_tot();
	}
}
void Stock::updata(double price)
{
	share_val=price;
    set_tot();
}
void Stock::show()
{
	std::cout<<"Company: "<<company<<std::endl;
	std::cout<<"Shares: "<<shares<<std::endl;
	std::cout<<"Share Price: "<<share_val<<std::endl;
	std::cout<<"Total Worth: "<<total_val<<std::endl;
}
