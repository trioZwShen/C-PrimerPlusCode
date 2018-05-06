//
//  useclassic.cpp
//  chapter13
//
//  Created by SZW on 2017/8/29.
//  Copyright © 2017年 SZW. All rights reserved.
//
#include<iostream>
#include <stdio.h>
#include"classic_1.hpp"
using namespace std;
void Bravo(const Cd & disk);
int main()
{
    Cd c1("Beatles","Capitol",14,35.5);
    Classic c2=Classic("Alfred Brendel","Philips",2,57.17,"Piano Sonata in B flat, Fantasia in C");
    Cd * pcd=&c1;
    cout<<"Using object directly:\n";
    c1.Report();
    c2.Report();
    
    cout<<"\nUsing object directly:\n";
    pcd->Report();
    pcd=&c2;
    pcd->Report();
    
    cout<<"\nCalling a function with a Cd reference argument:\n";
    Bravo(c1);
    Bravo(c2);
    
    cout<<"\nTesting assignment: \n";
    Classic copy;
    copy=c2;
    copy.Report();
    return 0;
}
void Bravo(const Cd & disk)
{
    disk.Report();
}
