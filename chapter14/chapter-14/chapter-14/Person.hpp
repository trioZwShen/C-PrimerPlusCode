//
//  Person.hpp
//  chapter-14
//
//  Created by SZW on 2017/9/26.
//  Copyright © 2017年 SZW. All rights reserved.
//

#ifndef Person_hpp
#define Person_hpp

#include <stdio.h>
#include<string>
#include <iostream>
using std::string;
using std::cout;
using std::cin;
using std::endl;
/*保存人的名和姓,Show()方法(显示名和姓).*/
class Person
{
private:
    string firstname;
    string lastname;
protected:
    virtual void Get();
public:
    Person(const string & fn="No one",const string ln="bala"):firstname(fn),lastname(ln){}
    virtual void Show()const{cout<<firstname<<" "<<lastname<<endl;}
    virtual void Set(){Get();}
};

/*由Person虚基类而来,Draw()方法(返回一个double,表示拔枪时间),Show()方法(显示所有信息)*/
class Gunslinger:public virtual Person
{
private:
    int NickNum;
    double GunTime;
protected:
    void Get();
public:
    Gunslinger(const string & fn="No one",const string ln="bala",int NNum=0,double GTime=0)
    :Person::Person(fn,ln),NickNum(NNum),GunTime(GTime){}
    Gunslinger(const Person & pt,int NNum,double GTime)
    :Person::Person(pt),NickNum(NNum),GunTime(GTime){}
    double Draw()const {return GunTime;}
    void Set(){Person::Get();Get();}
    void Show()const {Person::Show();cout<<"NickNum: "<<NickNum<<" GunTime: "<<GunTime<<endl;}
};

/*由Person虚基类派生,Draw()方法()(返回1-52),使用Person的Show()*/
class PokerPlayer:public virtual Person
{
public:
    PokerPlayer(const string & fn="No one",const string ln="bala"):Person::Person(fn,ln){}
    int Draw()const{return rand()%52;}
    void Set(){Person::Get();}
};

/*由Gunslinger和PokerPlayer公有派生而来,Gdraw()返回把枪时间,Cdraw()返回扑克,Show()*/
class BadDude:public Gunslinger,public PokerPlayer
{
public:
    BadDude(const string & fn="No one",const string ln="bala",int NNum=0,double GTime=0)
    :Person::Person(fn,ln),Gunslinger::Gunslinger(fn,ln,NNum,GTime){}
    BadDude(const Person & pt,int NNum,double GTime)
    :Gunslinger::Gunslinger(pt,NNum,GTime){}
    double Gdraw()const{return Gunslinger::Draw();}
    int Cdraw()const{return PokerPlayer::Draw();}
    void Show()const{Gunslinger::Show();cout<<"The next poker card: "<<Cdraw()<<endl;}
    void Set(){Person::Get();Gunslinger::Get();}
};
#endif /* Person_hpp */
