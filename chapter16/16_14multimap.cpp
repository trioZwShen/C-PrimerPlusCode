#include<iostream>
#include<map>
#include<string>
#include<algorithm>
#include<iterator>

typedef int KeyType;	//类型别名
typedef std::pair<const KeyType,std::string>Pair;//简化pair
typedef std::multimap<KeyType,std::string>MapCode;//简化multimap

int main()
{
	using namespace std;
	MapCode codes;	//声明一个multimap对象

	codes.insert(Pair(415,"San Francisco"));
	codes.insert(Pair(510,"Oakland"));
	codes.insert(Pair(718,"Brooklyn"));
	codes.insert(Pair(718,"Staten Island"));
	codes.insert(Pair(415,"San Rafael"));
	codes.insert(Pair(510,"Berkeley"));

	//count()成员函数
	cout<<"Number of cites with area with 415: "
		<<codes.count(415)<<endl;
	cout<<"Number of cites with area with 510: "
		<<codes.count(510)<<endl;
	cout<<"Number of cites with area with 718: "
		<<codes.count(718)<<endl;
	
	//lower_bound(),upper_bound()函数
	//ostream_iterator<string,char>out(cout," ");
	//copy(codes.lower_bound(500),codes.upper_bound(400),out);

	//输出,不能同上
	cout<<"Area cide  City\n";
	MapCode::iterator it;
	for(it=codes.lower_bound(500);it!=codes.upper_bound(700);it++)
		cout<<"   "<<(*it).first<<"     "<<(*it).second<<endl;

	//equal_range()成员函数
	pair<MapCode::iterator,MapCode::iterator>range=codes.equal_range(718);
	cout<<"The Number is 718's City: \n";
	for(it=range.first;it!=range.second;it++)
		cout<<"   "<<(*it).first<<"     "<<(*it).second<<endl;

	//使用自动类型判断
	auto rrrange=codes.equal_range(415);
	cout<<"The Number is 415's City: \n";
	for(it=rrrange.first;it!=rrrange.second;it++)
		cout<<"   "<<(*it).first<<"     "<<(*it).second<<endl;

	return 0;
}