// AUTHOR : SHIVAM DARGAN
// LANGAUGE : CPP
#include <bits/stdc++.h>
using namespace std;

int indexArray[100];

int index_recurr(int arr[],int n,int index,int sz,int hits)
{
    if(arr[index]==n)
    {
       indexArray[hits]= index;
       hits++;
        if(index == (sz-1))
        {
            return(hits);
        }

    }
    else if(index == (sz-1))
    {
        return(hits);
    }
    return index_recurr(arr,n,index+1,sz,hits);
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
    int hits = index_recurr(arr,n,0,sz,0);
	if(hits == 0)
    {
        cout<<"Element is Not Present in The Array"<<endl;
          cout<<"______________"<<"\n"<<"Total Occurences: "<<hits<<endl;
    }
    else
    {
        for(int i=0;i<hits;i++)

        {
            cout<<"Index of The Element is: "<<indexArray[i]<<endl;
        }
        cout<<"______________"<<"\n"<<"Total Occurences: "<<hits<<endl;
        
    }
    return 0;
}
