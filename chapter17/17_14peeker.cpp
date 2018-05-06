#include<iostream>

int main()
{
	using namespace std;
	char ch;
	while(cin.get(ch))	//直到文件尾
	{
		if(ch!='#')
			cout<<ch;
		else
		{
			cin.putback(ch);
			break;
		}
	}
	if(!cin.eof())	//判断不是因为文件尾而跳出循环
	{
		cin.get(ch);
		cout<<endl<<ch<<" is next input character.\n";
	}
	else
	{
		cout<<"End of file reached.\n";
		std::exit(0);
	}

	while(cin.peek()!='#')	
	{
		cin.get(ch);
		cout<<ch;
	}
	if(!cin.eof())
	{
		cin.get(ch);
		cout<<endl<<ch<<" is next input character.\n";
	}
	else
		cout<<"End of file reached.\n";
	return 0;
}