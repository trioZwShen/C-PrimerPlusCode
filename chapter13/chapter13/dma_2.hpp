//
//  dma.hpp
//  chapter13
//
//  Created by SZW on 2017/8/24.
//  Copyright © 2017年 SZW. All rights reserved.
//

#ifndef dma_2_hpp
#define dma_2_hpp

#include <stdio.h>
#include<iostream>

class abcDMA
{
private:
    int rating;
    char * temp;
public:
    void setRating(const abcDMA & rs){rating=rs.rating;}
    abcDMA(int r,const char * c){rating = r;temp =new char[strlen(c)+1];strcpy(temp,"szw");}
    virtual ~abcDMA(){};
    virtual void View()const=0;
    abcDMA & operator=(const abcDMA & st);
};

class baseDMA:public abcDMA
{
private:
    char * label;
public:
    baseDMA(const char * l ="null",int r=0,const char * s="szw");
    baseDMA(const baseDMA & rs);
    virtual ~baseDMA();
    baseDMA & operator=(const baseDMA & rs);
    virtual void View()const;
    friend std::ostream & operator<<(std::ostream & os,const baseDMA & rs);
    
};

#endif /* dma_2_hpp */
