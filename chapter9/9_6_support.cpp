#include<iostream>

extern double warming;
using namespace std;
void updata()
{
	warming+=0.1;
	cout<<warming<<endl;
}

void local()
{
	double warming=0.8;
	cout<<warming<<endl;
	cout<<::warming<<endl;
}