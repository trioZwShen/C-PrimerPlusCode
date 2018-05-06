//
//  usedma.cpp
//  chapter13
//
//  Created by SZW on 2017/8/24.
//  Copyright © 2017年 SZW. All rights reserved.
//
#include<iostream>
#include "dma.hpp"

using namespace std;
int main()
{
    baseDMA shirt("Portabelly",8);
    lacksDMA balloon("red","Blimpo",4);
    hasDMA map("Mercator","Buffao Keys",5);
    cout<<"Displaying baseDMA object:\n";
    cout<<shirt<<endl;
    cout<<"Displaying lacksDMA object:\n";
    cout<<balloon<<endl;
    cout<<"Displaying hasDMA object:\n";
    cout<<map<<endl;
    
    lacksDMA balloon2(balloon);
    cout<<"Result of lacksDMA copy:\n";
    cout<<balloon2<<endl;
    hasDMA map2;
    map2=map;
    cout<<"Result of hasDMA copy:\n";
    cout<<map2<<endl;
    return 0;
}
