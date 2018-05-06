//10.12
#include<iostream>
#include"stack.h"
#include<cctype>

int main()
{
	using namespace std;
	Stack st;
	char ch;
	unsigned long po;
	cout<<"Please enter A to add a purchase order,\n"
	<<"P to process a PO, Q to quit.\n";
	while(cin>>ch && toupper(ch)!='Q')
	{
		while(cin.get()!='\n')
		{
			//cin.clear();
			continue;
		}
		//如果输入的不是字母,继续下轮循环,接着输入,直到为字母
		if(!isalpha(ch))
		{
			cout<<"\a";
			continue;
		}
		switch(ch)
		{
			case 'A':
			case 'a':	cout<<"输入: ";
						cin>>po;
						if(st.isfull())
							cout<<"栈满\n";
						else
							st.push(po);
						break;

			case 'P':
			case 'p':	if(st.isempty())
							cout<<"栈空\n";
						else
						{
							st.pop(po);
							cout<<"出栈元素为: "<<po<<endl;
						}
						break;
		}
	cout<<"Please enter A to add a purchase order,\n"
		<<"P to process a PO, Q to quit.\n";
	}
	cout<<"Bye/n";
}
