#include<iostream>
#include<string>
#include<cctype>
#include<iterator>
#include<algorithm>

char toLower(char ch)	{return tolower(ch);}
bool IsNotAlpha(char ch)	{return !isalpha(ch);}

int main()
{
	using namespace std;
	cout<<"Please enther a words (q to quit): \n";
	string st;

	while(getline(cin,st) && st!="q")
	{
		string temp1,temp2;
		//化成小写
		transform(st.begin(),st.end(),st.begin(),toLower);
		//去掉多余字符,取反送至temp1
		remove_copy_if(st.rbegin(),st.rend(),insert_iterator<string>(temp1,temp1.begin()),IsNotAlpha);
		//将正向的送至temp2
		copy(temp1.rbegin(),temp1.rend(),insert_iterator<string>(temp2,temp2.begin()));
		//输出temp1和temp2
		copy(temp1.begin(),temp1.end(),ostream_iterator<char,char>(cout,""));
		cout<<endl;
		copy(temp2.begin(),temp2.end(),ostream_iterator<char,char>(cout,""));
		cout<<endl;
		//判断
		if(temp2.compare(temp1))
			cout<<"False!\n";
		else
			cout<<"True!\n";
		cout<<"Again: ";
	}
	return 0;
}

