#include<iostream>
#include"dma_1.hpp"

int abcDMA::View()const
{
    return rating;
}

abcDMA::~abcDMA()
{}
int baseDMA::View()const
{
    return reRating();
}
int baseDMA::test()
{
    return reRating();
}
void ccc(baseDMA & s)
{
    std::cout<<s.reRating()<<std::endl;
}
