#include<iostream>
#include<string>
#include<set>
#include<vector>
#include<algorithm>
#include<cctype>
#include<map>
#include<iterator>

using namespace std;

void Show(const string &);
string & ToLower(string &);
char toLower(char);
int main()
{
    //输入及保存
	vector<string> word_list1;
	string word;
	cout<<"Enter a word (q to quit):";
	while(cin>>word && word!="q")
	{
		word_list1.push_back(word);
		cout<<"Enter the next word: ";
	}
	for_each(word_list1.begin(),word_list1.end(),Show);cout<<endl;

	//排序及去重及小写化
	set<string>word_list2;
	transform(word_list1.begin(), word_list1.end(),insert_iterator<set<string>>(word_list2,word_list2.begin()),ToLower);
	for_each(word_list2.begin(),word_list2.end(),Show);cout<<endl;
    
    //计数
    map<string,int>wordmap;
    set<string>::iterator si;
    for(si=word_list2.begin();si!=word_list2.end();++si)
    {
        wordmap[*si]=count(word_list1.begin(),word_list1.end(),*si);
    }
    
    //输出map
    cout<<"\n\n";
    for(si=word_list2.begin();si!=word_list2.end();si++)
        cout<<*si<<" "<<wordmap[*si]<<endl;
	return 0;
}

void Show(const string & s)
{
	cout<<s<<" ";
}

string & ToLower(string & s)
{
    transform(s.begin(),s.end(),s.begin(),toLower);
	return s;
}

char toLower(char ch){return tolower(ch);}
