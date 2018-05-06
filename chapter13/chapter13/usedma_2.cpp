//
//  usedma.cpp
//  chapter13
//
//  Created by SZW on 2017/8/24.
//  Copyright © 2017年 SZW. All rights reserved.
//
#include<iostream>
#include "dma_2.hpp"

using namespace std;
int main()
{
    baseDMA s1("Portabelly",8,"szw");
    baseDMA s2;
    baseDMA s3=s1;
    s2=s1;
    cout<<"Displaying baseDMA object:\n";
    cout<<s1<<endl;
    cout<<s2<<endl<<s3<<endl;
    return 0;
}
