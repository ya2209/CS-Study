#include <iostream>
using namespace std;

int main()
{
    int year,month,day;
    int i=0;
    int n=0;
    
    while(cin>>year>>month>>day);
    { static int Month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
       
        for(i=0;i<month;++i)
        {
            n+=Month[i];

        }
        n+=day;
        if(month>2&&((year%4==0&&year%100!=0)||(year%400==0)))
        {
            n+=1;
        }
        cout<<n<<endl;

    }
return 0;
}