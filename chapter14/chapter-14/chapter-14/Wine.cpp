//
//  Wine.cpp
//  chapter-14
//
//  Created by SZW on 2017/9/25.
//  Copyright © 2017年 SZW. All rights reserved.
//

#include "Wine.hpp"

Wine::Wine(const char * l,int y,const int yr[],const int bot[]):data(ArrayInt(yr,y), ArrayInt(bot,y))
{
    fullname=l;
    yrs=y;
}
Wine::Wine(const char * l,int y)
{
    fullname=l;
    yrs=y;
}
void Wine::GetBottles()
{
    ArrayInt years(yrs);
    ArrayInt bottles(yrs);
    for(int i=0;i<yrs;i++)
    {
        std::cout<<"Enter the years: ";
        std::cin>>years[i];
        std::cout<<"Enter the bottle number: ";
        std::cin>>bottles[i];
    }
    while(std::cin.get()!='\n')
        continue;
    data.Set(years,bottles);
}
std::string & Wine::Label()
{
    return fullname;
}
void Wine::Show()const
{
    std::cout<<"Wine: "<<fullname<<std::endl;
    std::cout<<"Year and Number: \n";
    data.Show(yrs);
}
int Wine::sum()const
{
    return data.Sum();
}
