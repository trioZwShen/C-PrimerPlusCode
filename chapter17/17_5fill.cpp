#include<iostream>

int main()
{
	using namespace std;
	cout.fill('*');
	//创建常量指针数组,分别指向如下字符串
	const char * staff[2]={"waldo whiosnade","wilmarie wooper"};
	long bonus[2]={900,1350};

	for(int i=0;i<2;i++)
	{
		cout<<staff[i]<<": $";
		cout.width(7);
		cout<<bonus[i]<<endl;
	}
	return 0;
}