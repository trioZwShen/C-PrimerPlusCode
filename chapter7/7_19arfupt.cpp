#include<iostream>

const double * f1(const double ar[], int n);
const double * f2(const double *ar, int n);
const double * f3(const double *, int);

int main()
{
	using namespace std;
	double av[3]={1112.3,1542.6,2227.9};

	const double *(*p1)(const double *,int)=f1;
	auto p2=f2;
	auto p3=f3;

	
	

}


const double * f1(const double ar[], int n)
{
	return ar;
}

const double * f2(const double *ar, int n)
{
	return ar+1;
}
const double * f3(const double *, int)
{
	return ar+2;
}