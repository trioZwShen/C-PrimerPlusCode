#include<iostream>
#define MAXSIZE 20
#define ERROR 0
#define OK 1
typedef int Status;



/*两栈共享空间结构*/
typedef int SElemType;
typedef struct
{
    SElemType data[MAXSIZE];
    int top1;
    int top2;
}SqDoubleStack;

/*初始化栈*/
Status InitStack(SqDoubleStack *S)
{
    S->top1=-1;
    S->top2=MAXSIZE;
    return OK;
}

/*插入元素e为新的栈顶元素*/
Status Push(SqDoubleStack * S,SElemType e,int StackNumber)
{
    if(S->top1+1==S->top2)	//栈满
        return ERROR;
    if(StackNumber==1)
        S->data[++S->top1]=e;
    else if(StackNumber==2)
        S->data[--S->top2]=e;
    return OK;
}

/*若栈非空,则删除S的栈顶元素,用e返回*/
Status Pop(SqDoubleStack * S,SElemType *e,int StackNumber)
{
    if(StackNumber==1)
    {
        if(S->top1==-1)	//栈1为空,则溢出
            return ERROR;
        *e=S->data[S->top1--];//先赋值,再--
    }
    if(StackNumber==2)
    {
        if(S->top2==MAXSIZE)	//栈2为空栈,则溢出
            return ERROR;
        *e=S->data[S->top2++];//先赋值,再--
    }
    return OK;
}

int main()
{
    using namespace std;
    SqDoubleStack *S;
    S=(SqDoubleStack *)malloc(sizeof(SqDoubleStack));
    InitStack(S);
    cout<<S->top1<<" "<<S->top2<<endl;
    cout<<Push(S,10,1)<<endl;
    cout<<S->data[S->top1]<<endl;
    cout<<Push(S,20,1)<<endl;
    cout<<S->data[S->top1]<<endl;
    cout<<Push(S,30,2)<<endl;
    cout<<S->data[S->top2]<<endl;
    cout<<Push(S,40,2)<<endl;
    cout<<S->data[S->top2]<<endl;
    cout<<"==============="<<endl;
    int e;
    cout<<S->top1<<" "<<S->top2<<endl;
    cout<<Pop(S,&e,1)<<endl;
    cout<<S->top1<<" "<<S->top2<<endl;
    
    
    
    return 0;
    
}
