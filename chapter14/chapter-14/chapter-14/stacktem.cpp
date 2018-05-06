//
//  stacktem.cpp
//  chapter-14
//
//  Created by SZW on 2017/9/22.
//  Copyright © 2017年 SZW. All rights reserved.
//

#include <stdio.h>
#include<iostream>
#include<string>
#include<cctype>
#include"stacktp.hpp"

int main()
{
    using namespace std;
    Stack<string>st;
    char ch;
    string po;
    cout<<"Please enter A to add a purchase order,\n"
    <<"P to process a PO,or Q to quit.\n";
    while(cin>>ch && toupper(ch)!='Q')
    {
        while(cin.get()!='\n')
            continue;
        if(!isalpha(ch))
        {
            cout<<'\a';
            continue;
        }
        switch(ch)
        {
                case 'A':
                case 'a':
                cout<<"Enter a PO number to add: ";
                cin>>po;
                if(st.isfull())
                    cout<<"stack already full\n";
                else
                    st.push(po);
                break;
                case 'p':
                case 'P':
                if(st.isempty())
                    cout<<"stack lareadly empty\n";
                else
                {
                    st.pop(po);
                    cout<<"PO #"<<po<<" popped\n";
                    break;
                }
        }
        cout<<"Please enter A to add a purchase order,\n"
        <<"P to process a PO,or Qto quit.\n";
    }
    cout<<"BYE!";
    return 0;
    
}
