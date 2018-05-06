#include<iostream>

int main()
{
	using namespace std;
	char ch;
	int ct1,ct2;
	ct1=ct2=0;
	int *p=&ct1;
	cout<<*p<<" "<<ct2<<endl;
	return 0;
}