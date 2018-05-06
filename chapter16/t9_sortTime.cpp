#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include<iterator>
#include<ctime>

const int NUM=10000;

int main()
{
	using namespace std;

	//a
	vector<int> vi0(NUM);
	for (int i=0;i<NUM;i++)
		vi0[i]=rand()%100;

	//b
	vector<int> vi=vi0;
	list<int> li(NUM);
	copy(vi0.begin(),vi0.end(),li.begin());
	//c
	//vector's sort
	clock_t strat=clock();
	sort(vi.begin(),vi.end());
	clock_t end=clock();
	cout<<"vector's time: "<<(double)(end-strat)<<endl;
	//list's sort
	strat=clock();
	li.sort();
	end=clock();
	cout<<"list's time: "<<(double)(end-strat)<<endl;
	//利用vector排序
	copy(vi0.begin(),vi0.end(),li.begin());
	strat=clock();
	copy(li.begin(),li.end(),vi.begin());	//先复制到list中
	sort(vi.begin(),vi.end());
	end=clock();
	cout<<"list's vector time: "<<(double)(end-strat)<<endl;
	return 0;
}