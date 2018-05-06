//
//  14_23_tmp2rmp.cpp
//  Chapter14_
//
//  Created by SZW on 2018/3/6.
//  Copyright © 2018年 SZW. All rights reserved.
//

#include <stdio.h>
#include <iostream>

/*1 两个模板函数的声明*/
template<typename TFun>void Count();
template<typename TFun>void Report(TFun &);
/*2 模板类的声明*/
template<typename TClass>
class HasFriend{
private:
    TClass item;
    static int ct;
public:
    HasFriend(const TClass & tc): item(tc){ct++;}   //2.1 构造函数
    ~HasFriend(){ct--;}                             //2.2 析构函数
    /*该模板类的约束模板友元声明*/
    friend void Count<TClass>();                                    //2.3 模板类的约束模板友元
    friend void Report<HasFriend<TClass>>(HasFriend<TClass> &);    //2.4 模板类的约束模板友元
};

/*3 静态成员初始化*/
template<typename TClass>
int HasFriend<TClass>::ct=0;

/*4 模板定义*/
template<typename TFun>
void Count(){
    std::cout<<"template size: "<<sizeof(HasFriend<TFun>)<<std::endl;
    std::cout<<"template counts: "<<HasFriend<TFun>::ct<<std::endl;
}
template<typename TFun>
void Report(TFun &hf){
    std::cout<<hf.item<<std::endl;
}

/*5 主函数测试*/
int main(){
    using namespace std;
    HasFriend<int> hfi1(10);                //约束模板友元的调用
    HasFriend<int> hfi2(20);                //约束模板友元的调用
    HasFriend<double> hfdb(10.5);           //约束模板友元的调用
    Report(hfi1);
    Report(hfi2);
    Report(hfdb);
    cout<<"counts<int>() output:\n";
    Count<int>();                           //约束模板友元的调用
    cout<<"counts<double>() output:\n";
    Count<double>();                        //约束模板友元的调用
    return 0;
}
