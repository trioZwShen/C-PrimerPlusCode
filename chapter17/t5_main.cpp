#include<iostream>
#include<fstream>
#include<set>
#include<string>
#include<algorithm>
#include<iterator>

int main()
{
	using namespace std;

	ifstream fin1,fin2;	//创建两个文件输入流
	fin1.open("mat.dat");
	fin2.open("pat.dat");
	if(!fin1.is_open() || !fin2.is_open())	//检查打开与否
	{
		cout<<"Wrong!\n";
		exit(0);
	}

	string friend_name;
	set<string> mat,pat,all;
	cout<<"Mat's friend: ";
	while(getline(fin1,friend_name))
	{
		mat.insert(friend_name);
		cout<<friend_name<<endl;
	}
	cout<<"Pat's friend: ";
	while(getline(fin2,friend_name))
	{
		pat.insert(friend_name);
		cout<<friend_name<<endl;
	}
	fin1.close();fin2.close();
	set_union(mat.begin(),mat.end(),pat.begin(),pat.end(),
		insert_iterator<set<string>>(all,all.begin()));
	cout<<"\nFriends\n";
	copy(all.begin(),all.end(),ostream_iterator<string,char>(cout,"\n"));

	ofstream fout;
	fout.open("matnpat.txt");
	int i=0;
	copy(all.begin(),all.end(),ostream_iterator<string,char>(fout,"\n"));



	return 0;
}