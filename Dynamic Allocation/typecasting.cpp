// AUTHOR : SHIVAM DARGAN
// LANGAUGE : CPP
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int i=65;
    int*p=&i;
    char *pc = (char *)p;               //Expilict TypeCasting
    cout<<i<<endl<<*p<<endl<<*pc<<"\n\n"<<p<<endl<<pc<<endl;
    return 0;
}
