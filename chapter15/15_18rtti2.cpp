#include<iostream>
#include<cstdlib>
#include<typeinfo>
#include<ctime>

using namespace std;
//类
class Grand
{
private:
	int hold;
public:
	Grand(int h=0):hold(h){}	//默认构造函数
	virtual void Speak()const 
		{cout << "I am a grand class!\n";} 	//虚函数
	virtual int Value() const {return hold;}	//虚函数
};

//由Grand公有派生Superb类
class Superb : public Grand
{
public:
	Superb(int h=0):Grand(h){}	//默认构造函数
	void Speak() const			//Speak重定义
		{cout<<"I am a superb class!\n";}		
	virtual void Say() const					//虚函数
		{cout<<"I hold the superb value of "<<Value()<<"!\n";}
};

//由Superb公有派生Magnificent类
class Magnificent : public Superb
{
private:
	char ch;
public:
	Magnificent(int h=0,char c='A'):Superb(h),ch(c){}
	void Speak() const			//Speak重定义
		{cout<<"I am a Magnificent class!\n";}
	void Say() const	//Say重定义
		{cout<<"I hold the Magnificent value of "<<Value()<<"!\n";}
};

//GetOne原型定义
Grand * GetOne();

int main()
{
	std::srand(std::time(0));
	Grand * pg;
	Superb * ps;
	for (int i=0;i<10;i++)
	{
		pg=GetOne();
		//使用type_info类对象的name()成员
		cout<<"Now processing type "<<typeid(*pg).name()<<".\n";
		pg->Speak();
		if(ps=dynamic_cast<Superb *>(pg))	//只有当能够安全转换时才执行转换
			ps->Say();
		//判断pg是否是一个真的Magnificent指针
		if(typeid(Magnificent)==typeid(*pg))
			cout<<"Yes, you're really magnificent.\n";
		else
			cout<<"No.\n";
	}
	return 0;
}

Grand * GetOne()
{
	Grand * p;
	switch(std::rand()%3)
	{
		case 0:p=new Grand(std::rand()%100);break;
		case 1:p=new Superb(std::rand()%100);break;
		case 2:p=new Magnificent(std::rand()%100,'A'+std::rand()%26);break;
	}
	return p;
}