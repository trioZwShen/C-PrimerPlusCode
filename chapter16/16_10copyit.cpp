#include<iterator>
#include<iostream>
#include<vector>
int main()
{
	using namespace std;

	int casts[10]={6,7,2,9,4,11,8,7,10,5};
	vector<int> dice(10);
	copy(casts,casts+10,dice.begin());
	cout<<"Let the dice be cast!\n";
	ostream_iterator<int,char>out_iter(cout," ");	//定义一个输出流迭代器
	copy(dice.begin(),dice.end(),out_iter);
	cout<<endl;

	cout<<"Implicit use of reverse iterator.\n";
	copy(dice.rbegin(),dice.rend(),out_iter);
	cout<<endl;
	cout<<"Explicit ues of reverse iterator.\n";
	vector<int>::reverse_iterator pp;
	for (pp=dice.rbegin();pp!=dice.rend();pp++)
		cout<<*pp<<' ';
	cout<<endl;
	return 0;
}