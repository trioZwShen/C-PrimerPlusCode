#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
int main()
{
	using namespace std;
	ifstream fin1,fin2;
	fin1.open("t2.txt");
	fin2.open("t3.txt");
	if(!fin1.is_open() || !fin2.is_open())
	{
		cout<<"Wrong!\n";
		exit(0);
	}

	ofstream fout;
	fout.open("t4.txt");
	string s1[10];
	string s2[10];
	int i=0;
	int j=0;
	while (getline(fin1,s1[i]))
	{
		i++;
	}
	while (getline(fin2,s2[i]))
	{
		j++;
	}
	for(int t=0;t<i || t<j;t++)
	{
		fout<<s1[t]+" "+s2[t]<<endl;
	}
	return 0;
}