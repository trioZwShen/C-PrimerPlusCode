#ifndef stcktp1_hpp
#define stcktp1_hpp
#include <stdio.h>

template<class Type>
class Stack
{
private:
    enum {SIZE=10};
    int stacksize;
    Type * items;
    int top;
public:
    explicit Stack(int ss=SIZE);    //默认构造函数
    Stack(const Stack & st);        //复制构造函数
    Stack & operator=(const Stack & st);//重载运算符
    ~Stack(){delete [] items;}      //析构函数
    
    bool isempty()const {return top==0;}
    bool isfull()const {return top==stacksize;}
    bool push(const Type & item);
    bool pop(Type & item);
};

/*模板成员方法定义*/
template <class Type>
Stack<Type>::Stack(int ss)
{
    top=0;stacksize=ss;
    items=new Type[ss];
}

template <class Type>
Stack<Type>::Stack(const Stack & st)
{
    top=st.top;
    items=new Type[st.stacksize];
}

template <class Type>
Stack<Type> & Stack<Type>::operator=(const Stack & st)  //返回类型写模板类的全名.
{
    if(this==&st)
        return *this;
    delete [] items;
    top=st.top;
    items=new Type[st.stacksize];
    return *this;
}

template<class Type>
bool Stack<Type>::push(const Type & item)
{
    if(top==stacksize)
    {
        return false;
    }
    else
    {
        std::cout<<"top"<<" ";
        items[top++]=item;
        return true;
    }
}

template<class Type>
bool Stack<Type>::pop(Type & item)
{
    if(top==0)
        return false;
    else
    {
        item=items[--top];
        return true;
    }
}
#endif /* stcktp1_hpp */
