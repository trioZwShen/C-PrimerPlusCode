#include<iostream>
#include"stacktp.hpp"
using namespace std;
template<template<class T> class Thing> /*将模板类Thing做为参数的模板*/
class Crab
{
private:
    Thing<int> s1;
    Thing<double> s2;
public:
    Crab(){}
    /*假设Thing模板中有push,pop方法*/
    bool push(int a,double x){return s1.push(a) && s2.push(x);}
    bool pop(int &a,double &x){return s1.pop(a) && s2.pop(x);}
};

int main()
{
    Crab<Stack> nebula; //一个以Stack为参数的模板类Crab,Stack必须匹配template<class T> class Stack
    int ni;
    double nb;
    cout<<"Enter int double pairs, such as 4 3.5 (0 0 to end):\n";
    while(cin>>ni>>nb && ni>0 && nb>0)
    {
        if(!nebula.push(ni,nb))
            break;
    }
    while(nebula.pop(ni,nb))
        cout<<ni<<", "<<nb<<endl;
    cout<<"Done!\n";
    return 0;
}
