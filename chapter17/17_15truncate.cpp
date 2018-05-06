#include<iostream>

const int SLEN =10;
//去除多余输入
inline void eatline(){while (std::cin.get()!='\n')continue;}

int main()
{
	using namespace std;

	char name[SLEN];
	char title[SLEN];
	cout<<"Enter your name: ";
	cin.get(name, SLEN);
	if(cin.peek()!='\n')	//检查是否输入整行
		cout<<"Sorry, we only have enough room for"
			<<name<<endl;
	eatline();
	cout<<"Dear "<<name<<", enter your title: \n";
	cin.get(title,SLEN);
	if(cin.peek()!='\n')
		cout<<"We were forced to truncate your title.\n";
	eatline();
	cout<<"Name: "<<name
		<<"\nTitle: "<<title<<endl;
	return 0;
}