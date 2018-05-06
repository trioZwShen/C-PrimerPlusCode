#include<iostream>
#include"9_11_namesp.h"
namespace pers
{
	using std::cout;
	using std::cin;
	void GetPerson(Person & p)
	{
		cout<<"Please enter your first name: ";
		std::getline(cin,p.fname);
		cout<<"Please enter your last name: ";
		std::getline(cin,p.lname);

	}
	void ShowPerson(const Person & p)
	{
		cout<<p.fname<<" "<<p.lname;
	}
}

namespace debts
{
	using std::cout;
	using std::cin;
	void GetDebt(Debt & d)
	{
		GetPerson(d.name);
		cout<<"输入: ";
		(cin>>d.amount).get();
	}
	void ShowDebt(const Debt & d)
	{
		ShowPerson(d.name);
		cout<<" "<<d.amount<<std::endl;
	}
	double sumDebt(const Debt arr[],int n)
	{
		double temp=0;
		for (int i=0;i<n;i++)
			temp+=arr[i].amount;
		return temp;
	}
}
