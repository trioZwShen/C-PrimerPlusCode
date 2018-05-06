//
//  14_15_stcktp1.hpp
//  Chapter14_
//
//  Created by SZW on 2018/3/5.
//  Copyright © 2018年 SZW. All rights reserved.
//

#ifndef _4_15_stcktp1_hpp
#define _4_15_stcktp1_hpp

#include <stdio.h>

template<typename Type>
class Stack{
private:
    enum{MAX=10};
    Type * items;   //数据部分
    int stacksize;  //栈最大尺寸
    int top;        //栈顶指针
public:
    explicit Stack(int size=MAX);           //(1)默认构造函数
    Stack(const Stack & st);                //(2)复制构造函数
    Stack & operator=(const Stack & st);    //(3)重载赋值运算符
    ~Stack();                               //(4)析构函数
    
    /*普通类方法*/
    bool isempty()const;
    bool isfully()const;
    bool Push(const Type & t);
    bool Pop();
    bool Top(Type & t);
};

/*构造函数与析构函数*/
//(1)默认构造函数
template<typename Type>
Stack<Type>::Stack(int size){
    stacksize=size;
    top=0;
    items=new Type[size];
}
//(2)复制构造函数
template<typename Type>
Stack<Type>::Stack(const Stack<Type> & st){
    stacksize=st.stacksize;
    top=st.top;
    items=new Type[stacksize];
    
    for(int i=0;i<stacksize;++i){
        items[i]=st.items[i];
    }
}
//(3)重载赋值运算符, 高级版本
template<typename Type>
Stack<Type> & Stack<Type>::operator=(const Stack<Type> & st){
    if(&st!=this){
        Stack<Type> tempStack(st);      //通过复制构造函数创建临时栈
        Type * tempP=tempStack.items;   //创建临时指针,用于交换*this与临时栈的数据部分
        tempStack.items=items;
        items=tempP;
        
        stacksize=st.stacksize;         //给*this对象成员初始化
        top=st.top;
    }
    return *this;
}

template<typename Type>
Stack<Type>::~Stack(){                               //(4)析构函数
    delete [] items;
}

/*普通类方法*/
template<typename Type>
bool Stack<Type>::isempty()const{
    return top==0;
}
template<typename Type>
bool Stack<Type>::isfully()const{
    return top==stacksize;
}
template<typename Type>
bool Stack<Type>::Push(const Type & t){
    if(isfully())
        return false;
    items[top++]=t;
    return true;
}

template<typename Type>
bool Stack<Type>::Pop(){
    if(isempty())
        return false;
    top--;
    return true;
}

template<typename Type>
bool Stack<Type>::Top(Type & t){
    if(isempty())
        return false;
    t=items[top-1];
    return true;
}
#endif /* _4_15_stcktp1_hpp */
