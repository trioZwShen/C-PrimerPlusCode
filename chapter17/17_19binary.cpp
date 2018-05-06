#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstdlib>

inline void eatline(){while (std::cin.get()!='\n')continue;}
struct planet
{
	char name[20];
	double population;
	double g;
};
const char * file ="planets.dat";
int main()
{
	using namespace std;
	planet pl;
	cout<<fixed<<right;

	ifstream fin;
	fin.open(file,ios_base::in|ios_base::binary);
	if(fin.is_open())
	{
		cout<<"Here are the current contents of the "
			<<file<<" file:\n";
		while(fin.read((char *)&pl, sizeof pl))
		{
			cout<<setw(20)<<pl.name<<": "<<setprecision(0)<<setw(12)	
				<<pl.population<<setprecision(2)<<setw(6)<<pl.g<<endl;
		}
		fin.close();
	}

	ofstream fout(file,ios_base::out | ios_base::app | ios_base::binary);
	if(!fout.is_open())
	{
		cerr<<"WWWW"<<endl;
		exit(0);
	}

	cout<<"ENTER name";
	cin.get(pl.name,20);
	while(pl.name[0]!='\0')
	{
		eatline();
		cout<<"ENter population: ";
		cin>>pl.population;
		cout<<"Enter akjflam: ";
		cin>>pl.g;
		eatline();
		fout.write((char *)&pl,sizeof pl);
		cout<<"hahahahha";
		cin.get(pl.name,20);
	}
	fout.close();
	cout<<"DDDDDD\n";
	return 0;
}