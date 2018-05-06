//
//  List.cpp
//  Chapter10
//
//  Created by SZW on 2018/1/24.
//  Copyright © 2018年 SZW. All rights reserved.
//
#include<iostream>
#include "List.hpp"

//创建空列表的构造函数
List::List(int len,ElemType data)
{
    for(int i=0;i<len;i++)
        _data[i]=data;
    _len=len;
}
//添加数据项
void List::Push(ElemType data)
{
    if(_len >= MAX)
        std::cout<<"满\n";
    else
        _data[_len++]=data;
}
//判断是否为空
bool List::empty()const
{
    return _len==0;
}
//判断是否为满
bool List::full()const
{
    return _len==MAX;
}
//对数据项进行某种操作,输入参数为函数指针
void List::someOperator(void (*p)(ElemType))
{
    for(int i=0;i<_len;++i)
        (*p)(_data[i]);
}
