//
//  11_14_vector.hpp
//  chapter11
//
//  Created by SZW on 2018/1/25.
//  Copyright © 2018年 SZW. All rights reserved.
//

#ifndef _1_14_vector_hpp
#define _1_14_vector_hpp

#include <stdio.h>
#include<iostream>
//名称空间VECTOR
namespace VECTOR
{
    //定义类vector
    class Vector
    {
    public:
        enum Mode{RECT,POL};    //定义一种枚举类型
    private:
        //私有数据成员
        double _x;
        double _y;
        double _mag;
        double _ang;
        Mode _mode;
        
        //私有成员函数
        void set_mag();
        void set_ang();
        void set_x();
        void set_y();
    public:
        //公有成员函数
        Vector();
        Vector(double n1,double n2,Mode form=RECT);
        virtual ~Vector();
        double xval()const{return _x;}
        double yval()const{return _y;}
        double magval()const{return _mag;}
        double angval()const{return _ang;}
        void polar_mode(){_mode=POL;}
        void rect_mode(){_mode=RECT;}
        void reset(double n1,double n2,Mode form=RECT);
        
        //重载运算符
        Vector operator+(const Vector & b)const;
        Vector operator-(const Vector & b)const;
        Vector operator-()const;
        Vector operator*(double n)const;
        
        //友元
        friend Vector operator*(double n,const Vector & a);
        friend std::ostream & operator<<(std::ostream & os,const Vector & v);
    };
}
#endif /* _1_14_vector_hpp */
