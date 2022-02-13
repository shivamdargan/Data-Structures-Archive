// AUTHOR : SHIVAM DARGAN
// LANGAUGE : CPP
#include <bits/stdc++.h>
using namespace std;
int index_recurr(int arr[],int n,int index,int sz)
{
    if(arr[index]==n)
    {
        return index;
    }
    else if(index == 0)
    {
        return -1;
    }
    return index_recurr(arr,n,index-1,sz);
}
int main()
{
    cout<<"Enter Size Of The Array"<<endl;
    int sz;
    cin>>sz;
    int *arr = new int [sz];
    cout<<"Enter The Array"<<endl;
    for(int i=0;i<sz;i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter Element To Search"<<endl;
    int n;
    cin>>n;
    int index = index_recurr(arr,n,sz-1,sz);
	if(index == -1)
    {
        cout<<"Element is Not Present in The Array"<<endl;
    }
    else
    {
        cout<<"Last Index of The Element is: "<<index<<endl;
    }
    delete [] arr;
    return 0;
}
