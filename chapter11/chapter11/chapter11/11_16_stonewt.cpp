//
//  11_16_stonewt.cpp
//  chapter11
//
//  Created by SZW on 2018/1/28.
//  Copyright © 2018年 SZW. All rights reserved.
//

#include <iostream>
#include "11_16_stonewt.hpp"

Stonewt::Stonewt(double lbs)
{
    _stone=int(lbs) / Lbs_per_stn;
    _pds_left=int(lbs) % Lbs_per_stn + lbs - int(lbs);
    _pounds=lbs;
}
Stonewt::Stonewt(int stn, double lbs)
{
    _stone=stn;
    _pds_left=lbs;
    _pounds=stn*Lbs_per_stn+lbs;
}
Stonewt::Stonewt()
{
    _stone=0;
    _pds_left=0.0;
    _pounds=0.0;
}
Stonewt::~Stonewt()
{
}
void Stonewt::show_lbs() const
{
    std::cout<<_stone<<" stone, "<<_pds_left<<" pounds\n";
}
void Stonewt::show_stn() const
{
    std::cout<<_pounds<<" pounds\n";
}
