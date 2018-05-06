//
//  classic.cpp
//  chapter13
//
//  Created by SZW on 2017/8/29.
//  Copyright © 2017年 SZW. All rights reserved.
//
#include<iostream>
#include<cstring>
#include "classic.hpp"
using std::endl;
using std::cout;
//Cd
Cd::Cd(char * s1,char * s2,int n,double x)
{
    std::strcpy(performers,s1);
    std::strcpy(label,s2);
    selections=n;
    playtime=x;
}
Cd::Cd()
{
    std::strcpy(performers,"None");
    std::strcpy(label,"None");
    selections=0;
    playtime=0;
}
Cd::~Cd()
{}
void Cd::Report() const
{
    cout<<"#";
    cout<<performers<<" : "<<label<<" : "<<selections<<" : "<<playtime<<endl;
}

//Classic
Classic::Classic(char * s1,char * s2,int n,double x,char * s3):Cd(s1,s2,n,x)
{
    std::strcpy(import_work, s3);
}
Classic::Classic():Cd()
{
    std::strcpy(import_work, "None");
}
Classic::Classic(const Cd & st,char * s3):Cd(st)
{
    std::strcpy(import_work, "None");
}
void Classic::Report() const
{
    
    Cd::Report();
    cout<<" : "<<import_work<<endl;
}
