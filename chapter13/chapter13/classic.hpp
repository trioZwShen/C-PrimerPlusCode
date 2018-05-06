//
//  classic.hpp
//  chapter13
//
//  Created by SZW on 2017/8/29.
//  Copyright © 2017年 SZW. All rights reserved.
//

#ifndef classic_hpp
#define classic_hpp

#include <stdio.h>
class Cd
{
private:
    char performers[50];
    char label[20];
    int selections;
    double playtime;
public:
    Cd(char * s1,char * s2,int n,double x);
    Cd();
    virtual ~Cd();
    virtual void Report() const;
};

class Classic: public Cd
{
private:
    char import_work[50];
public:
    Classic(char * s1,char * s2,int n,double x,char * s3);
    Classic();
    Classic(const Cd & st,char * s3);
    void Report() const;
};





#endif /* classic_hpp */
