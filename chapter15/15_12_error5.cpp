//本例,讲解了栈解退机制.

#include<iostream>
#include<cmath>
#include<string>
#include"15_10_exc_mean.h"

using namespace std;

class demo	//用作中间函数的类,目的是看出栈解退的全过程
{
private:
	string word;
public:
	demo(const string & str)
	{
		word=str;
		cout<<"demo "<<word<<" created\n";
	}
	~demo()
	{
		cout<<"demo "<<word<<" destroyed"<<endl;
	}
	void show()const
	{
		cout<<"demo "<<word<<" lives!"<<endl;
	}
};

double hmean(double a,double b);
double gmean(double a,double b);
double means(double a,double b);

int main()
{
	double x,y,z;
	{
		demo d1("found in block in main()");
		cout<<"Enter two numbers:";
		while(cin>>x>>y)
		{
			try
			{
				z=means(x,y);
				cout<<"The mean of "<<x<<" and "<<y<<" is "<<z<<endl;
				cout<<"Enter next pair:";
			}
			catch(bad_hmean & bh)
			{
				bh.mesg();
				cout<<"Try again\n";
				continue;
			}
			catch(bad_gmean & bg)
			{
				cout<<bg.mesg();
				cout<<"Values used: "<<bg.v1<<", "<<bg.v2<<endl;
				cout<<"Sorry"<<endl;
				break;
			}
		}
		d1.show();
	}
	cout<<"Bye!\n";
	return 0;
}

double hmean(double a,double b)
{
	if (a==-b)
		throw bad_hmean(a,b);
	return 2.0*a*b/(a+b);
}
double gmean(double a,double b)
{
	if(a<0||b<0)
		throw bad_gmean(a,b);
	return std::sqrt(a * b);
}
double means(double a,double b)
{
	double am,hm,gm;
	demo d2("found in means()");
	am=(a+b)/2.0;
	try
	{
		hm=hmean(a,b);
		gm=gmean(a,b);
	}
	catch(bad_hmean & bh)
	{
		bh.mesg();
		cout<<"Caught in means()\n";
		throw;		//终止means,返回main,调用main中的catch异常,由于没有指出类型,所以调用第一个catch
	}
	d2.show();
	return (am+hm+gm)/3.0;
} 