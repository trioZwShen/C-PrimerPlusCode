#include<iostream>

double betsy(int);
double pam(int);
void estimate(int lines,double(*pf)(int))
{
	std::cout<<lines<<" line will take ";
	std::cout<<(*pf)(lines)<<" hour(s)\n";
}

int main()
{
	using namespace std;
	estimate(10,betsy);
	estimate(10,pam);
}

double betsy(int lns)
{
	return 0.05*lns;
}
double pam(int lns)
{
	return 0.03*lns+0.0004*lns*lns;
}