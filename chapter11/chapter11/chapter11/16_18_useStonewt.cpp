//
//  16_18_useStonewt.cpp
//  chapter11
//
//  Created by SZW on 2018/1/28.
//  Copyright © 2018年 SZW. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "11_16_stonewt.hpp"

void display(const Stonewt & st, int n);

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;
    Stonewt incognito = 275;    //int转换为double, 再转换为Stonewt
    Stonewt wolfe(285.7);       //double转换为Stonewt
    Stonewt taft(21,8);         //构造函数
    
    cout<<"The celebrity weighed  ";
    incognito.show_lbs();
    cout<<"The detective weighted ";
    wolfe.show_lbs();
    cout<<"The President weighed ";
    taft.show_stn();
    incognito=276.8;            //double转换为Stonewt
    taft=325;                   //int转换为double, 再转换为Stonewt
    cout<<"After dinner, the celebrity weighted ";
    incognito.show_lbs();
    cout<<"After dinner, the President weighted ";
    taft.show_lbs();
    display(taft,2);
    cout<<"The wrestler weighed even more.\n";
    display(422,2);
    cout<<"No stone left unearned\n";
    return 0;
}

void display(const Stonewt & st, int n)
{
    for(int i=0;i<n;i++)
    {
        std::cout<<"Wow! ";
        st.show_stn();
    }
}
