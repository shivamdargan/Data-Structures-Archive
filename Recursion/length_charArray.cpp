// AUTHOR : SHIVAM DARGAN
// LANGAUGE : CPP
#include <bits/stdc++.h>
int lenCharArray(char arr[],int len = 0)
{
    if(arr[0] == '\0')
    {
        return len;
    }
    lenCharArray(arr+1,len+1);

}
using namespace std;
int main()
{
    cout<<"Enter Character Array"<<endl;
    char arr[200];
    cin.getline(arr,sizeof(arr));
    int len=lenCharArray(arr);
    cout<<"Length Of The String is: "<<len<<endl;
    return 0;
}
