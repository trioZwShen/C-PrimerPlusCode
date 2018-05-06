//
//  Wine2.hpp
//  chapter-14
//
//  Created by SZW on 2017/9/25.
//  Copyright © 2017年 SZW. All rights reserved.
//

#ifndef Wine2_hpp
#define Wine2_hpp
#include<iostream>
#include<valarray>
#include <stdio.h>
typedef std::valarray<int> ArrayInt;
template<class T1,class T2>
class Pair
{
private:
    T1 year;
    T2 bottle;
public:
    Pair(const T1 & yr,const T2 & bt ):year(yr),bottle(bt){}
    Pair(){}
    //Pair(int x,int * y,int * b){data1(x);data2(x);data1={y};data2={b};}
    int Sum()const;
    void Set(const T1 & yr,const T2 &bt);
    void Show(int y)const;
    //Pair<T1,T2> & operator=(const Pair<T1,T2> &p);
};
/*方法定义*/
template<class T1,class T2>
void Pair<T1,T2>::Set(const T1 & yr,const T2 &bt)
{
    year=yr;
    bottle=bt;
}
template<class T1,class T2>
int Pair<T1,T2>::Sum()const
{
    return bottle.sum();
}
template<class T1,class T2>
void Pair<T1,T2>::Show(int y)const
{
    for(int i=0;i<y;i++)
        std::cout<<year[i]<<" : "<<bottle[i]<<std::endl;
}



typedef Pair<ArrayInt,ArrayInt>PairArray;

class Wine:private PairArray,private std::string
{
private:
    int yrs;
public:
    Wine(){}
    Wine(const char * l,int y,const int yr[],const int bot[]);
    Wine(const char * l,int y);
    void GetBottles();
    std::string & Label();
    void Show()const;
    int sum()const;
};


#endif
