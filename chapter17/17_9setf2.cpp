#include<iostream>
#include<cmath>
int main()
{
	using std::cout;
	using std::endl;
	using std::ios_base;
	//设置左对齐
	cout.setf(ios_base::left,ios_base::adjustfield);
	//设置正号
	cout.setf(ios_base::showpos);
	//设置显示末尾0
	cout.setf(ios_base::showpoint);
	//设置精度为3位
	cout.precision(3);
	//cout.unsetf(ios_base::showpoint);    //关闭末尾0显示
	//对齐方式为左对齐
	//设置浮点型为科学计数法显示,并保存原有设置,精度为小数点的位数
	ios_base::fmtflags old=cout.setf(
		ios_base::scientific,ios_base::floatfield);
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
	cout.setf(ios_base::internal,ios_base::adjustfield);
	//恢复浮点数的表示方法为常规方法,精度为全部位数
	cout.setf(old,ios_base::floatfield);
	cout<<"Internal Justification:\n";
	for(n=1;n<=41;n+=10)
	{
		cout.width(4);
		cout<<n<<"|";
		cout.width(12);
		cout<<sqrt(double(n))<<"|\n";
	}

	//转换为右对齐
	cout.setf(ios_base::right,ios_base::adjustfield);
	//浮点数表示切换为定点表示法,精度表示小数点后位数
	cout.setf(ios_base::fixed,ios_base::floatfield);
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