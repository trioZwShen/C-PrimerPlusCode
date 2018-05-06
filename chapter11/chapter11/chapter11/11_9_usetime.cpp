//
//  11_9_usetime.cpp
//  chapter11
//
//  Created by SZW on 2018/1/24.
//  Copyright © 2018年 SZW. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "11_7_mytime.hpp"
int main()
{
    using namespace std;
    Time weeding(4,35);
    Time waxing(2,47);
    Time total;
    Time diff;
    Time adjusted;
    
    weeding.Show();
    waxing.Show();
    total=weeding+waxing;
    total.Show();
    
    diff=weeding-waxing;
    diff.Show();
    
    adjusted=total*1.5;
    adjusted.Show();
    
    return 0;
}
