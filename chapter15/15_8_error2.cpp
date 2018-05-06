#include<iostream>
#include<cfloat>

using namespace std;
bool hmean(double a,double b,double *c);

int main()
{
	double x,y,z;
	cout<<"Enter two numbers: ";
	while(cin>>x>>y)
	{
		if(hmean(x,y,&z))
		{
			std::cout<<"Harmonic mean of "<<x<<" and "<<y<<" is "
			<<z<<std::endl;
		}
		else
			cout<<"One value should not be the negative of the other - try again.\n";
		cout<<"Enter next set of numbers<q to quit>: ";
	}
	cout<<"Bye!\n";
	return 0;
}

bool hmean(double a,double b,double * c)
{
	if(a==-b)
	{
		*c=DBL_MAX;
		return false;
	}
	else
	{
		*c=2.0*a*b/(a+b);
		return true;
	}
}