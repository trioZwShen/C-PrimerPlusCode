#ifndef tv_hpp
#define tv_hpp
#include<iostream>
#include<stdio.h>

class Tv
{
public:
    friend class Remote;    //声明Remote是Tv的友元类
    enum{Off,On};
    enum{MinVal,MaxVal=20};
    enum{Antenna,Cable};
    enum{TV,DVD};
    
    Tv(int s=Off,int mc=125):state(s),volume(mc),maxchannel(mc),channel(2),mode(Cable),input(TV){}
    void onoff(){state=(state==On)?Off:On;} //一种切换状态的方法.
    bool ison()const {return state==On;}
    bool volup();
    bool voldown();
    void chanup();
    void chandown();
    void set_mode(){mode=(mode==Antenna)?Cable:Antenna;}
    void set_input(){input=(input==TV)?DVD:TV;}
    void settings()const;
    
private:
    int state;
    int volume;
    int maxchannel;
    int channel;
    int mode;
    int input;
};
class Remote
{
private:
    int mode;
public:
    Remote(int m=Tv::TV):mode(m){}
    bool volup(Tv & t){return t.volup();}
    bool vodown(Tv & t){return t.voldown();}
    void onoff(Tv & t){t.onoff();}
    void chanup(Tv & t){t.chanup();}
    void chandown(Tv & t){t.chandown();}
    void set_chan(Tv & t,int c){t.channel=c;}
    void set_mode(Tv & t){t.set_mode();}
    void set_input(Tv & t){t.set_input();}
};

#endif
