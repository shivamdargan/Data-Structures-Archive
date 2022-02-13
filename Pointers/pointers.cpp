#include <bits/stdc++.h>
using namespace std;
int main()
{
    int p;
    cout<<"Enter Value"<<endl;
    cin>>p;
    int *ptr=&p;
    cout<<sizeof(ptr)<<sizeof(p)<<*ptr<<endl;
}