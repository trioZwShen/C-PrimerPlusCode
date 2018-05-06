#include<iostream>
#include"dma_1.hpp"
using namespace std;
int main()
{
    baseDMA x;
    baseDMA y(10);
    cout<<"szw\n";
    cout<<x.View()<<endl<<y.View()<<endl;
    cout<<x.reRating()<<endl;
    ccc(y);
    return 0;
}
