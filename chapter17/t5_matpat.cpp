#include<iostream>
#include<fstream>
#include<set>
#include<string>
#include<algorithm>
#include<iterator>

int main()
{
	using namespace std;
	ofstream fout;	//文件输出流对象

	//Mat's friends
	fout.open("mat.dat");
	cout<<"Enter Mat's firends' name (q to quit): \n";
	string name;
	while(cin>>name && name!="q")
	{
		fout<<name<<endl;
		cout<<"The next one: ";
	}
	fout.close();
	//Pat's friends
	fout.open("pat.dat");
	cout<<"Enter Pat's firends' name (q to quit): \n";
	while(cin>>name && name!="q")
	{
		fout<<name<<endl;
		cout<<"The next one: ";
	}
	fout.close();


	
	return 0;

}