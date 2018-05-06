//
//  14_10_worekermi.cpp
//  Chapter14_
//
//  Created by SZW on 2018/3/4.
//  Copyright © 2018年 SZW. All rights reserved.
//
#include <iostream>
#include <string>
#include "14_10_worekermi.hpp"

using std::cin;
using std::cout;
using std::endl;

/*抽象基类*/
Worker::~Worker(){}
void Worker::subShow()const{
    cout<<fullname<<": "<<id<<endl;
}
void Worker::subSet(){
    cout<<"Enter the fullname: ";
    cin>>fullname;
    cout<<"Enter the id number: ";
    cin>>id;
}


/*第一层派生*/
/*派生类1*/
void Waiter::subShow()const{
    cout<<"Panache: "<<panache<<endl;
}
void Waiter::subSet(){
    cout<<"Enter the panache: ";
    cin>>panache;
}
void Waiter::Show() const{
    cout<<"Waiter: \n";
    Worker::subShow();
    subShow();
}
void Waiter::Set(){
    cout<<"Waiter: \n";
    Worker::subSet();
    subSet();
}

/*派生类2*/
char * Singer::pv[]={"other","alto","contralto","soprano","bass","baritone","tenor"};
void Singer::subShow()const{
    cout<<"voice: "<<pv[voice]<<endl;
}
void Singer::subSet(){
    cout<<"Enter the voice: ";
    cin>>voice;
}
void Singer::Show() const{
    cout<<"Singer: \n";
    Worker::subShow();
    subShow();
}
void Singer::Set(){
    cout<<"Singer: \n";
    Worker::subSet();
    subSet();
}

/*第二层派生*/
void SingingWaiter::subShow()const{
    Waiter::subShow();
    Singer::subShow();
}
void SingingWaiter::subSet(){
    Waiter::subSet();
    Singer::subSet();
}
void SingingWaiter::Show() const{
    cout<<"SingingWaiter: \n";
    Worker::subShow();
    subShow();
}
void SingingWaiter::Set(){
    cout<<"SingingWaiter: \n";
    Worker::subSet();
    subSet();
}
