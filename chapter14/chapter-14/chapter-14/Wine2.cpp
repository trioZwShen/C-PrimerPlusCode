

#include "Wine2.hpp"

Wine::Wine(const char * l,int y,const int yr[],const int bot[]):std::string(l),PairArray(ArrayInt(yr,y), ArrayInt(bot,y))
{
    yrs=y;
}
Wine::Wine(const char * l,int y):std::string(l)
{
    yrs=y;
}
void Wine::GetBottles()
{
    ArrayInt years(yrs);
    ArrayInt bottles(yrs);
    for(int i=0;i<yrs;i++)
    {
        std::cout<<"Enter the years: ";
        std::cin>>years[i];
        std::cout<<"Enter the bottle number: ";
        std::cin>>bottles[i];
    }
    while(std::cin.get()!='\n')
        continue;
    PairArray::Set(years,bottles);
}
std::string & Wine::Label()
{
    return (std::string &)(*this);
}
void Wine::Show()const
{
    std::cout<<"Wine: "<<(const std::string &)(*this)<<std::endl;
    std::cout<<"Year and Number: \n";
    PairArray::Show(yrs);
}
int Wine::sum()const
{
    return PairArray::Sum();
}
