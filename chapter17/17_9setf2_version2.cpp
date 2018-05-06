#include<iostream>
#include<cmath>
int main()
{
	using std::cout;
	using std::endl;
	using std::ios_base;
	//设置左对齐
	cout<<std::left;
	//设置正号
	cout<<std::showpos;
	//设置显示末尾0
	cout<<std::showpoint;
	//设置精度为3位
	cout.precision(3);
	//cout.unsetf(ios_base::showpoint);    //关闭末尾0显示
	//对齐方式为左对齐
	//设置浮点型为科学计数法显示,并保存原有设置,精度为小数点的位数
	cout<<std::scientific;
	//cout.unsetf(ios_base::floatfield);	//切换回默认显示模式
	cout<<"Left Justification:\n";
	long n;
	for(n=1;n<=41;n+=10)
	{
		cout.width(4);
		cout<<n<<"|";
		cout.width(12);
		cout<<sqrt(double(n))<<"|\n";
	}

	//转换对齐方式
	cout<<std::internal;
	//恢复浮点数的表示方法为常规方法,精度为全部位数
	cout.unsetf(ios_base::floatfield);
	cout<<"Internal Justification:\n";
	for(n=1;n<=41;n+=10)
	{
		cout.width(4);
		cout<<n<<"|";
		cout.width(12);
		cout<<sqrt(double(n))<<"|\n";
	}

	//转换为右对齐
	cout<<std::right;
	//浮点数表示切换为定点表示法,精度表示小数点后位数
	cout<<std::fixed;
	cout<<"Right Justification:\n";
	for(n=1;n<=41;n+=10)
	{
		cout.width(4);
		cout<<n<<"|";
		cout.width(12);
		cout<<sqrt(double(n))<<"|\n";
	}
	return 0;
}