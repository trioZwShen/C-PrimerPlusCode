#include<iostream>
#include<vector>
#include<random>
#include<algorithm>
using namespace std;

typedef vector<int> vecint;
vecint LoTTo(int all_number,int sub_number);

int main()
{
	vecint x;
	x=LoTTo(51,6);
	for(int i=0;i<6;i++)
		cout<<x[i]<<" ";
	cout<<endl;


	return 0;
}

vecint LoTTo(int all_number,int sub_number)
{
	vecint group;
	for (int i=0;i<all_number;i++)
		group.push_back(i+1);
	vecint sub_group;
	for(int i=0;i<sub_number;i++)
	{
		random_shuffle(group.begin(),group.end());
		sub_group.push_back(group[i]);
	}
	return sub_group;
}
