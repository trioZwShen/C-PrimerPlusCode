#include <stdio.h>
#include<iostream>
#include"tv.hpp"

int main()
{
    using std::cout;
    Tv s42;
    cout<<"Initial settings for 42\"TV:\n";
    s42.settings();
    s42.onoff();
    s42.settings();
    s42.chanup();
    cout<<"\nAdjusted settings for 42\"TV:\n";
    s42.chanup();
    cout<<"\nAdjusted settings for 42\"TV:\n";
    s42.settings();

    Remote grey;
    grey.set_chan(s42,10);
    grey.volup(s42);
    grey.volup(s42);
    cout<<"\n42\" settings after using remotr:\n";
    s42.settings();

    Tv s58(Tv::On);
    s58.set_mode();
    grey.set_chan(s58, 28);
    cout<<"\n58\" settings:\n";
    s58.settings();

    cout<<"无情分割线-------------------\n";
    grey.show_mode();
    s58.onoff();
    s58.settings();
    s58.set_Remote(grey);
    grey.show_mode();
    
    return 0;
}
