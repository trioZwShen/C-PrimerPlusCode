#ifndef tv_hpp
#define tv_hpp
#include<iostream>
#include<stdio.h>

class Remote;   //前向声明

class Tv
{
private:
    int state;
    int volume;
    int maxchannel;
    int channel;
    int mode;
    int input;
    
public:
    friend class Remote;    //声明Remote是Tv的友元类
    enum{Off,On};
    enum{MinVal,MaxVal=20};
    enum{Antenna,Cable};
    enum{TV,DVD};
    enum{NORMAL,INTERACT};  //定义两个新的枚举类型.
    
    Tv(int s=Off,int mc=125) : state(s),volume(mc),maxchannel(mc),channel(2),mode(Cable),input(TV){}
    void onoff(){state=(state==On)?Off:On;} //一种切换状态的方法.
    bool ison()const {return state==On;}
    bool volup();
    bool voldown();
    void chanup();
    void chandown();
    void set_mode(){mode=(mode==Antenna)?Cable:Antenna;}
    void set_input(){input=(input==TV)?DVD:TV;}
    void settings()const;
    void set_Remote(Remote & s);    //控制Remote中的新成员,不能有具体的定义,因为前向声明中不包含具体声明.
};

class Remote
{
    friend class Tv;    //互为友元
private:
    int mode;
    int act;    //新成员,act=Interact为互动模式,act=Normal为常规模式
public:
    Remote(int m=Tv::TV):mode(m),act(Tv::NORMAL){}  //修改默认构造函数
    bool volup(Tv & t){return t.volup();}
    bool vodown(Tv & t){return t.voldown();}
    void onoff(Tv & t){t.onoff();}
    void chanup(Tv & t){t.chanup();}
    void chandown(Tv & t){t.chandown();}
    void set_chan(Tv & t,int c){t.channel=c;}
    void set_mode(Tv & t){t.set_mode();}
    void set_input(Tv & t){t.set_input();}
    
    void show_mode()const{std::cout<<mode<<" : "<<act<<std::endl;}  //显示mode
};

#endif
