#include<iostream>
#include<cstring>
int main()
{
	using namespace std;
	const char * state1="Florida";	//指针常量,即指针是一个常量,但是指向的不是常量
	const char * state2="Kansas";
	const char * state3="Euphoria";

	int len=strlen(state2);
	cout<<"Increasing loop index:\n";
	int i;
	for(i=1;i<=len;i++)
		cout.write(state2,i)<<endl;

	cout<<"Decreasing loop index:\n";
	for(i=len;i>=1;i--)
		cout.write(state2,i)<<endl;

	cout<<"Exceeding string length:\n";
	cout.write(state2,len+5)<<endl;

	cout<<endl;
	long val=560031841;
	cout.write((char *)&val,sizeof(long))<<endl;
	return 0;
}