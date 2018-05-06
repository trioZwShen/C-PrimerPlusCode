#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include<cctype>
#include<vector>
#include<fstream>
using std::string;
const int NUM=26;

const string list[NUM]={"apiary","beetle","cereal","danger","ensign",
"florid","garage","health","insult","jackal",
"keeper","loaner","manage","nonce","onset","plaid","quilt","remote","stolid",
"train","useful","valid","whence","xenon","yearn","zippy"};


int main()
{
	using namespace std;
	//使用文件输入
	ifstream infile;
	infile.open("//Users//chinshii//Documents//Cpp//chapter16//wordlist.txt");
	if(!infile.is_open())         //如果成功打开会返回true
	{
		cout<<"Worng!\n";
		return 0;
	}
	vector<string> wordlist;
	string temp;
	while(infile>>temp)
		{
			wordlist.push_back(temp);
			cout<<temp<<" ";
		}
	cout<<endl<<wordlist.size()<<endl;
	srand(time(0));
	char play;
	cout<<"Will you play a word game? <y/n>";
	cin>>play;
	play=tolower(play);
	while(play=='y')
	{
		string target = wordlist[rand() % wordlist.size()];	//随机选取string
		int length=target.length();
		string attempt(length,'-');	//初始化尝试string
		string badchars;
		int guesses=6;
		cout<<"Guess my secret word. It has "<<length
			<<" letters, and you guess\n"
			<<"one letter at a time. You get "<<guesses
			<<" wrong guesses.\n";
		cout<<"Your word: "<<attempt<<endl;
		while(guesses>0 && attempt!=target)
		{
			char letter;
			cout<<"Guess a letter: ";
			cin>>letter;
			if(badchars.find(letter)!=string::npos || attempt.find(letter)!=string::npos)
			{
				cout<<"Your already guessed that. Try again.\n";
				continue;
			}
			int loc=target.find(letter);
			if (loc==string::npos)
			{
				cout<<"Oh BAD GUESS!\n";
				--guesses;
				badchars+=letter;
			}
			else
			{
				cout<<"GOOD GUESS!\n";
				attempt[loc]=letter;
				loc=target.find(letter,loc+1);	//查找是否存在下一个letter
				while(loc!=string::npos)
				{
					attempt[loc]=letter;
					loc=target.find(letter,loc+1);
				}
			}
			cout<<"Your word: "<<attempt<<endl;
			if(attempt!=target)
			{
				if(badchars.length()>0)
					cout<<"Bad choices: "<<badchars<<endl;
				cout<<guesses<<" bad guesses left\n\n";
			}
		}
		if(guesses>0)
			cout<<"That's right!\n";
		else
			cout<<"Sorry, the word is "<<target<<".\n";
		cout<<"Will you play another? <y/n>";
		cin>>play;
		play=tolower(play);
	}
	cout<<"Bye!\n";
	return 0;
}