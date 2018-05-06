#include<iostream>
#include<string>
int main()
{
	using namespace std;
	double x=11.0;
	cout.setf(ios_base::showpoint);
	cout.setf(ios_base::scientific);
	cout.precision(5);
	cout<<x<<endl;
	return 0;
}