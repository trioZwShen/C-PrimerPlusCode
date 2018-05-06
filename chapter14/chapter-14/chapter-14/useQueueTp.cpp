//
//  QueueTp.cpp
//  chapter-14
//
//  Created by SZW on 2017/9/26.
//  Copyright © 2017年 SZW. All rights reserved.
//
#include<iostream>
#include "QueueTp.hpp"
#include"Workermi.hpp"
using namespace std;

const int SIZE=5;
int main()
{
    using std::cout;
    using std::cin;
    using std::endl;
    using std::strchr;
    
    Worker * lolas[SIZE];
    //cout<<"test"<<endl;
    QueueTp<Worker *>lll;
    
    
    int ct;
    for(ct=0;ct<SIZE;ct++)
    {
        char choice;
        cout<<"Enter the employee category:\n"
        <<"w: waiter s: singer  "
        <<"t: singing waiter q: quit\n";
        cin>>choice;
        while(strchr("wstq",choice)==NULL)
        {
            cout<<"Please enter a w,s,t,or q: ";
            cin>>choice;
        }
        if(choice=='q')
            break;
        switch (choice) {
            case 'w':
                lolas[ct]=new Waiter;
                break;
            case 's':
                lolas[ct]=new Singer;
                break;
            case 't':
                lolas[ct]=new SingingWaiter;
                break;
            default:
                break;
        }
        cin.get();
        lolas[ct]->Set();
        lll.EnQueue(lolas[ct]);
    }
    cout<<"\n**********************\nHere is your staff:\n";
    int i;
    Worker *xxx;
    for(i=0;i<ct;i++)
    {
        cout<<endl;
        cout<<lll.DeQueue(xxx);
        xxx->Show();
    }
    for(i=0;i<ct;i++)
        delete lolas[i];
    cout<<"Bye\n";
    return 0;
}
