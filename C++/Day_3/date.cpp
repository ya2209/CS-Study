#include <iostream>
using namespace std;
class Date
{
    friend ostream &operator<<(ostream &out, const Date &d);
    friend istream &operator>>(istream &in,const Date &d);
public:
    int Getmonth(const int &y, const int &m)
    {
        static int Month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (m == 2 && ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0))
        {
            return 29;
        }

        return Month[m];
    }

    Date(int y = 0, int m = 0, int d = 0)
        : year(y), month(m), day(d)
    {
        if (y >= 0 && m >= 1 && m <= 12 && d >= 1 && d <= Getmonth(y, m))
        {
        }
        else
        {
            cout << "ERROR" << endl;
        }

    } // 构造函数
    Date(const Date &d)
        : year(d.year), month(d.month), day(d.day)
    {

    } // 拷贝函数

    void Print()
    {
        cout << year << ":" << month << ":" << day << endl;
    }

    bool operator==(const Date &d)
    {
        return year == d.year && month == d.month && day == d.day;
    }

    bool operator<(const Date &d)
    {
        if (year == d.year)
        {
            if (month == d.month)
            {
                if (day < d.day)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else if (month < d.month)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else if (year < d.year)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool operator<=(const Date &d)
    {
        if (*this < d || *this == d)
        {
            return true;
        }
        else
        {
            return false;
        }
    } // 操作符重载

    bool operator>(const Date &d)
    {

        return !(*this <= d);
    }
    bool operator>=(const Date &d)

    {

        return !(*this < d);
    }

    bool operator!=(const Date &d)

    {
        return !(*this == d);
    }

   
    Date operator+(int day)
    {
        Date ret = *this;
        ret += day;
        return ret;
    }

    Date &operator+=(int day)
    {
        this->day += day;
        while (this->day > Getmonth(this->year, this->month))
        {
            this->day -= Getmonth(this->year, this->month);
            this->month++;
            if (this->month == 13)
            {
                this->year++;
                this->month = 1;
            }
        }
        return *this;
    }

    int DaysBetween(const Date &other) const
    {
        Date d1 = *this;
        Date d2 = other;
        int count = 0;
        // 保证 d1 <= d2
        if (d1 > d2)
        {
            swap(d1, d2);
        }
        while (d1 != d2)
        {
            d1 += 1;
            count++;
        }
        return count;
    }
    // qisil....

    Date &operator-=(int day)
    {
        this->day -= day;
        while (this->day <= 0)
        {
            this->month--;
            if (this->month == 0)
            {
                this->year--;
                this->month = 12;
                this->day += Getmonth(this->year, this->month);
            }
        }
        return *this;
    }

    Date operator-(int day)
    {
        Date d1(*this);
        d1 -= day;

        return d1;
    }

    Date operator--(int)
    {
        Date d = *this;
        *this -= 1;
        return d;
    }
    Date &operator--()
    {

        *this -= 1;
        return *this;
    }

    Date operator++(int)
    {
        Date d = *this;
        *this += 1;

        return d;
    }

    Date &operator++()
    {
        *this += 1;

        return *this;
    }

private:
    int year;
    int month;
    int day;
    
};

ostream &operator<<(ostream &out,const Date &d)
{
    out << d.year << ":" << d.month << ":" << d.day << endl;
    return out;
}

istream &operator>>(istream &in,const Date &d)
{
    in>>d.year>>d.month>>d.day;
    return in;
}

int main()
{
    Date s1(2025, 7, 20);
    Date s2(2028, 1, 1);
    int days = s1.DaysBetween(s2);
    s1 -= 20;
    s1.Print();
    s2--;
    s2.Print();

    cout << "Days between: " << days << endl;
    cout << s1 << s2;

    return 0;
}