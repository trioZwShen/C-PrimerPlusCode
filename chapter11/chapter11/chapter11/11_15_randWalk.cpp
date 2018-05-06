//
//  11_15_randWalk.cpp
//  chapter11
//
//  Created by SZW on 2018/1/25.
//  Copyright © 2018年 SZW. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "11_14_vector.hpp"

int main()
{
    using namespace std;
    using VECTOR::Vector;
    srand(time(0));
   
    double direction;
    Vector step;
    Vector result(0.0,0.0);
    unsigned long steps=0;
    double target;
    double dstep;
    cout<<"输入目标距离: ";
    while(cin>>target)
    {
        cout<<"输入步长: ";
        if(!(cin>>dstep))
            break;
        while(result.magval()<target)
        {
            direction=rand()%360;
            step.reset(dstep,direction,Vector::POL);
            result=result+step;
            steps++;
        }
        cout<<"After: "<<steps<<" steps, the subject has the following location:\n";
        cout<<result<<endl;
        result.polar_mode();
        cout<<" or\n"<<result<<endl;
        cout<<"平均走的距离: "<<result.magval()/steps<<endl;
        steps=0;
        result.reset(0.0,0.0);
        cout<<"q to quit: ";
    }
    cout<<"BYE\n";
    cin.clear();
    while(cin.get()!='\n')
        continue;
    return 0;
}
