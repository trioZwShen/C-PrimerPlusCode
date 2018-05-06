#include<iostream>
#include<iomanip>

int main()
{
	using namespace std;
	int x=11;
	cout<<showbase
		<<setw(15)<<dec<<x
		<<setw(15)<<oct<<x
		<<setw(15)<<hex<<x<<endl;
	return 0;
}