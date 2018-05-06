//
//  dma.cpp
//  chapter13
//
//  Created by SZW on 2017/8/24.
//  Copyright © 2017年 SZW. All rights reserved.
//
#include<iostream>
#include "dma.hpp"

//baseDMA
baseDMA::baseDMA(const char * l,int r)
{
    label=new char[std::strlen(l)+1];
    strcpy(label,l);
    rating =r;
}
baseDMA::baseDMA(const baseDMA & rs)
{
    label =new char[strlen(rs.label)+1];
    strcpy(label,rs.label);
    rating=rs.rating;
}
baseDMA::~baseDMA()
{
    delete [] label;
}
baseDMA & baseDMA::operator=(const baseDMA & rs)
{
    if(this == &rs)
        return *this;
    delete [] label;
    label=new char[strlen(rs.label)+1];
    strcpy(label,rs.label);
    rating=rs.rating;
    return *this;
}
std::ostream & operator<<(std::ostream & os,const baseDMA & rs)
{
    os<<"Label: "<<rs.label<<std::endl;
    os<<"Rating: "<<rs.rating<<std::endl;
    return os;
}


//lacksDMA
lacksDMA::lacksDMA(const char * c,const char * l,int r):baseDMA(l,r)
{
    std::strncpy(color,c,39);
    color[39]='\0';
}
lacksDMA::lacksDMA(const char * c,const baseDMA & rs):baseDMA(rs)
{
    std::strncpy(color,c,COL_LEN-1);
    color[COL_LEN-1]='\0';
}
std::ostream & operator<<(std::ostream & os,const lacksDMA & rs)
{
    os<<(const baseDMA &)rs;    //强制转换
    os<<"Color: "<<rs.color<<std::endl;
    return os;
}

//hasDMA
hasDMA::hasDMA(const char * s,const char * l,int r):baseDMA(l,r)
{
    style=new char[strlen(s)+1];
    strcpy(style,s);
}
hasDMA::hasDMA(const char * s,const baseDMA & rs):baseDMA(rs)
{
    style=new char[strlen(s)+1];
    strcpy(style,s);
}
hasDMA::hasDMA(const hasDMA & hs):baseDMA(hs)
{
    style=new char[strlen(hs.style)+1];
    strcpy(style,hs.style);
}
hasDMA::~hasDMA()
{
    delete [] style;
}
hasDMA & hasDMA::operator=(const hasDMA & rs)
{
    if(this == &rs)
        return *this;
    baseDMA::operator=(rs);
    delete [] style;
    style=new char[strlen(rs.style)+1];
    strcpy(style,rs.style);
    return *this;
}
std::ostream & operator<<(std::ostream & os,const hasDMA & rs)
{
    os<<(const baseDMA &)rs;
    os<<"Style: "<<rs.style<<std::endl;
    return os;
}





