//
//  12_10_queue.hpp
//  chapter12
//
//  Created by SZW on 2018/2/4.
//  Copyright © 2018年 SZW. All rights reserved.
//

#ifndef _2_10_queue_hpp
#define _2_10_queue_hpp
#include <iostream>
#include <stdio.h>

/*顾客类*/
class Customer
{
private:
    long _arrive;    //到达时间
    int _processTime;//处理时间
public:
    Customer():_arrive(0),_processTime(0){}     //使用成员初始化列表的构造函数
    void set(long arrive);                      //设置_arrive
    long when()const{return _arrive;}           //返回_arrive
    int ptime()const{return _processTime;}      //返回_processTime
};

typedef Customer Item;  //类型别名

/*队列类*/
class Queue
{
private:
    struct Node { Item _item ;struct Node * _next; };   //类内嵌套结构
    enum {Q_size=10};   //枚举类型定义
//----------------------------------------------------------------------//
    Node * _rear;        //尾结点
    Node * _head;        //头结点
    int _len;            //队列长度
    const int _qsize;    //队列最大长度
//----------------------------------------------------------------------//
    //通过伪私有方法回避构造深度复制的复制构造函数以及重载赋值运算符
    Queue(const Queue & q):_qsize(0){}
    Queue & operator=(const Queue & q){return *this;}
public:
    Queue(int qs=Q_size);               //构造函数
    ~Queue();                           //析构函数
    bool isempty()const;                //判断是否为空
    bool isfull()const;                 //判断是否为满
    int queuecount()const;              //返回队列长度
    bool enqueue(const Item & item);    //入队
    bool dequeue(Item & item);          //出队
};
#endif /* _2_10_queue_hpp */
