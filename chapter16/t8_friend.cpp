#include<iostream>
#include<set>
#include<string>
#include<algorithm>
#include<iterator>

int main()
{
	using namespace std;

	//Mat's friends
	set<string> mat;
	cout<<"Enter Mat's firends' name (q to quit): \n";
	string name;
	while(cin>>name && name!="q")
	{
		mat.insert(name);
		cout<<"The next one: ";
	}
	
	//Pat's friends
	set<string> pat;
	cout<<"Enter Pat's firends' name (q to quit): \n";
	while(cin>>name && name!="q")
	{
		pat.insert(name);
		cout<<"The next one: ";
	}

	//邀请的朋友
	set<string> all_friend;
	set_union(mat.begin(),mat.end(),pat.begin(),pat.end(),
		insert_iterator<set<string>>(all_friend,all_friend.begin()));


	//输出朋友
	cout<<"Mat's firends: \n";
	copy(mat.begin(),mat.end(),ostream_iterator<string,char>(cout," "));
	cout<<endl;
	cout<<"Pat's firends: \n";
	copy(pat.begin(),pat.end(),ostream_iterator<string,char>(cout," "));
	cout<<endl;
	cout<<"ALL firends: \n";
	copy(all_friend.begin(),all_friend.end(),ostream_iterator<string,char>(cout," "));
	cout<<endl;

	return 0;
}