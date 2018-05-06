//
//  11_16_stonewt.hpp
//  chapter11
//
//  Created by SZW on 2018/1/28.
//  Copyright © 2018年 SZW. All rights reserved.
//

#ifndef _1_16_stonewt_hpp
#define _1_16_stonewt_hpp

#include <stdio.h>

class Stonewt
{
private:
    enum{Lbs_per_stn=14};
    int _stone;
    double _pds_left;
    double _pounds;
public:
    Stonewt(double lbs);    //类型转换构造函数
    Stonewt(int stn, double lbs);
    Stonewt();
    ~Stonewt();
    void show_lbs()const;
    void show_stn()const;
    
};
#endif /* _1_16_stonewt_hpp */
