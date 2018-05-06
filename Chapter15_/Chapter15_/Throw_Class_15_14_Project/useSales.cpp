#include <iostream>
#include <string>
#include "sales.hpp"

int main(){
	using namespace std;
	double vals1[12]={
		1220, 1100, 1122, 2212, 1232, 2334, 
		2884, 2393, 3302, 2922, 300, 3544
	};

	double vals2[12]={
		12,11, 22, 21, 32, 34, 28, 29, 33, 29,  32, 35
	};
	Sales sales1(2011,vals1, 12);
	LabeledSales sales2("Blogstar", 2012, vals2, 12);

	cout<<"First try block:\n";
	try{
		int i;
		cout<<"Year= "<<sales1.Year()<<endl;
		for(i=0;i<12;++i){
			cout<<sales1[i]<<" ";
			if(i%6==5)
				cout<<endl;
		}
		cout<<"+++++++++++++++++++++++++\n";
		cout<<"Year = "<<sales2.Year()<<endl;
		cout<<"Label = "<<sales2.Label()<<endl;
		for(i=0;i<=12;++i){
			cout<<sales2[i]<<" ";
			if(i%6==5)
				cout<<endl;
		}
	}
	catch(LabeledSales::nbad_index & nbd){
		cout<<nbd.what();
		cout<<"Company: "<<nbd.label_val()<<endl;
		cout<<"bad index"<<nbd.bi_val()<<endl;
	}
	catch(Sales::bad_index & bd){
		cout<<bd.what();
		cout<<"bad index"<<bd.bi_val()<<endl;
		cout<<"\nNext try bloc:\n";
	}
	try{
			sales2[2]=37.5;
			sales1[20]=23345;
			cout<<"End of try block 2.\n";
		}
		catch(LabeledSales::nbad_index & nbd){
			cout<<nbd.what();
			cout<<"Company: "<<nbd.label_val()<<endl;
			cout<<"bad index"<<nbd.bi_val()<<endl;
		}
		catch(Sales::bad_index & bd){
			cout<<bd.what();
			cout<<"bad index"<<bd.bi_val()<<endl;
		}
	cout<<"Done\n";
	return 0;
}
