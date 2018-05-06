//
//  12_6_sayings.cpp
//  chapter12
//
//  Created by SZW on 2018/1/31.
//  Copyright © 2018年 SZW. All rights reserved.
//
#include <iostream>
#include <cstring>
#include "12_4_string1.hpp"

const int ArSize=10;
const int MaxLen=81;
int main()
{
    using std::cout;
    using std::cin;
    using std::endl;
    String name;
    cout<<"名字?\n";
    cin>>name;
    cout<<name<<", 请输入最多"<<ArSize<<"个字符串(空行结束):\n";
    String sayings[ArSize];
    char temp[MaxLen];
    int i;
    for(i=0;i<ArSize;++i)
    {
        cout<<i+1<<": ";
        cin.get(temp,MaxLen);
        while(cin && cin.get()!='\n')
            continue;
        if(!cin || temp[0]=='\0')
            break;
        else
            sayings[i]=temp;
    }
    int total=i;
    if(total>0)
    {
        cout<<"全部字符串:\n";
        for(i=0;i<total;++i)
            cout<<sayings[i][0]<<": "<<sayings[i]<<endl;
        int shortest=0;
        int first=0;
        for(i=0;i<total;++i)
        {
            if(sayings[i].length()<sayings[shortest].length())
                shortest=i;
            if(sayings[i]<sayings[first])
                first=i;
        }
        cout<<"最短字符串: "<<sayings[shortest]<<endl;
        cout<<"首字符串: "<<sayings[first]<<endl;
        cout<<"共用字符串: "<<String::HowMany()<<endl;
    }
    else
        cout<<"No input! Bye.\n";
    return 0;
}
