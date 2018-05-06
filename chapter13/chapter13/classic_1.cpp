//
//  classic.cpp
//  chapter13
//
//  Created by SZW on 2017/8/29.
//  Copyright © 2017年 SZW. All rights reserved.
//
#include<iostream>
#include<cstring>
#include "classic_1.hpp"
using std::endl;
using std::cout;
//Cd
Cd::Cd(char * s1,char * s2,int n,double x)
{
    performers=new char[std::strlen(s1)+1];
    label=new char[std::strlen(s2)+1];
    std::strcpy(performers,s1);
    std::strcpy(label,s2);
    selections=n;
    playtime=x;
}
Cd::Cd()
{
    performers=new char[std::strlen("None")+1];
    label=new char[std::strlen("None")+1];
    std::strcpy(performers,"None");
    std::strcpy(label,"None");
    selections=0;
    playtime=0;
}
Cd::Cd(const Cd & st)
{
    performers=new char[std::strlen(st.performers)+1];
    label=new char[std::strlen(st.label)+1];
    std::strcpy(performers,st.performers);
    std::strcpy(label,st.label);
    selections=st.selections;
    playtime=st.playtime;
}
Cd::~Cd()
{}
void Cd::Report() const
{
    cout<<"#";
    cout<<performers<<" : "<<label<<" : "<<selections<<" : "<<playtime<<endl;
}

const Cd & Cd::operator=(const Cd & st)
{
    if(this==&st)
        return *this;
    delete [] performers;
    delete [] label;
    performers=new char[std::strlen(st.performers)+1];
    label=new char[std::strlen(st.label)+1];
    std::strcpy(performers,st.performers);
    std::strcpy(label,st.label);
    selections=st.selections;
    playtime=st.playtime;
    return *this;
}

//Classic
Classic::Classic(char * s1,char * s2,int n,double x,char * s3):Cd(s1,s2,n,x)
{
    import_work=new char[std::strlen(s3)+1];
    std::strcpy(import_work, s3);
}

Classic::Classic():Cd()
{
    import_work=new char[std::strlen("None")+1];
    std::strcpy(import_work, "None");
}

Classic::Classic(const Cd & st,char * s3):Cd(st)
{
    import_work=new char[std::strlen(s3)+1];
    std::strcpy(import_work, s3);
}
Classic::Classic(const Classic & stt):Cd(stt)
{
    import_work=new char[std::strlen(stt.import_work)+1];
    std::strcpy(import_work,stt.import_work);
}

void Classic::Report() const
{
    
    Cd::Report();
    cout<<" : "<<import_work<<endl;
}

const Classic & Classic::operator=(const Classic & stt)
{
    if(this==&stt)
        return *this;
    Cd::operator=(stt);
    delete [] import_work;
    import_work=new char[std::strlen(stt.import_work)+1];
    std::strcpy(import_work,stt.import_work);
    return *this;
}
