#include<iostream>
#include<cstdlib>
#include<ctime>
#include"stcktp1.hpp"

const int Num=10;
int main()
{
    using namespace std;
    cout<<"Please enter stack size: ";
    int stacksize;
    cin>>stacksize;
    Stack<const char *>st(stacksize);   //创建Stack
    const char * in[Num]=
    {
        "1:Hunk Gilgamesh","2:Kiki Ishtar","3:Betty Rocker",
        "4:Ian Flagranti","5:Wolfgang Kibble","6:Portia Koop","7:SZW","8:HuangHuang","9:Cy",
        "10:Misha Mache"
    };
    const char * out[Num];
    int processed=0;
    int nextin=0;
    //cout<<"test"<<endl;
    while(processed<Num)
    {
        //cout<<"test"<<endl;
        if(st.isempty())
            st.push(in[nextin++]);
        else if(st.isfull())
            st.pop(out[processed++]);
        else if(rand()%2 && nextin<Num)
            st.push(in[nextin++]);
        else
            st.pop(out[processed++]);
    }
    for(int i=0;i<Num;i++)
        cout<<out[i]<<endl;
    cout<<"BYE\n";
    return 0;
    
}
