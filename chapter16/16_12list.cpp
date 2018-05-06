#include<iostream>
#include<list>
#include<iterator>
#include<algorithm>


void output(int n){std::cout<<n<<" ";}

int main()
{
	using namespace std;
	list<int> one(5,2);
	int stuff[5]={1,2,4,8,6};
	list<int> two;
	two.insert(two.begin(),stuff,stuff+5);
	int more[6]={6,4,2,4,6,5};
	list<int> three(two);
	three.insert(three.end(),more,more+6);

	cout<<"list one: ";
	for_each(one.begin(),one.end(),output);
	cout<<endl<<"List two: ";
	for_each(two.begin(),two.end(),output);
	cout<<endl<<"List three: ";
	for_each(three.begin(),three.end(),output);
	cout<<endl;

	three.remove(2);
	cout<<"List three minus 2: ";
	for_each(three.begin(),three.end(),output);cout<<endl;
	
	three.splice(three.begin(),one);
	cout<<"List three after splice: ";
	for_each(three.begin(),three.end(),output);cout<<endl;
	cout<<"And list one: ";
	for_each(one.begin(),one.end(),output);cout<<endl;

	three.unique();
	cout<<"List three after unique: ";
	for_each(three.begin(),three.end(),output);cout<<endl;

	three.sort();
	cout<<"List three after sort: ";
	for_each(three.begin(),three.end(),output);cout<<endl;

	three.unique();
	cout<<"List three after sort & unique: ";
	for_each(three.begin(),three.end(),output);cout<<endl;

	two.sort();
	three.merge(two);
	cout<<"List three after merge with two: ";
	for_each(three.begin(),three.end(),output);cout<<endl;
	return 0;
}