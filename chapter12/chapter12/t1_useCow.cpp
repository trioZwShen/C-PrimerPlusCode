//
//  t1_useCow.cpp
//  chapter12
//
//  Created by SZW on 2018/2/5.
//  Copyright © 2018年 SZW. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "t1_Cow.hpp"


int main()
{
    using namespace std;
    Cow a;                      //构造函数1
    Cow b("SZW","Code",55.0);   //构造函数2
    Cow c=b;                    //构造函数3
    Cow d;                      //构造函数1
    d=b;                        //重载赋值运算符
    a.ShowCow();
    b.ShowCow();
    c.ShowCow();
    d.ShowCow();
    return 0;    
}
