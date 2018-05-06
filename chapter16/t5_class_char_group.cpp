#include<iostream>
#include<algorithm>
#include<set>
#include<iterator>
#include<string>

using namespace std;
const int NUM=10;
template<class T>
int reduce(T ar [],int n);//排序,删除重复值,返回长度
template<class T>
void Show(const T & l){cout<<l<<" ";}
int main()
{	
	cout<<"Enter your group (length=10): ";
	string temp;
	string arr[NUM];
	int i=0;
	while(cin>>temp && i<10)
		{arr[i++]=temp;cout<<"The next: ";}

	
	//初始数组
	cout<<"Oringinal array: ";
	//for_each(arr,arr+NUM,Show);cout<<endl;
	for(int i=0;i<NUM;i++)
		cout<<arr[i]<<" ";

	//处理
	int len=reduce(arr,NUM);
	cout<<"\nThe length of processed array is "<<len<<endl;
	
	//处理后的数组
	cout<<"Processed array: ";
	//for_each(arr,arr+len,Show);cout<<endl;
	for(int i=0;i<len;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	return 0;
}
template<class T>
int reduce(T ar [],int n)
{
	set<T> temp;
	copy(ar,ar+n,insert_iterator<set<T>>(temp,temp.begin()));
	copy(temp.begin(),temp.end(),ar);
	return temp.size();
}