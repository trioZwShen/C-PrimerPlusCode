#include<iostream>
#include<fstream>
#include<string>
int main()
{
	using namespace std;
	ofstream fout;		//创建文件输出流
	fout.open("t3.txt");//将其与文件关联	
	char ch;
	cout<<"Enter the line: ";
	while(cin.get(ch))
	{
		fout<<ch;	//写入文本
	}
	fout.close();		//关闭

	return 0;
}