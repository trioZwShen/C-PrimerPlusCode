#ifndef dma_1_hpp
#define dma_1_hpp
class abcDMA
{
private:
    int rating;
public:
    int reRating()const{return rating;}
    abcDMA(int i=0){rating=i;}
    virtual ~abcDMA();
    virtual int View()const =0;
};

class baseDMA:public abcDMA
{
public:
    baseDMA(int i=0):abcDMA(i){}
    //~baseDMA();
    int test();
    int View()const;
    friend void ccc(baseDMA & s);
};

#endif
