//
//  dma.cpp
//  chapter13
//
//  Created by SZW on 2017/8/24.
//  Copyright © 2017年 SZW. All rights reserved.
//
#include<iostream>
#include "dma_2.hpp"

//abcDMA
void abcDMA::View()const
{
    std::cout<<"Rating: "<<rating<<std::endl;
    std::cout<<"Temp: "<<temp<<std::endl;
}
abcDMA & abcDMA::operator=(const abcDMA & st)
{
    if(this==&st)
        return *this;
    delete [] temp;
    temp=new char[strlen(st.temp)+1];
    strcpy(temp,st.temp);
    rating =st.rating;
    return *this;
}


//baseDMA
baseDMA::baseDMA(const char * l,int r,const char * s):abcDMA(r,s)
{
    label=new char[std::strlen(l)+1];
    strcpy(label,l);
}
baseDMA::baseDMA(const baseDMA & rs):abcDMA(rs)
{
    label =new char[strlen(rs.label)+1];
    strcpy(label,rs.label);
}
baseDMA::~baseDMA()
{
    delete [] label;
}
baseDMA & baseDMA::operator=(const baseDMA & rs)
{
    this->setRating(rs);
    if(this == &rs)
        return *this;
    delete [] label;
    label=new char[strlen(rs.label)+1];
    strcpy(label,rs.label);
    return *this;
}

void baseDMA::View()const
{
    abcDMA::View();
}
std::ostream & operator<<(std::ostream & os,const baseDMA & rs)
{
    os<<"Label: "<<rs.label<<std::endl;
    rs.View();
    return os;
}
