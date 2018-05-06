#include<iostream>
#include"10_1_stock00.hpp"

int main()
{
    using namespace std;
	Stock a;
    a.acquire("szw", 10, 5);
    a.show();
    cout<<endl;
    a.sell(3, 5);
    a.show();
    cout<<endl;
    a.buy(3, 6);
    a.show();
    cout<<endl;
    a.updata(8);
    a.show();
	return 0;
}
