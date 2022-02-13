// AUTHOR : SHIVAM DARGAN
// LANGAUGE : CPP
#include <bits/stdc++.h>
using namespace std;

int* increment(int **p2)
{
    p2=p2+1;
    return *p2;
}
int * increment1(int **p2)
{
    *p2 = *p2+1;
    return *p2;
}
int * increment3(int **p2)
{
    **p2=**p2+1;
    return *p2;
}



int main()
{
    int i =10;
    int *p=&i;
    int **p2 = &p;

    // same values
    // cout<<i<<endl;
    // cout<<*p<<endl;
    // cout<<**p2<<endl;
	
    cout<<&i<<endl;
    cout<<p<<endl;
    cout<<*p2<<endl;

    cout<<increment(p2)<<endl;
    cout<<increment1(p2)<<endl;
    cout<<increment3(p2)<<endl;

    cout<<i;
    return 0;
}
