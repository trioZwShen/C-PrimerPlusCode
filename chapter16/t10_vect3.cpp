#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<memory>
using std::string;
using std::endl;
using std::cout;
using std::cin;
using std::vector;
using std::shared_ptr;
struct Review
{
    string title;
    double price;	//添加成员
    int rating;
};

bool operator<(shared_ptr<Review> r1,shared_ptr<Review> r2);
bool worseThan(shared_ptr<Review> r1,shared_ptr<Review> r2);
bool FillReview(Review & rr);
void ShowReview(shared_ptr<Review> rr);


int main()
{
    vector<Review> books_list;
    Review temp;
    int num=1;
    while(FillReview(temp))
   	{
        books_list.push_back(temp);
        num++;
    }
    vector<shared_ptr<Review>> books(--num);
    for (int i=0;i<num;i++)
    	books[i]=shared_ptr<Review>(new Review(books_list[i]));


    if(books.size()>0)
    {
        cout<<"Thank you. You entered the following "
        <<books.size()<<" ratings:\n"<<"Rating \tbooks \tprice\n";
        for(int i=0;i<books.size();i++)
            cout<<(*books[i]).rating<<"\t"<<(*books[i]).title<<"\t"<<(*books[i]).price<<endl;
        cout<<endl;
        
        
        sort(books.begin(),books.end());
        cout<<"Sorted by title:\nRating\tBOOK\tPRICE\n";
        for(int i=0;i<books.size();i++)
            cout<<(*books[i]).rating<<"\t"<<(*books[i]).title<<"\t"<<(*books[i]).price<<endl;
        cout<<endl;
        
        cout<<"Sorted by rating:\nRating\tBOOK\tPRICE\n";
        sort(books.rbegin(),books.rend(),worseThan);
        for(int i=0;i<books.size();i++)
            cout<<(*books[i]).rating<<"\t"<<(*books[i]).title<<"\t"<<(*books[i]).price<<endl;
        cout<<endl;
        /*
        random_shuffle(books.begin(),books.end());
        cout<<"After shuffling:\nRating\tBook\n";
        for_each(books.begin(),books.end(),ShowReview);
        cout<<endl;
        */
    }
    else
        cout<<"No entries.";
    cout<<"Bye!\n";
    return 0;

}

bool operator<(shared_ptr<Review> r1,shared_ptr<Review> r2)
{
    if(r1->title<r2->title)
        return true;
    else if(r1->title==r2->title && r1->rating<r2->rating)
        return true;
    else
        return false;
}

bool worseThan(shared_ptr<Review> r1,shared_ptr<Review> r2)
{
    if(r1->rating<r2->rating)
        return true;
    else
        return false;
}

bool FillReview(Review & rr)
{
    cout<<"Enter book title (quit to quit): ";
    getline(cin,rr.title);
    if(rr.title=="quit")
        return false;
    cout<<"Enter book rating: ";
    cin>>rr.rating;
    cout<<"Enter book price: ";
    cin>>rr.price;
    if(!cin)
        return false;
    while(cin.get()!='\n')
        continue;
    return true;
}

void ShowReview(shared_ptr<Review> rr)
{
    cout<<rr->rating<<"\t"<<rr->title<<endl;
}
