//头文件
#include<iostream>
#include<fstream>
#include<string>

//抽象基类
class abstr_emp	
{
private:
	std::string fname;	//first name
	std::string lname;	//last name
	std::string job;	//工作
public:
	abstr_emp();					//构造函数1, 默认构造函数
	abstr_emp(const std::string & fn, const std::string & ln, 
		const std::string & j);		//构造函数2
	virtual void ShowAll() const;	//虚函数1, 显示全部信息
	virtual void SetAll();			//虚函数2, 设置全部信息
	virtual ~abstr_emp()=0;			//虚函数3, 纯虚函数, 析构函数
    virtual void WriteAll(std::ofstream & os) const;  //虚函数4, 用于将数据写入文本
    virtual void GetAll(std::ifstream & is);  //虚函数5, 用于将读取文本
	friend std::ostream & operator<<(std::ostream & os,
		const abstr_emp & e);		//友元, 重载operator<<
	// 显示first与last name
};


//由abstr_emp公有派生
class employee:public abstr_emp 
{
public:
	employee();						//构造函数1,默认构造函数
	employee(const std::string & fn, const std::string & ln,
		const std::string & j);		//构造函数2
	virtual void ShowAll()const;	//虚函数1, 显示全部信息
	virtual void SetAll();			//虚函数2, 设置全部信息
    virtual void WriteAll(std::ofstream & os) const;  //虚函数3, 用于将数据写入文本
    virtual void GetAll(std::ifstream & is);  //虚函数4, 用于将读取文本
};

//由abstr_emp公有派生, 且abstr_emp为虚基类
class manager: virtual public abstr_emp
{
private:
	int inchargeof;		//新的私有成员
protected:
	int InChargeof()const {return inchargeof;}	//输出
	int & InChargeof() {return inchargeof;}		//输入
public:
	manager();							//构造函数1, 默认构造函数
	manager(const std::string & fn, const std::string & ln,
		const std::string & j, int ico=0);	//构造函数2
	manager(const abstr_emp & e, int ico);	//构造函数3
	manager(const manager & m);				//构造函数4
	virtual void ShowAll()const;	//虚函数1, 显示全部信息
	virtual void SetAll();			//虚函数2, 设置全部信息
    virtual void WriteAll(std::ofstream & os) const;  //虚函数3, 用于将数据写入文本
    virtual void GetAll(std::ifstream & is);  //虚函数4, 用于将读取文本
};


//由abstr_emp公有派生, 且abstr_emp为虚基类
class fink: virtual public abstr_emp
{
private:
	std::string reportsto;		//新的私有成员
protected:
	const std::string ReportsTo()const {return reportsto;}	//输出
	std::string & ReportsTo() {return reportsto;}			//输入
public:
	fink();							//构造函数1, 默认构造函数
	fink(const std::string & fn, const std::string & ln,
		const std::string & j, const std::string & rpo);//构造函数2
	fink(const abstr_emp & e, const std::string & rpo);	//构造函数3
	fink(const fink & f);								//构造函数4
	virtual void ShowAll()const;	//虚函数1, 显示全部信息
	virtual void SetAll();			//虚函数2, 设置全部信息
    virtual void WriteAll(std::ofstream & os) const;  //虚函数3, 用于将数据写入文本
    virtual void GetAll(std::ifstream & is);  //虚函数4, 用于将读取文本
};


//由manager和fink多重继承而来, 而且用到了虚基类abstr_emp
class highfink : public manager, public fink
{
public:
	highfink();		//构造函数1, 默认构造函数
	highfink(const std::string & fn, const std::string & ln,
		const std::string & j, const std::string & rpo,
		int ico);	//构造函数2
	highfink(const abstr_emp & e, const std::string & rpo,
		int ico);	//构造函数3
	highfink(const manager & m, const std::string & rpo);//构造函数4
	highfink(const fink & f, int ico);		//构造函数5
	highfink(const highfink & h);			//构造函数6
	virtual void ShowAll()const;	//虚函数1, 显示全部信息
	virtual void SetAll();			//虚函数2, 设置全部信息
    virtual void WriteAll(std::ofstream & os) const;  //虚函数3 用于将数据写入文本
    virtual void GetAll(std::ifstream & is);  //虚函数4, 用于将读取文本
};
