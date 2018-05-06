#include<iostream>
#include<cstdlib>
char * left(const char * str, int len);
unsigned long left(unsigned long number, int len);

int main()
{
	using namespace std;
	char *trip="Hawaii!!";
	unsigned long n=12345678999;
	int i;
	char * temp;
	for(i=1;i<12;i++)
	{
		cout<<left(n,i)<<endl;
		temp=left(trip,i);
		cout<<temp<<endl;
		delete [] temp;
	}
	return 0;
}

char * left(const char * str, int len)
{
	if(len<0)
		len=0;
	int i=0;
	while(i<len && str[i]!='\0')
		i++;
	char * temp=new char[i+1];
	int j;
	for(j=0;j<i;j++)
		temp[j]=str[j];
	temp[j]='\0';
	return temp;
}

unsigned long left(unsigned long number, int len)
{
	if(len==0 || number==0)
		return 0;
	int digits=1;
	unsigned long temp=number;
	while(temp/=10)
		digits++;
	if(len<digits)
	{
		for(int i=0;i<(digits-len);i++)
			number/=10;
		return number;
	}
	else
		return number;
}