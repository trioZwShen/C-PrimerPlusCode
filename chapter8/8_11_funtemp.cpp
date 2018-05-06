#include<iostream>

template<typename T>
void Swap(T &a, T &b);

int main()
{
	using namespace std;

	int i=10;
	int j=20;
	cout<<"i,j= "<<i<<", "<<j<<endl;
	Swap(i,j);
	cout<<"i,j= "<<i<<", "<<j<<endl;

	double a=10.0;
	double b=20.1;
	cout<<"a,b= "<<a<<", "<<b<<endl;
	Swap(a,b);
	cout<<"a,b= "<<a<<", "<<b<<endl;

	return 0;
}

template<typename T>
void Swap(T &a, T &b)
{
	T temp;
	temp=a;
	a=b;
	b=temp;
}