//
//  Port.cpp
//  chapter13
//
//  Created by SZW on 2017/9/3.
//  Copyright © 2017年 SZW. All rights reserved.
//

#include "Port.hpp"
//Port method define
using namespace std;
Port::Port(const char * br,const char * st,int b)
{
    brand=new char[strlen(br)+1];
    strcpy(brand,br);
    strcpy(style,st);
    bottles=b;
}
Port::Port(const Port & p)
{
    brand=new char[strlen(p.brand)+1];
    strcpy(brand,p.brand);
    strcpy(style,p.style);
    bottles=p.bottles;
}
Port & Port::operator=(const Port &p)
{
    if(this==&p)
        return *this;
    delete [] brand;
    brand=new char[strlen(p.brand)+1];
    strcpy(brand,p.brand);
    strcpy(style,p.style);
    bottles=p.bottles;
    return *this;
}
Port & Port::operator+=(int b)
{
    bottles+=b;
    return *this;
}
Port & Port::operator-=(int b)
{
    bottles-=b;
    return *this;
}
void Port::Show()const
{
    cout<<"Brand: "<<brand<<endl;
    cout<<"Kind: "<<style<<endl;
    cout<<"Bottles: "<<bottles<<endl;
    
}
ostream & operator<<(ostream & os,const Port & p)
{
    os<<p.brand<<", "<<p.style<<", "<<p.bottles;
    return os;
}

//VintagePort method define
VintagePort::VintagePort()
{
    nickame=new char[5];
    strcpy(nickame, "None");
    year=0;
}
VintagePort::VintagePort(const char *br,const char *st,int b,const char *nn,int y):Port(br,st,b)
{
    nickame=new char[strlen(nn)+1];
    strcpy(nickame, nn);
    year=y;
}
VintagePort::VintagePort(const VintagePort &vp):Port(vp)
{
    nickame=new char[strlen(vp.nickame)+1];
    strcpy(nickame, vp.nickame);
    year=vp.year;
}VintagePort & VintagePort::operator=(const VintagePort &vp)
{
    if(this==&vp)
        return *this;
    Port::operator=(vp);
    delete [] nickame;
    nickame =new char[strlen(vp.nickame)+1];
    strcpy(nickame,vp.nickame);
    year=vp.year;
    return *this;
}
void VintagePort::Show() const
{
    Port::Show();
    cout<<"Nickname: "<<nickame<<endl;
    cout<<"Year: "<<year<<endl;
}
std::ostream & operator<<(std::ostream & os, const VintagePort & vp)
{
    os<<Port(vp)<<", ";
    os<<vp.nickame<<", "<<vp.year;
    return os;
}
