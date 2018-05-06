//
//  14_6_useStudenti.cpp
//  Chapter14_
//
//  Created by SZW on 2018/3/3.
//  Copyright © 2018年 SZW. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "14_4_studenti.hpp"
using std::cout;
using std::cin;
using std::endl;

void set(Student & sa,int n);
const int pupils=3;
const int quizzes=5;

int main()
{
    Student ada[pupils]={Student(quizzes),Student(quizzes),Student(quizzes)};
    int i;
    for(i=0;i<pupils;++i)
    {
        set(ada[i],quizzes);
    }
    cout<<"\nStudent List:\n";
    for(i=0;i<pupils;++i)
    {
        cout<<ada[i].Name()<<endl;
    }
    cout<<"\nResults:";
    for(i=0;i<pupils;++i)
    {
        cout<<endl<<ada[i];
        cout<<"average: "<<ada[i].Average()<<endl;
    }
    cout<<"Done!\n";
    return 0;
}
void set(Student & sa,int n)
{
    cout<<"Please enter the student's name: ";
    getline(cin,sa);
    cout<<"Please enter "<<n<<" scores:\n";
    for(int i=0;i<n;i++)
        cin>>sa[i];
    while(cin.get()!='\n')
        continue;
}
