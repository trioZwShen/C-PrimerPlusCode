#include<iostream>
#include<string>
#include<cstdlib>
#include"14_t5emp.h"
const int MAX=10;
using namespace std;
int main()
{
    
    abstr_emp * pc[MAX];
    char ch;
    int i=0;
    cout<<"Enter the class: ";
    
    while(cin.get(ch).get() && ch!='q')
    {
        switch (ch)
        {
            case 'e':   {pc[i] =new employee;pc[i]->SetAll();}
                break;
            case 'm':   {pc[i] =new manager;pc[i]->SetAll();}
                break;
            case 'f':   {pc[i] =new fink;pc[i]->SetAll();}
                break;
            case 'h':   {pc[i] =new highfink;pc[i]->SetAll();}
                break;
            default:
                continue;
        }
        i++;
        cout<<"\nEnter the next class: ";
    }
    
    /*
     cout<<"\n输出: "<<endl;
    for (int t=0;t<i;t++)
    {
        cout<<t+1<<endl;
        pc[t]->ShowAll();
        cout<<endl;
    }
    */
    
    //写入文件
    
    ofstream fout;
    fout.open("//Users//chinshii//Documents//Cpp//chapter17//szw.txt");
    if(fout.is_open())
        cout<<"OPEN\n";
    for (int t=0;t<i;t++)
    {
        cout<<t+1<<endl;
        pc[t]->WriteAll(fout);
    }
    fout.close();
    
    //从文件读取
    abstr_emp * pout[MAX];
    ifstream fin;
    fin.open("//Users//chinshii//Documents//Cpp//chapter17//szw.txt");
    if(!fin.is_open())
    {
        cout<<"WRONG!";
        exit(0);
    }
    char fc;
    for(int t=0;t<i;t++)
    {
        fin.get(fc).get();
        switch (fc) {
            case 'e':{  pout[t]=new employee;pout[t]->GetAll(fin); }
                break;
            case 'm':{  pout[t]=new manager;pout[t]->GetAll(fin); }
                break;
            case 'f':{  pout[t]=new fink;pout[t]->GetAll(fin); }
                break;
            case 'h':{  pout[t]=new highfink;pout[t]->GetAll(fin); }
                break;
            default:
                break;
        }
    }
    cout<<"\n输出: "<<endl;
    for (int t=0;t<i;t++)
    {
        cout<<t+1<<endl;
        pout[t]->ShowAll();
        cout<<endl;
    }
    
    return 0;
}
