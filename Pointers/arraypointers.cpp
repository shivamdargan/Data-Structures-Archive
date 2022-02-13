#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[10];
    int* p = arr;
    cout<<"Enter Elements Of The Array"<<endl;
    for(int i=0;i<5;i++)
    {
        cin>>*(p+i);
    }
    cout<<sizeof(arr)<<endl;
    cout<<sizeof(p)<<endl;
    cout<<"OUTPUT ARRAY"<<endl;
    for(int j=0; j<5 ;j++)
    {
        cout<<*(p+j)<<endl;
    }

    // FOR CHARACTER ARRAYS , THE CHARACTER POINTER TO ARRAYS ALWAYS PRINTS THE CONTENT OF THE ARRAY IF THE POINTER'S VALUE IS ACCESSED !

    char carr[] = "hello friend ! ";
    char *parr = carr;
    cout<<carr<<endl;
    cout<<parr<<endl;

    return 0;
}