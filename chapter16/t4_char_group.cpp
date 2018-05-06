#include<iostream>
#include<algorithm>
#include<set>
#include<iterator>

using namespace std;
const int NUM=10;
int reduce(long ar [],int n);//排序,删除重复值,返回长度
void Show(long l){cout<<l<<" ";}
int main()
{	
	cout<<"Enter your group (length=10): ";
	long temp;
	long arr[NUM];
	int i=0;
	while(cin>>temp && i<10)
		arr[i++]=temp;

	//初始数组
	cout<<"Oringinal array: ";
	for_each(arr,arr+NUM,Show);cout<<endl;

	//处理
	int len=reduce(arr,NUM);
	cout<<"The length of processed array is "<<len<<endl;
	//处理后的数组
	cout<<"Processed array: ";
	for_each(arr,arr+len,Show);cout<<endl;

	return 0;
}

int reduce(long ar [],int n)
{
	set<long> temp;
	copy(ar,ar+n,insert_iterator<set<long>>(temp,temp.begin()));
	copy(temp.begin(),temp.end(),ar);
	return temp.size();
}