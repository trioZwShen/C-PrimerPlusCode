#include<iostream>
#include<exception>
#include<cctype>
int main()
{
	using namespace std;
	cout<<"Enter numbers: ";
	cin.exceptions(ios_base::failbit);
	int sum=0;
	int input;
	while(cin>>input)
	{
		sum+=input;
	}
	if(cin.fail()&&!cin.eof())
	{
		cin.clear();
		while(cin.get()!='\n')
			continue;
	}
	else	//到达文件尾
	{
		cout<<"I can not go on!\n";
	}
	cout<<"Last value entered = "<<input<<endl;
	cout<<"Sum = "<<sum<<endl;
	int x;
	cin>>x;
	cout<<x<<endl;
	return 0;
}