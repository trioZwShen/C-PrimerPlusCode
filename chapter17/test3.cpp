#include<iostream>
#include<iomanip>
#include<string>
int main()
{
	using namespace std;
	cout<<"Enter your name: ";
	string name;
	getline(cin,name);

	cout<<"Enter your hourly wages: ";
	float wage;
	cin>>wage;

	cout<<"Enter number of hours worked: ";
	float hours;
	cin>>hours;

	cout<<showpoint<<"First format: \n";
	cout<<setw(20)<<name<<": $"
		<<setw(10)<<setprecision(4)<<wage<<":"
		<<setw(10)<<setprecision(2)<<hours<<endl;

	cout<<"Second format: \n";
	cout<<left<<setw(20)<<name<<": $"
		<<setw(10)<<setprecision(4)<<wage<<":"
		<<setw(10)<<setprecision(2)<<hours<<endl;

	return 0;
}