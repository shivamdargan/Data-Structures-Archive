// AUTHOR : SHIVAM DARGAN
// LANGAUGE : CPP
#include <bits/stdc++.h>
using namespace std;

int fibonacci_recur(int no)
{
   if(no==0)
   {
       return 0;
   }
   if(no==1)
   {
       return 1;
   }
   return fibonacci_recur(no-1)+fibonacci_recur(no-2);
}
int main()
{
    int n;
    cin>>n;
	cout<<fibonacci_recur(n)<<endl;
    return 0;
}
