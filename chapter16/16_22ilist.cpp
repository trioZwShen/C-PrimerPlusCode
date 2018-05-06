#include<iostream>
#include<initializer_list>

double sum(std::initializer_list<double> i1);
double average(const std::initializer_list<double> & ri1);

int main()
{
	using std::cout;
	cout<<"List 1: sum = "<<sum({2,3,4})<<"\t\taverage: "<<average({2,3,4})<<std::endl;
	std::initializer_list<double>d1={1.1,2.2,3.3,4.4,5.5};
	cout<<"List 2: sum = "<<sum(d1)<<"\taverage: "<<average(d1)<<"\n";
	d1={16.0,25.0,36.0,49.0,64.0};
	cout<<"List 3: sum = "<<sum(d1)<<"\taverage: "<<average(d1)<<std::endl;
	return 0;
}

double sum(std::initializer_list<double> i1)
{
	double total=0;
	for(auto i=i1.begin();i!=i1.end();i++)
		total+=*i;
	return total;
}
double average(const std::initializer_list<double> & ri1)
{
	double total=0;
	if(ri1.size()>0)
	{
		for(auto i=ri1.begin();i!=ri1.end();i++)
			total+=*i;
		total/=ri1.size();
	}
	return total;
}