//
//  Workertest.cpp
//  chapter-14
//
//  Created by SZW on 2017/9/20.
//  Copyright © 2017年 SZW. All rights reserved.
//

#include <stdio.h>
#include<iostream>
#include"Worker0.hpp"

const int LIM=4;
int main()
{
    Waiter bob("Bob Apple",314L,5);
    Singer bev("Beverly Hills",522L,3);
    Waiter w_temp;
    Singer S_temp;
    Worker * pw[LIM]={&bob,&bev,&w_temp,&S_temp};
    int i;
    for(i=2;i<LIM;i++)
        pw[i]->Set();
    for(i=0;i<LIM;i++)
    {
        pw[i]->Show();
        std::cout<<std::endl;
    }
    return 0;
}
