//
//  12_6_sayings.cpp
//  chapter12
//
//  Created by SZW on 2018/1/31.
//  Copyright © 2018年 SZW. All rights reserved.
//
#include <iostream>
#include <cstring>
#include "t2_string2.hpp"

int main()
{
    using namespace std;
    String s1(" and I am a C++ student.");  //构造函数
    String s2="Please enter your name: ";   //构造函数
    String s3;                              //构造函数
    cout<<s2;                               //重载<<
    cin>>s3;                                //重载>>
    s2="My name is "+s3;                    //友元重载+
    cout<<s2<<".\n";                        //重载<<
    s2=s2+s1;                               //成员重载+
    s2.Stringup();                          //转换大写
    cout<<"The string\n"<<s2<<"\ncontains "<<s2.Count('A')  //计数
        <<" 'A' characters in it.\n";
    s1="red";                               //重载=
    String rgb[3]={String(s1),String("green"),String("blue")};
    cout<<"Enter the name of a primary color for mixing light: ";
    String ans;
    bool success = false;
    while(cin>>ans)
    {
        ans.Stringlow();
        for(int i=0;i<3;++i)
        {
            if(ans==rgb[i]){
                cout<<"That's right!\n";
                success=true;
                break;
            }
        }
        if(success)
            break;
        else
            cout<<"Try again!\n";
    }
    cout<<"Bye\n";
    return 0;
}
