#include<iostream>
using namespace std;



class Sum {
  public:
    Sum() {
        sum += i;
        ++i;
    }
    static unsigned  int Getsum() {
        return sum;
    }
    static void Init() {
        sum = 0;
        i = 1;
    }


  private:
    static unsigned int sum;
    static unsigned int i;
};
unsigned int Sum::sum = 0;
unsigned int Sum::i = 1;





class Solution {
  public:
    int Sum_Solution(int n) {
        Sum::Init();
        Sum* p = new Sum[n];
        return Sum::Getsum();
    }
};
int main()
{
  Solution st;

  cout<<st.Sum_Solution(5)<<endl;
  return 0;
}