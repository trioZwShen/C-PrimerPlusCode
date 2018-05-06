//
//  12_10_queue.cpp
//  chapter12
//
//  Created by SZW on 2018/2/4.
//  Copyright © 2018年 SZW. All rights reserved.
//
#include <cstdlib>
#include <iostream>
#include "12_10_queue.hpp"


/*---------------------------Customer类方法定义---------------------------*/
//设置_arrive
void Customer::set(long arrive)
{
    _arrive=arrive;
    _processTime=std::rand()%3+1;
}

/*----------------------------Queue类方法定义-----------------------------*/

//构造函数
Queue::Queue(int qs):_qsize(qs)
{
    _rear=_head=nullptr;
    _len=0;
}
//析构函数,将剩余的结点全部销毁
Queue::~Queue()
{
    Node * p=_head;
    while(_head)
    {
        p=p->_next;
        delete _head;
        _head=p;
        --_len;
    }
}
//判断是否为空
bool Queue::isempty()const
{
    return _len==0;
}
//判断是否为满
bool Queue::isfull()const
{
    return _len==_qsize;
}
//返回队列长度
int Queue::queuecount()const
{
    return _len;
}
//入队
bool Queue::enqueue(const Item & item)
{
    if(isfull()){
        std::cout<<"FULL!\n";
        return false;
    }
    Node * temp=new Node;       //创建一个新结点
    temp->_item=item;           //初始化位item
    temp->_next=nullptr;        //将新结点的next指向空
    
    if(_head==nullptr)          //表示原队列为空
        _head=temp;             //队头指向新结点
    else
        _rear->_next=temp;      //旧的队尾next指向新结点,将队列与新结点连接
    _rear=temp;                 //队尾更新
    ++_len;
    return true;
}
//出队
bool Queue::dequeue(Item & item)
{
    if(isempty()){
        std::cout<<"EMPTY!\n";
        return false;
    }
    item=_head->_item;           //队头结点存入item
    Node * temp=_head;
    _head=_head->_next;          //队列不只有一个结点,将队头后移
    delete temp;                 //删除队头
    --_len;
    if(_len==1)                  //如果队列只有一个结点
        _head=_rear=nullptr;
    return true;
}
