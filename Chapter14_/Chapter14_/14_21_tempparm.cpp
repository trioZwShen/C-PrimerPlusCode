//
//  14_21_tempparm.cpp
//  Chapter14_
//
//  Created by SZW on 2018/3/5.
//  Copyright © 2018年 SZW. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "14_15_stcktp1.hpp"

//声明一个以模板类为参数的模板类
template<template<typename T>class Ting>
class Crab{
private:
    Ting<int> s1;
    Ting<double> s2;
public:
    Crab(){}
    bool Push(int n, double x){return s1.Push(n) && s2.Push(x);}
    bool Pop(){return s1.Pop() && s2.Pop();}
    bool Top(int &n, double &x){return s1.Top(n) && s2.Top(x);}
};

int main(){
    using namespace std;
    int ni;
    double nb;
    Crab<Stack> Temp;
    cout<<"Enter int double pairs: \n";
    while(cin>>ni>>nb){
        if(!Temp.Push(ni, nb))
           break;
    }
    cout<<"OUT:\n";
    while(Temp.Top(ni,nb)){
        Temp.Pop();
        cout<<ni<<" "<<nb<<endl;
    }
    cout<<"Done!\n";
    return 0;
}
