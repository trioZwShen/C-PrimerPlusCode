//
//  usePort.cpp
//  chapter13
//
//  Created by SZW on 2017/9/3.
//  Copyright © 2017年 SZW. All rights reserved.
//

#include <stdio.h>
#include<iostream>
#include"Port.hpp"

int main()
{
    using namespace std;
    Port p1,p2("Szw","Cool",1993);
    VintagePort vp1,vp2("CY","Cute",1994,"Red Bean",11);
    cout<<"P1\n";
    p1.Show();
    cout<<"P2\n";
    p2.Show();
    cout<<"VP1\n";
    vp1.Show();
    cout<<"VP2\n";
    vp2.Show();
    vp1+=1;
    vp2-=10;
    cout<<vp1<<vp2<<endl;
    return 0;
}
