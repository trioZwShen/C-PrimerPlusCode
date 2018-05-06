#include<iostream>
#include<string>
#include<cctype>
#include<iterator>

int main()
{
	using namespace std;
	cout<<"Please enther a words (q to quit): \n";
	string st;
	while(cin>>st && st!="q")
	{
		string temp;
		copy(st.rbegin(),st.rend(),insert_iterator<string>(temp,temp.begin()));
		//copy(temp.begin(),temp.end(),ostream_iterator<char,char>(cout,""));
		if(st.compare(temp))
			cout<<"False!\n";
		else
			cout<<"True!\n";
		cout<<"Again: ";
	}
	return 0;
}