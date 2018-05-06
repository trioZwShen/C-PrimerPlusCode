//
//  usePerson.cpp
//  chapter-14
//
//  Created by SZW on 2017/9/26.
//  Copyright © 2017年 SZW. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "Person.hpp"

int main()
{
    using namespace std;
    Person p1("s","zw");
    Gunslinger p2("s","zz",10,1.1);
    PokerPlayer p3("s","zx");
    BadDude p4("s","za",4,1.2);
    cout<<"p1"<<endl;
    p1.Show();
    cout<<"\np2"<<endl;
    p2.Show();
    cout<<"\np3"<<endl;
    p3.Show();
    cout<<"\np4"<<endl;
    p4.Show();
    Person *x[4];
    x[0]=new Person;
    x[0]->Set();
    x[1]=new Gunslinger;
    x[1]->Set();
    x[2]=new PokerPlayer;
    x[2]->Set();
    x[3]=new BadDude;
    x[3]->Set();
    cout<<"x1"<<endl;
    x[0]->Show();
    cout<<"\nx2"<<endl;
    x[1]->Show();
    cout<<"\nx3"<<endl;
    x[2]->Show();
    cout<<"\nx4"<<endl;
    x[3]->Show();
    
    return 0;
}

