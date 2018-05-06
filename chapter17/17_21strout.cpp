#include<iostream>
#include<sstream>
#include<string>

int main()
{
	using namespace std;
	ostringstream outstr;
	double price=380.0;
	char * ps="for a copy of the ISO/EIC C++ standard!";
	outstr.precision(2);
	outstr<<fixed;
	outstr<<"Pay only CHF "<<price<<ps<<endl;
	return 0;

}