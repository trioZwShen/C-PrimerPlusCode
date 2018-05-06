//
//  15_9_throw.cpp
//  Chapter15_
//
//  Created by SZW on 2018/3/8.
//  Copyright © 2018年 SZW. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <cmath>

/*定义异常类*/
class bad_hmean{ //hmean的异常类
private:
    double _a;
    double _b;
public:
    bad_hmean(int a, int b):_a(a),_b(b){}
    ~bad_hmean(){}
    void wrong()const{std::cout<<std::endl<<_a<<" and "<<_b<<" hmean() is Wrong!\n";}
};
class bad_gmean{ //gmean的异常类
private:
    double _a;
    double _b;
public:
    bad_gmean(int a, int b):_a(a),_b(b){}
    ~bad_gmean(){}
    void wrong()const{std::cout<<std::endl<<_a<<" and "<<_b<<" gmean() is Wrong!\n";}
};

double hmean(double a, double b);
double gmean(double a, double b);


int main(){
    using namespace std;
    double x,y;
    cout<<"Enter two numbers: ";
    while(cin>>x>>y){
        try{
            cout<<"hmean = "<<hmean(x, y)<<endl;
            cout<<"gmean = "<<gmean(x, y)<<endl;
        }
        catch(const bad_hmean & h){     //hmean的异常处理
            h.wrong();
            cout<<"Try again: ";
            continue;
        }
        catch(const bad_gmean & g){     //gmean的异常处理
            g.wrong();
            cout<<"Try again: ";
            continue;
        }
        
        cout<<"Enter next set of numbers <q to quit>: ";
    }
    cout<<"Bye!\n";
    return 0;
}

//函数定义
double hmean(double a, double b){
    if(a==-b){
        throw bad_hmean(a,b);
    }
    return 2.0*a*b/(a+b);
}
double gmean(double a, double b){
    if(a<0||b<0)
        throw bad_gmean(a,b);
    return std::sqrt(a*b);
}
