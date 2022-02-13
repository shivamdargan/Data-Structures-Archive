// AUTHOR : SHIVAM DARGAN
// LANGAUGE : CPP
#include <bits/stdc++.h>
using namespace std;

int sum (int *a, int size){
    int ans=0;
    for(int i=0;i<size;i++){
        ans = ans + *(a+i);
    }
    return ans;
}

int main()
{
	int arr[10];
    for(int i=0;i<5;i++)
    {
        cin>>arr[i];
    }
    cout<<sum(arr, 5);
    return 0;
}


 