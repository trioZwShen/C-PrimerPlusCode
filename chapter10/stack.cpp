//10.11
#include<iostream>
#include"stack.h"

//将数据压入栈顶
bool Stack::push(const Item & e)
{
	if(m_top>=MAX)
		return false;
	m_items[m_top++]=e;
	return true;
}
//将数据弹出
bool Stack::pop(Item & e)
{
	if(m_top<=0)
	{
		e=0;
		printf("空\n");
		return false;
	}
    e=m_items[--m_top];
	return true;
}
//检查栈是否满
bool Stack::isfull()const
{
	return m_top==MAX;
}
//检查栈是否空
bool Stack::isempty()const
{
	return m_top==0;
}
