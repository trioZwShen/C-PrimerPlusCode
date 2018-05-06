#include<iostream>
#include"9_11_namesp.h"
void other(void);
void another(void);

int main()
{
	using namespace std;
	using debts::Debt;
	using debts::ShowDebt;

	Debt golf={{"s","zw"},12.0};
	ShowDebt(golf);
	other();
	another();
	return 0;
}

void other(void)
{
	using std::cout;
	using std::endl;
	using namespace debts;
	Person dog{"DDD","GGG"};
	ShowPerson(dog);
	cout<<endl;
	Debt zippy[3];
	int i;
	for(i=0;i<3;i++)
		GetDebt(zippy[i]);

	for(i=0;i<3;i++)
		ShowDebt(zippy[i]);

	cout<<"THE SUM: "<<sumDebt(zippy,3)<<endl;
}
void another(void)
{
	using pers::Person;
	Person collector={"MIlo","ahsjf"};
	pers::ShowPerson(collector);
	std::cout<<std::endl;
}