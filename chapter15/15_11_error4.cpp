#include<iostream>
#include<cmath>
#include<stdexcept> //异常类的头文件
#include"15_10_exc_mean.h"

using namespace std;
class Bgmean : public logic_error
{
private:
    int a;
    int b;
public:
    Bgmean(int x,int y,char * s):a(x),b(y),logic_error(s){}
    void Show()const{cout<<a<<" "<<b<<endl;}
};
class Bhmean : public logic_error
{
private:
    int a;
    int b;
public:
    Bhmean(int x,int y,char * s):a(x),b(y),logic_error(s){}
    void Show()const{cout<<a<<" "<<b<<endl;}
};


double hmean(double a,double b);
double gmean(double a,double b);
int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	double x,y,z;
	cout<<"Enter two numbers: ";
	while(cin>>x>>y)
	{
		try
		{
			z=hmean(x,y);
			cout<<"The hmean is "<<z<<endl;
			cout<<"The gmean is "<<gmean(x,y)<<endl;
		}
		catch(Bhmean & bh)
		{
			cout<<bh.what()<<endl;
            bh.Show();
            break;
		}
		catch(Bgmean & bg)
		{
			cout<<bg.what()<<endl;
            bg.Show();
			break;
		}
		cout<<"Enter enter enter: ";
	}
	cout<<"Bye!";
	return 0;
}

double hmean(double a,double b)
{
	if (a==-b)
        throw Bhmean(a,b,"hmean()");
	return 2.0*a*b/(a+b);
}
double gmean(double a,double b)
{
	if(a<0||b<0)
        throw Bgmean(a,b,"hmean()");
	return std::sqrt(a * b);
}
