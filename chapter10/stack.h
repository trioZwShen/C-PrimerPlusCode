//10.10
//定义一个栈
#ifndef STACK_H_
#define STACK_H_
typedef unsigned long Item;

class Stack
{
private:
	enum{MAX=10};
	Item m_items[MAX];
	int m_top;
public:
	//可创建空栈,构造函数
	Stack(){m_top=0;}	//栈顶指向数组第一个元素位置
	//将数据压入栈顶
	bool push(const Item & e);
	//将数据弹出
	bool pop(Item & e);
	//检查栈是否满
	bool isfull()const;
	//检查栈是否空
	bool isempty()const; 
};
#endif