#include<iostream>
#include<string>
#include<algorithm>

int main()
{
	using namespace std;
	string letters;
	cout<<"Enter the letter grouping (quit to quit): ";
	while(cin>>letters && letters !="quit")
	{
		cout<<"Permutations of "<<letters<<endl;
		sort(letters.begin(),letters.end());
		cout<<"Sorted of "<<letters<<endl;
		int i=1;
		while(next_permutation(letters.begin(),letters.end()))
		{
			cout<<"# "<<i++<<" "<<letters<<endl;
		}
		cout<<"Again cin :";
	}
	return 0;
}