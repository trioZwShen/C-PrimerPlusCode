#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>

const char * file ="guest.txt";
int main()
{
	using namespace std;
	char ch;
	ifstream fin;//创建文本输入对象
	fin.open(file);//将该对象与文件file关联

	if(fin.is_open())//检查文件是否存在, 若已存在
	{
		cout<<"Here are the current contents of the "
			<<file<<" file:\n";
		while(fin.get(ch))
		{
			cout<<ch;
		}
		fin.close();
	}

	//创建文本输出对象,并初始化与file文件相连, 且设置模式为写入,并追加到文件尾
	ofstream fout(file,ios_base::out|ios_base::app);
	if(!fout.is_open())	//若打开失败
	{
		cerr<<"Can't open "<<file<<" file for output.\n";
		exit(0);
	}

	cout<<"Enter guest names (enter a blank line to quit):\n";
	string name;
	while(getline(cin,name)&&name.size()>0)
	{
		fout<<name<<endl;
	}
	fout.close();

	fin.clear();
	fin.open(file);
	if(fin.is_open())
	{
		cout<<"Here are the new contents of the "<<file<<" file:\n";
		while(fin.get(ch))
			cout<<ch;
		fin.close();
	}
	cout<<"Done.\n";
	return 0;




}
