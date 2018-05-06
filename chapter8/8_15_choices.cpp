#include<iostream>

template<class T>	//模板1
T lesser(T a, T b)
{
	return a;
}

int lesser(int a, int b)	//函数2
{
	return b;
}

int main()
{
	using namespace std;
	//cout<<lesser(1.1,2.2)<<endl;
	//cout<<lesser(1,2)<<endl;
	//cout<<lesser(1.0,2.0)<<endl;
	cout<<lesser(1.1,2)<<endl;		//会选用函数2,因为模板1要求T的类型相同
	cout<<lesser<int>(1,2)<<endl;	//通过显示实例化强制调用模板1
}