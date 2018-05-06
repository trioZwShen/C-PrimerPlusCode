//
//  useemp.cpp
//  chapter-14
//
//  Created by SZW on 2017/9/26.
//  Copyright © 2017年 SZW. All rights reserved.
//
#include<iostream>
#include<string>
#include <stdio.h>
#include"emp.hpp"

int main()
{
    using namespace std;
    employee em("Trip","Harris","Thumper");
    cout<<endl<<em<<endl;
    em.ShowAll();
    manager ma("Amorphia","Spindragon","Nuancer",5);
    cout<<endl<<ma<<endl;
    ma.ShowAll();
    
    fink fi("Matt","Oggs","Oiler","Juno Barr");
    cout<<endl<<fi<<endl;
    fi.ShowAll();
    highfink hf(ma,"Curly Kew");
    cout<<endl<<hf<<endl;
    hf.ShowAll();
    cout<<"\nPress a key for next phase:\n";
    cin.get();
    highfink hf2;
    hf2.SetAll();
    
    cout<<"\nUsing an abstr_emp * pointer:\n";
    abstr_emp * tri[4]={&em,&fi,&hf,&hf2};
    for(int i=0;i<4;i++)
    {
        cout<<"***********************************\n";
        tri[i]->ShowAll();
    }
    
    return 0;
}
