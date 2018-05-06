//
//  List.hpp
//  Chapter10
//
//  Created by SZW on 2018/1/24.
//  Copyright © 2018年 SZW. All rights reserved.
//

#ifndef List_hpp
#define List_hpp
#define MAX 10
#include <stdio.h>
typedef int ElemType;
class List
{
private:
    ElemType _data[MAX];
    int _len;
public:
    //创建空列表的构造函数
    List(int len=0,ElemType data=0);
    //虚析构函数
    virtual ~List(){};
    //添加数据项
    void Push(ElemType data);
    //判断是否为空
    bool empty()const;
    //判断是否为满
    bool full()const;
    //对数据项进行某种操作,输入参数为函数指针
    void someOperator(void (*p)(ElemType));
};

#endif /* List_hpp */
