//
//  t1_useBank.cpp
//  Chapter10
//
//  Created by SZW on 2018/1/24.
//  Copyright © 2018年 SZW. All rights reserved.
//

#include <stdio.h>
#include"Bank.hpp"

int main()
{
    using namespace std;
    Bank p1;
    Bank p2("szw","980092413",1000000000.1);
    Bank p3("lj","123321",100);
    p1.Show();
    p2.Show();
    p3.Show();
    p2.Deposit(30000.1);
    p2.Show();
    p2.Withdraw(1000);
    p2.Show();
    p3.Deposit(-1);
    p3.Withdraw(200);
    return 0;
}
