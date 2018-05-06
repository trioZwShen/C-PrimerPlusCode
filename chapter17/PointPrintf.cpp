//输出几字型曲线的顶点
#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<iomanip>

struct Point	//直角坐标系下的点
{
	double x;
	double y;
};

//根据输入的长宽,间隔,方向,以及初始点将几字形曲线顶点存到一个vector对象中输出
std::vector<Point> PointOut(double, double, double, double, Point &);


int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

	//数据初始化
	cout<<"Enter the length: ";
	double dLen;
	cin>>dLen;

	cout<<"Enter the width: ";
	double dWid;
	cin>>dWid;

	cout<<"Enter the interval: ";
	double dInter;
	cin>>dInter;

	cout<<"Enter the angle: ";//输入角度
	double dAng;
	cin>>dAng;
	dAng=dAng*3.1415926535898/180;	//转换成弧度

	Point p0;
	cout<<"Enter the x of initial point: ";
	cin>>p0.x;
	cout<<"Enter the y of initial point: ";
	cin>>p0.y;

	std::vector<Point> result;
	result=PointOut(dLen, dWid, dInter, dAng, p0);
	
	cout.setf(std::ios_base::showpoint);
	cout.precision(4);
	for (int i=0;i<result.size();i++)
		cout<<"#"<<std::setw(4)<<i<<" ("<<std::setw(6)<<result[i].x
			<<" , "<<std::setw(6)<<result[i].y<<")"<<endl;
	
	return 0;

}


std::vector<Point> PointOut(double dLen, double dWid, double dInter, double dAng, Point & p0)
{
	using namespace std;
	vector<Point> points;	//存放输出点的vector对象
	double dStepX,dStepY;
	dStepX=dInter*cos(dAng);
	dStepY=dInter*sin(dAng);

	Point tempA=p0;
	points.push_back(tempA);//存入初始点
	tempA.x+=dStepX;
	tempA.y+=dStepY;
	points.push_back(tempA);//存入第二个点

	Point tempB=tempA;
	if (dAng>=0)
	{
		tempB.x += dWid*sin(dAng);
		tempB.y -= dWid*cos(dAng);
	}
	else
	{
		tempB.x -= dWid*sin(dAng);
		tempB.y += dWid*cos(dAng);
	}
	points.push_back(tempB);//存入第三个点
	
	double dDis=sqrt(tempA.x*tempA.x+tempA.y*tempA.y);
	if (dDis>=dLen)
	{
		cout<<"END\n";
		return points;
	}

	do
	{
		tempB.x+=dStepX;
		tempB.y+=dStepY;
		points.push_back(tempB);
		tempA.x+=dStepX;
		tempA.y+=dStepY;
		points.push_back(tempA);
		dDis=sqrt(tempA.x*tempA.x+tempA.y*tempA.y);
		//cout<<dDis<<endl;
	}
	while(dDis<dLen);
	return points;
}
