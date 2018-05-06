#include<iostream>

template<typename T>
void Swap(T &a, T &b);

template<typename T>
void Swap(T a[], T b[], int n);

struct Job
{
	char name[40];
	double salary;
	int floor;
};

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

	char x[5]="szw";
	char y[5]="cyy";
	cout<<"x,y= "<<x<<", "<<y<<endl;
	Swap(x,y,3);
	cout<<"x,y= "<<x<<", "<<y<<endl;
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

template<typename T>
void Swap(T a[], T b[], int n)
{
	T temp;
	for(int i=0;i<n;i++)
	{
		temp=a[i];
		a[i]=b[i];
		b[i]=temp;
	}
}