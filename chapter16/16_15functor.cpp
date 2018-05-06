#include<iostream>
#include<list>
#include<iterator>
#include<algorithm>

//定义一个模板类,用作函数对象,函数符
template<class T>
class TooBig
{
private:
	T cutoff;
public:
	TooBig(const T & t):cutoff(t){}
    bool operator()(const T & v){return v>cutoff;}
};

//用于打印输出
void outint(int n){std::cout<<n<<" ";}

int main()
{


	using namespace std;
	TooBig<int>f100(100);	//初始化f100,传入控制取舍的值
	int vals[10]={50,100,90,180,60,210,415,88,128,201};
	list<int>yadayada(vals,vals+10);
	list<int>etcetera(vals,vals+10);
	//输出初始值
	cout<<"Original lists: \n";
	cout<<"yadayada: ";for_each(yadayada.begin(),yadayada.end(),outint);cout<<endl;
	cout<<"etcetera: ";for_each(etcetera.begin(),etcetera.end(),outint);cout<<endl;
	//使用函数符处理
	yadayada.remove_if(f100);
	etcetera.remove_if(TooBig<int>(200));
	//输出处理值
	cout<<"After processed: \n";
	cout<<"yadayada: ";for_each(yadayada.begin(),yadayada.end(),outint);cout<<endl;
	cout<<"etcetera: ";for_each(etcetera.begin(),etcetera.end(),outint);cout<<endl;
	return 0;

}