#ifndef tvfm_hpp
#define tvfm_hpp
#include<iostream>
#include<stdio.h>

class Tv;

class Remote
{
public:
    enum State{Off,On};
    enum {MinVal,MaxVal=20};
    enum {Antenna,Cable};
    enum {TV,DVD};
private:
    int mode;
public:
    /*
    Remote(int m=Tv::TV):mode(m){}
    
    */
    Remote(int m=TV):mode(m){}
    bool volup(Tv & t);
    bool vodown(Tv & t);
    void onoff(Tv & t);
    void chanup(Tv & t);
    void chandown(Tv & t);
    void set_mode(Tv & t);
    void set_input(Tv & t);
    
    void set_chan(Tv & t,int c);    //在Tv中声明为Tv的友元函数
};




class Tv
{
public:
    friend void Remote::set_chan(Tv & t,int c);    //声明set_chan()为Tv的友元函数.
    enum State{Off,On};
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

//Remote的方法定义
inline bool Remote::volup(Tv & t){return t.volup();}
inline bool Remote::vodown(Tv & t){return t.voldown();}
inline void Remote::onoff(Tv & t){t.onoff();}
inline void Remote::chanup(Tv & t){t.chanup();}
inline void Remote::chandown(Tv & t){t.chandown();}
inline void Remote::set_mode(Tv & t){t.set_mode();}
inline void Remote::set_input(Tv & t){t.set_input();}

inline void Remote::set_chan(Tv & t,int c){t.channel=c;}

#endif
