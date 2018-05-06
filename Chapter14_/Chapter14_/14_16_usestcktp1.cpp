//
//  14_15_stcktp1.cpp
//  Chapter14_
//
//  Created by SZW on 2018/3/5.
//  Copyright © 2018年 SZW. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "14_15_stcktp1.hpp"

const int Num=10;

int main(){
    using namespace std;
    srand(time(0));
    cout<<"Please enter stack size: ";
    int stacksize;
    cin>>stacksize;
    //创建一个字符串常量指针栈
    Stack<const char *> st(stacksize);
    
    //创建一个字符串常量数组
    const char * in[]={"1:HG","2:KI","3:BR","4:IF","5:WK","6:PK","7:JA","8:XP","9:JM","10:MM"};
    
    const char *out[Num];
    int processed=0;
    int nextin=0;
    while(processed<Num){
        if(st.isempty())                    //如果空栈, 则将in中一个字符串入栈
            st.Push(in[nextin++]);
        else if(st.isfully()){              //如果满栈, 则将栈顶字符串出栈,并置入out
            st.Top(out[processed++]);
            st.Pop();
        }
        else if(std::rand()%2 && nextin<Num)
            st.Push(in[nextin++]);
        else{
            st.Top(out[processed++]);
            st.Pop();
        }
    }
    
    for(int i=0;i<Num;++i){
        cout<<out[i]<<endl;
    }
    cout<<"Bye!\n";
    return 0;
    
}
