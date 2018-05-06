#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<algorithm>
#include<iterator>

inline void Showstr(const std::string & s){std::cout<<s<<std::endl;}
void GetStr(std::istream & is, std::vector<std::string> & v);
class Store
{
private:
    std::ofstream ofs;
public:
    Store(const char *addr){ofs.open(addr,
    	std::ios_base::out|std::ios_base::binary);}
    void operator()(const std::string & s)
    {
    	int len=s.length();
    	ofs.write((char *)&len,sizeof(std::size_t));//写入长度
    	ofs.write((char *)s.data(),len);	
    	//data()成员函数,类似于c_str(), 但是结尾不加'\0'
    }
};

int main()
{
	using namespace std;
	vector<string>vostr;
	string temp;

	//获取string
	cout<<"Enter string (empty line to quit):\n";
	while(getline(cin,temp) && temp[0]!='\0')
	{
		vostr.push_back(temp);
	}
	cout<<"Here is your input.\n";
	for_each(vostr.begin(),vostr.end(),Showstr);
	cout<<endl;

	//保存到文件中,保存成二进制文本
	//ofstream fout;
    string addr="//Users//chinshii//Documents//Cpp//chapter17//t7.txt";
    for_each(vostr.begin(),vostr.end(),Store(addr.c_str()));
    //fout.close();

    //从文件中读取,读取二进制文本
    vector<string> vistr;
    ifstream fin(addr.c_str(),
    	ios_base::in|ios_base::binary);
    if(!fin.is_open())
    {
    	cerr<<"Worng!"<<endl;
    	exit(0);
    }
    GetStr(fin,vistr);
    cout<<"\n\nNow\n";
    for_each(vistr.begin(),vistr.end(),Showstr);
    //cout<<"asfjdhas "<<vistr[1]<<endl;
	return 0;
}

void GetStr(std::istream & is, std::vector<std::string> & v)
{
	
	char ch;
	int len;
	while(is.read((char *)&len,sizeof(size_t)))
	{
		std::string temp;
		//std::cout<<"len:"<<len<<std::endl;
		for(int i=0;i<len;i++)
		{
			is.read((char *)&ch,1);
			temp.push_back(ch);
		}			
		temp.push_back('\0');
		std::cout<<temp<<std::endl;
		v.push_back(temp);
	}
}
