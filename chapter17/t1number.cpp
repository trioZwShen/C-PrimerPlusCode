#include<iostream>

int main()
{
	using namespace std;
	char ch;
	cout<<"Enter a line: ";
	int num=0;
	while(cin.peek()!='$')
	{
		cout<<char(cin.peek())<<endl;
		cin.get();
		num+=1;
	}
	cout<<num<<endl;
	return 0;
}