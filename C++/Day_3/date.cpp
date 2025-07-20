#include<iostream>
#include<complex>
using namespace std;
class Date{
    public:
    int Getmonth(const int& y,const int& m)
    {
         static int Month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
        if(m==2&&((y%4==0&&y%100!=0)||y%400==0))
        {
            return 29;
        }

        return Month[m];

    }

    Date (int y=0,int m=0,int d=0)
    :year(y),month(m),day(d)
    {
       if(y>=0&&m>=1&&m<=12&&d>=1&&d<=Getmonth(y,m))
        {
                
        }
        else
        {
            cout<<"ERROR"<<endl;
        }
    
    }//构造函数
    Date(const Date& d)
    :year(d.year),month(d.month),day(d.day)
    {

    }//拷贝函数


    void Print()
    {
        cout<<year<<":"<<month<<":"<<day<<endl;
    }


    bool operator ==(const Date& d)
    {
        return year==d.year&&month==d.month&&day==d.day;
    
    }


    

    bool operator <(const Date& d)
    {
        if(year==d.year)
        {
            if(month==d.month)
            {
                if(day<d.day)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else if(month<d.month)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else if(year<d.year)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool operator <=(const Date& d)
    {/*
        if(year==d.year)
        {
            if(month==d.month)
            {
                if(day<=d.day)
                {
                    return true;
                }
            }
            else if(month<d.month)

            {
                return true;
            }
        }
        else if(year<d.year)
        {
            return true;
        }
        else
        {
            return false;
        }*/
       if(*this<d||*this==d)
       {
        return true;
       }
       else
       {
        return false;
       }
    }

    bool operator >(const Date& d)
    {
       /* if(year==d.year)
        {
            if(month==d.month)
            {
                if(day>d.day)
                return true;
            }
            else if(month>d.month)
            {
                return true;
            }
        }
        else if(year>d.year)
        {
            return true;
        }
        else
        {
            return false;
        }*/
       return !(*this<=d);
        
    }
     bool operator >=(const Date& d)

     {
        /* if(year==d.year)
        {
            if(month==d.month)
            {
                if(day>d.day)
                return true;
            }
            else if(month>d.month)
            {
                return true;
            }
        }
        else if(year>d.year)
        {
            return true;
        }
        else
        {
            return false;
        }
     }//操作符重载
        */
        return !(*this<d);
    }

    bool operator !=(const Date& d)

    {
        return !(*this==d);
    }

    Date operator+(const int& day)
    {
        Date ret=*this;
        ret.day+=day;
        while(ret.day>Getmonth(ret.year,ret.month))
        {
            ret.day-=Getmonth(ret.year,ret.month);
            ret.month++;
            if(ret.month==13)
            {
                ret.year++;
                ret.month=1;
            }
        }
        return ret;
    }

    Date& operator+=(const int& day)
    {
        this->day+=day;
        while(this->day>Getmonth(this->year,this->month))
        {
            this->day-=Getmonth(this->year,this->month);
            this->month++;
            if(this->month==13)
            {
                this->year++;
                this->month=1;
            }
        }
        return *this;
    }

   
   /* int DateSub(Date& d2)
    {
        int d=0;
        int count =0;
        while(*this!=d2)
        {
            if(*this>d2)
            {
                d2.day++;
                count++;
                if(d2.day>Getmonth(d2.year,d2.month))
                {
                    d2.month++;
    
                }
                if(d2.month==13)
                {
                    d2.year++;
                    d2.month=1;
                }
            }
            else if(*this<d2)
            {
                Date d1=*this;
                 d1.day++;
                count++;
                if(d1.day>Getmonth(d1.year,d1.month))
                {
                    d1.month++;
    
                }
                if(d1.month==13)
                {
                    d1.year++;
                    d1.month=1;
                }
            }
                
        }
        cout<<"相差的天数为："<<count<<endl;
        

     return count;   
        
    }想复杂了*/
   // ...existing code...
   
int DaysBetween(const Date& other) const
{
    Date d1 = *this;
    Date d2 = other;
    int count = 0;
    // 保证 d1 <= d2
    if (d1 > d2) {
        swap(d1, d2);
    }
    while (d1 != d2) {
        d1 += 1;
        count++;
    }
    return count;
}
// qisil....


    private:
    int year;
    int month;
    int day;
    

};

int main()
{
    Date s1(2025,7,20);
    Date s2(2028,12,21);
    int days = s1.DaysBetween(s2);
    cout << "Days between: " << days << endl;

   

  
    return 0;
}