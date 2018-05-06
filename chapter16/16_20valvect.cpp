#include<iostream>
#include<algorithm>
#include<vector>
#include<valarray>
#include<iterator>
#include<functional>

int main()
{
	using namespace std;
	vector<double>data;
	double temp;
	cout<<"Enter numbers (<=0 to quit):\n";
	while(cin>>temp && temp>0)	
		data.push_back(temp);
	sort(data.begin(),data.end());
	int size=data.size();

	valarray<double>numbers(size);
	for (int i=0;i<size;i++)
		numbers[i]=data[i];
	valarray<double>sq_rts(size);
	sq_rts=sqrt(numbers);
	valarray<double>result(size);
	result=numbers+2.0*sq_rts;
	cout.setf(ios_base::fixed);
	cout.precision(4);

	ostream_iterator<double,char>out_iter(cout," ");
	copy(begin(result),end(result),out_iter);
	cout<<endl;
	return 0;

}