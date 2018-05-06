//
//  stacktp.hpp
//  chapter-14
//
//  Created by SZW on 2017/9/22.
//  Copyright © 2017年 SZW. All rights reserved.
//

#ifndef stacktp_hpp
#define stacktp_hpp

#include <stdio.h>
template<class Type>
class Stack
{
private:
    enum {MAX=10};
    Type items[MAX];
    int top;
public:
    Stack();
    bool isempty()const;
    bool isfull()const;
    bool push(const Type & item);
    bool pop(Type & item);
};

/*模板成员方法定义*/
template <class Type>
Stack<Type>::Stack()
{
    top=0;
}

template<class Type>
bool Stack<Type>::isempty()const
{
    if(top==0)
        return 1;
    else
        return 0;
}
template<class Type>
bool Stack<Type>::isfull()const
{
    return top==MAX;
}

template<class Type>
bool Stack<Type>::push(const Type & item)
{
    if(top==MAX)
        return false;
    else
    {
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

#endif /* stacktp_hpp */
