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
    char * performers;
    char * label;
    int selections;
    double playtime;
public:
    Cd(char * s1,char * s2,int n,double x);
    Cd();
    Cd(const Cd & st);//复制构造
    virtual ~Cd();
    virtual void Report() const;
    const Cd & operator=(const Cd & st);//赋值运算符
};

class Classic: public Cd
{
private:
    char * import_work;
public:
    Classic(char * s1,char * s2,int n,double x,char * s3);
    Classic();
    Classic(const Cd & st,char * s3);
    Classic(const Classic & st);//copy struct function
    void Report() const;
    const Classic & operator=(const Classic & st);//assignment operation function
};





#endif /* classic_hpp */
