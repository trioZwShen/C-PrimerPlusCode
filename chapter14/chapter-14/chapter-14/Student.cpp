//
//  Student.cpp
//  chapter-14
//
//  Created by SZW on 2017/9/11.
//  Copyright © 2017年 SZW. All rights reserved.
//

#include "Student.hpp"
//private method
std::ostream & Student::arr_out(std::ostream & os)const
{
    int i;
    int lim=scores.size();
    if(lim>0)
    {
        for(i=0;i<lim;i++)
        {
            os<<scores[i]<<" ";
            if(i%5==4)
                os<<std::endl;
        }
        if(i%5!=0)
            os<<std::endl;

    }
    else
        os<<"Empty array!\n";
    return os;
}


//public method
double Student::Average()const
{
    if(scores.size()>0)
        return scores.sum()/scores.size();
    else
        return 0;
}
const std::string & Student::Name()const
{
    return name;
}
double & Student::operator[](int i)
{
    return scores[i];
}
double Student::operator[](int i)const
{
    return scores[i];
}

//friend function
std::istream & operator>>(std::istream & is,Student & stu)
{
    is>>stu.name;
    return is;
}
std::istream & getline(std::istream & is,Student & stu)
{
    getline(is,stu.name);
    return is;
}
std::ostream & operator<<(std::ostream & os,const Student & stu)
{
    os<<"Scores for "<<stu.name<<std::endl;
    stu.arr_out(os);
    return os;
}
