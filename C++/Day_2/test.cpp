#include<iostream>
#include<complex>
using namespace std;
class Date{
    public:
    Date (int y=0,int m=0,int d=0)
    :year(y),month(m),day(d)
    {

    }
    void Print()
    {
        cout<<year<<":"<<month<<":"<<day<<endl;
    }
    private:
    int year;
    int month;
    int day;
    

};

int main()
{
    Date s1(2025,7,19);
    s1.Print();
    
    return 0;
}
