// AUTHOR : SHIVAM DARGAN
// LANGAUGE : CPP
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter The Number Of Elements In the Array"<<endl;
    cin>>n;
	int *arr = new int[n];
    cout<<"Enter Elements In The Array"<<endl;
    for(int i =0;i<n;i++)
    {
        cin>>arr[i];
    }
    int max=-1;
    cout<<"Calculating Maximum Element In The Array...."<<endl;
    for(int i=0;i<n;i++)
    {
        if(max<arr[i])
        {
            max=arr[i];
        }
    }   
    cout<<"Maximum Element In The Array Is : "<<max<<endl;
    //Deallocating Memory To Avoid Memory Leaks
    delete [] arr;
    return 0;
}
