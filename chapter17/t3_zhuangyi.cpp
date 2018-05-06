#include<iostream>
#include<fstream>
#include<cstdlib>

int main()
{
	using namespace std;
	ifstream fin;
	fin.open("t2.txt",ios_base::in);
	if(!fin.is_open())
	{
		cout<<"Wrong\n";
		exit(0);
	}

	ofstream fout;
	fout.open("t3.txt");
	char ch;
	while(fin.get(ch))
		fout<<ch;
	cout<<endl;
	fout.close();
	fin.close();
	
	return 0;
}