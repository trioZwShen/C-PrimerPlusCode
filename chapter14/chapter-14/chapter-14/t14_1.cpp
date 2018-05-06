//
//  t14_1.cpp
//  chapter-14
//
//  Created by SZW on 2017/9/25.
//  Copyright © 2017年 SZW. All rights reserved.
//

#include <stdio.h>
#include<iostream>
#include"Wine2.hpp"

using namespace std;
int main()
{
    cout<<"Enter the name: ";
    char lab[50];
    cin.getline(lab,50);
    cout<<"Enter the number: ";
    int yrs;
    cin>>yrs;
    
    Wine holding(lab,yrs);
    holding.GetBottles();
    holding.Show();
    
    const int YRS=3;
    int y[YRS]={1993,1995,1998};
    int b[YRS]={48,60,72};
    Wine more("Gushing",YRS,y,b);
    more.Show();
    
    cout<<"Total "<<more.Label()<<": "<<more.sum()<<endl;
    
    
    return 0;
}
