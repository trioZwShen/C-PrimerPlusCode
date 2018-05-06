//
//  t7_usecomplex.cpp
//  chapter11
//
//  Created by SZW on 2018/1/29.
//  Copyright © 2018年 SZW. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "t7_complex.hpp"

int main()
{
    using namespace std;
    Complex a(3.0,4.0);
    Complex c;
    cout<<"Enter a complex (q to quit):";
    while(cin>>c)
    {
        cout<<"c is "<<c<<"\n";
        cout<<"complex conjugate is "<<~c<<"\n";
        cout<<"a is "<<a<<"\n";
        cout<<"a + c is "<< a + c <<"\n";
        cout<<"a - c is "<< a - c <<"\n";
        cout<<"a * 2 is "<< a * 2 <<"\n";
        cout<<"3 * a is "<< 3 * a <<"\n";
        cout<<"Enter a complex (q to quit):";
    }
    cout<<"Done\n";
    return 0;
}
