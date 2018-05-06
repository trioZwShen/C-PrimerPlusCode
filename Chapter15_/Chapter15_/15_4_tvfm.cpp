//
//  15_4_tvfm.cpp
//  Chapter15_
//
//  Created by SZW on 2018/3/7.
//  Copyright © 2018年 SZW. All rights reserved.
//
#include <iostream>
#include "15_4_tvfm.hpp"

bool Tv::volup()
{
    if(volume<MaxVal)
    {
        volume++;
        return true;
    }
    else
        return false;
}
bool Tv::voldown()
{
    if(volume>MinVal)
    {
        --volume;
        return true;
    }
    else
        return false;
}

void Tv::chanup()
{
    if(channel<maxchannel)
        channel++;
    else
        channel=1;
}
void Tv::chandown()
{
    if(channel>1)
        channel--;
    else
        channel=maxchannel;
}

void Tv::settings()const
{
    using std::cout;
    using std::endl;
    cout<<"Tv is "<<(state ==Off? "Off":"On")<<endl;
    if(state==On)
    {
        cout<<"Volume setting = "<<volume<<endl;
        cout<<"Channel setting = "<<channel<<endl;
        cout<<"Mode = "<<(mode==Antenna?"antenna":"cable")<<endl;
        cout<<"Input = "<<(input == TV?"TV":"DVD")<<endl;
    }
}
