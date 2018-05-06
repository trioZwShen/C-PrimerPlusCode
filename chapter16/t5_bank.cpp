//未做完

#include<iostream>
#include<cstdlib>
#include<ctime>
#include<queue>

const int MIN_PER_HR = 60;
bool newcustomer(double x);

int main()
{
	using namespace std;
	srand(time(0));	//初始化时间
	cout<<"Case Study: Bank of Heather Automatic Teller\n";
	cout<<"Enter maximum size of queue: ";
	int qs;
	cin>>qs;

	queue<int> line(qs);	//初始化line

	cout<<"Enter the number of simulation hours: ";
	int hours;
	cin>>hours;

	long cyclelimit = MIN_PER_HR *hours;

	cout<<"Enter the average number of customers per hour: ";
	double perhour;
	cin>>perhour;

	double min_per_cust=MIN_PER_HR;



}