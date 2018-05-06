//
//  12_12_ATM_useQueue.cpp
//  chapter12
//
//  Created by SZW on 2018/2/4.
//  Copyright © 2018年 SZW. All rights reserved.
//
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include "12_10_queue.hpp"

const int MIN_PER_HR=60;

bool newcustomer(double x); //新用户检测

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::ios_base;
    
    //初始化随机数种子
    std::srand(int(std::time(0)));
    cout<<"Case Study: Bank of Heather Automatic Teller\n";
    int qs;
    cin>>qs;    //输入队列最大值
    //初始化一个最大长度为qs的队列line
    Queue line(qs);
    cout<<"输入仿真时长: ";
    int hours;
    cin>>hours;
    long cyclelimit = MIN_PER_HR * hours;
    
    cout<<"输入平均每小时的顾客数: ";
    double perhour;
    cin>>perhour;
    double min_per_cust;
    min_per_cust=MIN_PER_HR;
    
    Item temp;
    long turnaways=0;
    long customers=0;
    long served=0;
    long sum_line=0;
    int wait_time=0;
    long line_wait=0;
    
    for (int cycle=0;cycle<cyclelimit;++cycle)
    {
        if(newcustomer(min_per_cust))
        {
            if(line.isfull())
                turnaways++;
            else
            {
                customers++;
                temp.set(cycle);
                line.enqueue(temp);
            }
        }
        if(wait_time<=0 && !line.isempty())
        {
            line.dequeue(temp);
            wait_time=temp.ptime();
            line_wait+=cycle-temp.when();
            served++;
        }
        if(wait_time>0)
            wait_time--;
        sum_line+=line.queuecount();
    }
    
    if(customers>0)
    {
        cout<<"customers accepted: "<<customers<<endl;
        cout<<"  customers served: "<<served<<endl;
        cout<<"         turnaways: "<<turnaways<<endl;
        cout<<"average queue size: ";
        cout.precision(2);
        cout.setf(ios_base::fixed,ios_base::floatfield);
        cout<<(double)sum_line/cyclelimit<<endl;
        cout<<" average wait time: "
        <<(double) line_wait/served<<" minutes\n";
    }
    else
        cout<<"No customers!\n";
    cout<<"Done!\n";
    return 0;
}

bool newcustomer(double x)
{
    return (std::rand()*x/RAND_MAX<1);
}
