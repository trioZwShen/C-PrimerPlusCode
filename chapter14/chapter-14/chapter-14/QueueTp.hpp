//构造一个链队列

#ifndef QueueTp_hpp
#define QueueTp_hpp
#include<iostream>
#include <stdio.h>
template<class Type>    //结点结构
struct QNode
{
    Type data;
    QNode * next;
};

template<class Type>
class QueueTp
{
private:
    QNode<Type> *head,*rear;
    int itemNumber;
public:
    QueueTp();  //初始化空队列
    //QueueTp(int num); //初始化结点数为num的队列.
    bool isempty()const {return itemNumber==0;}
    bool EnQueue(const Type & temp);    //将temp入队尾
    bool DeQueue(Type & temp);  //将队头数据出至temp
    int Len()const{return itemNumber;}
   
};
template<class Type>
QueueTp<Type>::QueueTp()
{
    itemNumber=0;
    head=nullptr;
    rear=nullptr;
}
template<class Type>
bool QueueTp<Type>::EnQueue(const Type &temp)
{
    QNode<Type> * x=new QNode<Type>;
    
    x->data=temp;
    x->next=nullptr;
    if(itemNumber==0)
        head=rear=x;
    else
    {
        rear->next=x;
        rear=x;
    }
    itemNumber++;
    return true;
}

template<class Type>
bool QueueTp<Type>::DeQueue(Type &temp)
{
    if(itemNumber==0)
        return false;
    //std::cout<<head->data<<std::endl;
    temp=head->data;
    QNode<Type> * x=head;
    head=head->next;
    //std::cout<<head->data<<std::endl;
    delete x;
    if(itemNumber==1)
        rear=nullptr;
    itemNumber--;
    return true;
}


#endif /* QueueTp_hpp */
