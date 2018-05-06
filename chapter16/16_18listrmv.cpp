#include<iostream>
#include<algorithm>
#include<list>

void Show(int);
const int LIM=10;

int main()
{
	using namespace std;
	list<int>la={4,5,4,2,2,3,4,8,1,4};
	list<int>lb={4,5,4,2,2,3,4,8,1,4};

	cout<<"Original list contents:\n";
	cout<<"la: ";for_each(la.begin(),la.end(),Show);cout<<endl;
	cout<<"lb: ";for_each(lb.begin(),lb.end(),Show);cout<<endl;

	la.remove(4);
	cout<<"After la.remove(4): \n";
	cout<<"la: ";for_each(la.begin(),la.end(),Show);cout<<endl;
	cout<<"lb: ";for_each(lb.begin(),lb.end(),Show);cout<<endl;

	list<int>::iterator it;
	it=remove(lb.begin(), lb.end(),4);
	cout<<"After remove():\n";
	cout<<"la: ";for_each(la.begin(),la.end(),Show);cout<<endl;
	cout<<"lb: ";for_each(lb.begin(),lb.end(),Show);cout<<endl;

	lb.erase(it,lb.end());
	cout<<"After erase():\n";
	cout<<"la: ";for_each(la.begin(),la.end(),Show);cout<<endl;
	cout<<"lb: ";for_each(lb.begin(),lb.end(),Show);cout<<endl;

}
void Show(int x)
{
	std::cout<<x<<" ";
}