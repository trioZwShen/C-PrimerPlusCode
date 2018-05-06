#include<iostream>
#include<valarray>
#include<cstdlib>

const int SIZE=12;
typedef std::valarray<int> vint;
void show(const vint & v,int cols);

int main()
{
	using namespace std;

	vint valint(SIZE);

	int i;
	for(i=0;i<SIZE;i++)
		valint[i]=rand()%100;
	ostream_iterator<int,char>out_iter(cout," ");
	copy(begin(valint),end(valint),out_iter);cout<<endl;

	cout<<"Original array:\n";			//输出
	show(valint,3);

	cout<<"Second column:\n";
	vint vcol(valint[slice(1,4,3)]);	//获取第二列
	show(vcol,1);

	cout<<"Second row:\n";
	vint vcow(valint[slice(3,3,1)]);	//获取第二行
	show(vcow,3);

	valint[slice(2,4,3)]=10;
	cout<<"Set last column to 10:\n";	//修改后输出
	show(valint,3);

	cout<<"Set first column to sum of next two:\n";
	valint[slice(0,4,3)]=vint(valint[slice(1,4,3)])+vint(valint[slice(2,4,3)]);
	show(valint,3);	
	return 0;
}

void show(const vint & v,int cols)	//cols列数
{
	using std::cout;
	using std::endl;
	int lim=v.size();
	for (int i=0;i<lim;i++)
	{
		cout.width(3);
		cout<<v[i];
		if(i%cols==cols-1)
			cout<<endl;
		else
			cout<<" ";
	}
	if(lim % cols !=0)
		cout<<endl;
}