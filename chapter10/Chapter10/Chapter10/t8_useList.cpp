//
//  t8_useList.cpp
//  Chapter10
//
//  Created by SZW on 2018/1/24.
//  Copyright © 2018年 SZW. All rights reserved.
//

#include <stdio.h>
#include<iostream>
#include "List.hpp"
inline void visited(ElemType x){std::cout<<x<<" ";}

int main()
{
    using namespace std;
    List a;
    List b(10);
    List c(5,5);
    a.someOperator(visited);cout<<endl;
    b.someOperator(visited);cout<<endl;
    c.someOperator(visited);cout<<endl;
    cout<<a.empty()<<endl;
    a.Push(12);
    cout<<b.full()<<endl;
    cout<<c.empty()<<endl;
    a.someOperator(visited);cout<<endl;
    b.someOperator(visited);cout<<endl;
    c.someOperator(visited);cout<<endl;
    return 0;
}
