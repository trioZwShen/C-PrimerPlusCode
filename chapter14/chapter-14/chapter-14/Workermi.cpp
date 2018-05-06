//
//  Workermi.cpp
//  chapter-14
//
//  Created by SZW on 2017/9/20.
//  Copyright © 2017年 SZW. All rights reserved.
//
#include<iostream>
#include "Workermi.hpp"

using std::cout;
using std::endl;
using std::cin;

/*Worker methods*/
Worker::~Worker()
{}

void Worker::Data()const
{
    cout<<"Name: "<<fullname<<endl;
    cout<<"Employee ID: "<<id<<endl;
}
void Worker::Get()
{
    cout<<"Enter worker's name:";
    getline(cin,fullname);
    cout<<"Enter worker's ID:";
    cin>>id;
    while(cin.get()!='\n')
        continue;
}
void Worker::Set()
{
    Get();
    cout<<endl;
}
void Worker::Show()const
{
    Data();
}


/*Waiter methods*/
void Waiter::Data()const
{
    cout<<"Panache rating: "<<panache<<endl;
}
void Waiter::Get()
{
    cout<<"Enter waiter's panache rating:";
    cin>>panache;
    while(cin.get()!='\n')
        continue;
}
void Waiter::Set()
{
    Worker::Get();
    Get();
    cout<<endl;
}
void Waiter::Show()const
{
    cout<<"Category:Waiter\n";
    Worker::Data();
    Data();
    
}


/*Singer methods*/
char * Singer::pv[]={"other","alto","contralto","soprano","bass","baritone","tenor"};
void Singer::Data()const
{
    cout<<"Vocal range: "<<pv[voice]<<endl;
}
void Singer::Get()
{
    cout<<"Enter number for singer's vocal range:\n";
    int i;
    for(i=0;i<Vtypes;i++)
    {
        cout<<i<<": "<<pv[i]<<" ";
        if(i%4==3)
            cout<<endl;
    }
    if(i%4!=0)
        cout<<endl;
    while(cin>>voice && (voice <0||voice>=Vtypes))
        cout<<"Please enter a value>=0 and < "<<Vtypes<<endl;
    while(cin.get()!='\n')
        continue;
}
void Singer::Set()
{
    Worker::Get();
    Get();
    cout<<endl;
}

void Singer::Show()const
{
    cout<<"Category:singer\n";
    Worker::Data();
    Data();
}

/*MI派生类的方法*/
void SingingWaiter::Data()const
{
    Singer::Data();
    Waiter::Data();
}
void SingingWaiter::Get()
{
    Singer::Get();
    Waiter::Get();
}
void SingingWaiter::Set()
{
    cout<<"SET SingingWaiter\n";
    Worker::Get();
    Get();
    cout<<endl;
}
void SingingWaiter::Show()const
{
    cout<<"Category: singing waiter\n";
    Worker::Data();
    Data();
}
