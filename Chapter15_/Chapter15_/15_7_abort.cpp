//
//  15_7_abort.cpp
//  Chapter15_
//
//  Created by SZW on 2018/3/8.
//  Copyright © 2018年 SZW. All rights reserved.
//

#include <iostream>
#include <cstdlib>

double hmean(double a, double b);

int main(){
    using namespace std;
    double x,y,z;
    cout<<"Enter two numbers: ";
    while(cin>>x>>y){
        z=hmean(x,y);
        cout<<"Harmonic mean of "<<x<<" and "<<y
            <<" is "<<z<<endl;
        cout<<"Enter next set of numbers <q to quit>: ";
    }
    cout<<"Bye!\n";
    return 0;
}

double hmean(double a, double b){
    if(a==-b){
        std::cout<<"Untenable agruments to hmean()\n";
        std::abort();
    }
    return 2.0*a*b/(a+b);
}
