#ifndef sales_hpp
#define sales_hpp
#include <stdexcept>
#include <string>


class Sales{
protected:
	enum{MOUTHS=12};	//枚举常量
private:
	double gross[MOUTHS];
	int year;
public:
	//嵌套异常类
	class bad_index:public std::logic_error{	
	private:
		int bi;
	public:
		//bad_index类的构造函数
		explicit bad_index(int ix, const std::string & s="Index error in Sales object\n");
		int bi_val()const {return bi;}	//输出bi
		virtual ~bad_index()throw(){}   //虚析构函数
	};

	/*构造函数与析构函数*/
	//Sales类的默认构造函数
	explicit Sales(int yy=0);
	//Sales类的构造函数
	Sales(int yy, const double * gr, int n);
	virtual ~Sales(){}

	//类方法
	int Year()const{return year;}
	virtual double operator[](int i)const;
	virtual double & operator[](int i);
};

class LabeledSales:public Sales{
private:
	std::string label;
public:
	/*嵌套异常类,继承自Sales的嵌套异常类*/
	class nbad_index: public Sales::bad_index{
	private:
		std::string lbl;
	public:
		//nbad_index的构造函数
		nbad_index(const std::string & lb, int ix,
			 const std::string & s="Index error in LabeledSales object\n");
		//返回错误label
		const std::string & label_val()const{return lbl;}
		virtual ~nbad_index()throw(){}
	};
	/*构造函数与析构函数*/
	//构造函数1
	explicit LabeledSales(const std::string & lb="none", int yy=0);
	//构造函数2
	LabeledSales(const std::string & lb, int yy, const double * gr, int n);
	virtual ~LabeledSales(){}

	/*方法*/
	//返回label
	const std::string & Label()const{return label;}
	virtual double operator[](int i)const;
	virtual double & operator[](int i);
};

#endif
