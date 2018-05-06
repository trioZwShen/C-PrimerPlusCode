#include<iostream>
#include<iterator>
#include<set>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	const int N=6;
	string s1[N]={"buffoon","thinkers","for","heavy","can","for"};
	string s2[N]={"metal","any","food","elegant","deliver","for"};

	set<string>A(s1,s1+N);	//用s1来初始化A
	set<string>B(s2,s2+N);	//用s2来初始化B

	ostream_iterator<string,char>out(cout," ");	//定义输出流迭代器
	cout<<"A: ";copy(A.begin(),A.end(),out);cout<<endl;	//输出A
	cout<<"B: ";copy(B.begin(),B.end(),out);cout<<endl;	//输出B

	//set_union()函数,输出
	cout<<"A B 并集: ";
	set_union(A.begin(),A.end(),B.begin(),B.end(),out);
	cout<<endl;

	//set_intersection()函数,输出
	cout<<"A B 交集: ";
	set_intersection(A.begin(),A.end(),B.begin(),B.end(),out);
	cout<<endl;

	//set_difference()函数,输出
	cout<<"A-B : ";
	set_difference(A.begin(),A.end(),B.begin(),B.end(),out);
	cout<<endl;

	//利用set_union(),插入到C
	set<string>C;
	set_union(A.begin(),A.end(),B.begin(),B.end(),insert_iterator<set<string>>(C,C.begin()));
	cout<<"C: ";copy(C.begin(),C.end(),out);cout<<endl;	//输出C

	//insert()方法
	string s3("grungy");
	C.insert(s3);
	cout<<endl<<"CCCC: ";
	copy(C.begin(),C.end(),out);cout<<endl;	//输出C

	//lower_bound()与upper_bound()
	cout<<"Showing a range: ";
	copy(C.lower_bound("ghost"),C.upper_bound("spook"),out);cout<<endl;


	return 0;
}