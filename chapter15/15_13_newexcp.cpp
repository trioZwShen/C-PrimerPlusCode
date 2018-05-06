#include<iostream>
#include<new>
#include<cstdlib>
using namespace std;

struct Big
{
	double stuff[2000];
};

int main()
{
	Big * pb;
	try
	{
		cout<<"Trying to get a big block of memory:\n";
		pb = new Big[100000000000];
		cout<<"Got past the new request:\n";
	}
	catch(bad_alloc & ba)
	{
		cout<<"Caught the exception!\n";
		cout<<ba.what()<<endl;
		return 0;
	}
	cout<<"Memory successfully allocated\n";
	pb[0].stuff[0]=4;
	cout<<pb[0].stuff[0]<<endl;
	delete [] pb;
	return 0;
}