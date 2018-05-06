#include<iostream>
void divide(char arr[],int x1,int x2,int level);
int main()
{
	using namespace std;
	char arr[9];
	for(int i=0;i<9;i++)
	{
		arr[i]=' ';
	}
	arr[0]='|';
	arr[8]='|';
	int level=1;
	while(level<=3)
	{
		divide(arr,0,8,level++);
		for(int i=0;i<9;i++)
		{
			cout<<arr[i];
			arr[i]=' ';
		}
		arr[0]='|';
		arr[8]='|';
		cout<<endl;
	}
}

void divide(char arr[],int x1,int x2,int level)
{
	if(level>0)
	{
		int mid=(x1+x2)/2;
		arr[mid]='|';
		divide(arr,x1,mid,level-1);
		divide(arr,mid,x2,level-1);
	}
}