// AUTHOR : SHIVAM DARGAN
// LANGAUGE : CPP
#include <bits/stdc++.h>
using namespace std;
bool isSorted(int arr [], int size)
{
    if(size ==0 || size ==1)
    {
        return true;
    }
    if(arr[0]>arr[1])
    {
        return false;
    }
    return isSorted(arr+1,size-1);
}
int main()
{
    int a[5];
    for(int i =0;i<5;i++)
    {
        cin>>a[i];
    }
    if(isSorted(a,5))
    {
        cout<<"Array Is Sorted !"<<endl;
    }
    else
    {
        cout<<"Array Is nOt Sorted"<<endl;
    }
    return 0;
}
