#include<iostream>
double hmean(double a,double b);

using namespace std;
int main()
{
	double x,y,z;
	cout<<"Enter two numbers: ";
	while(cin>>x>>y)
	{
		try{					//try it but catch throw, then catch
			z=hmean(x,y);
		}
		catch (const char * s)	//捕获到异常
		{
			cout<<s<<endl;
			cout<<"Enter a new pair of numbers: ";
			continue;
		}
		cout<<"Harmonic mean of "<<x<<" and "<<y<<" is "<<z<<endl;
		cout<<"Enter next set of numbers <q to quit>: ";
	}
	cout<<"Bye!\n";
	return 0;
}

double hmean(double a,double b)
{
	if (a==-b)
		throw "bad hmean() arguments: a=-b not allowed";	//引发异常
	return 2.0*a*b/(a+b);
}