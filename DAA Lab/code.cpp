#include<bits/stdc++.h>
using namespace std;
int countBad(int arrive[],int exit[], int len)
{
    int finalCount = 0;
    // int ind = *(&arrive + 1) - arrive - 1;
    // int ind1 = ind;
    int ind  = len-1;
    int ind1 = ind;
    while(ind >=0)
    {
       
        if(arrive[ind] == -1)
        {
            ind--;
        }
        else if(exit[ind1] == -1)
        {
            ind1--;
        }
        else if(arrive[ind] == exit[ind1])
        {
            ind1--;
            ind--;
        }
        else{
            for (int i =0;i<len;i++)
            {
                if(exit[i] == arrive[ind])
                {
                    exit[i] = -1;
                    arrive[ind] = -1;
                }
            }
            finalCount++;
            ind--;
        }
    }
    return finalCount;
}
int main()
{
    int arr[5] = {1,2};
    int arr1[5]= {1,2};
    cout<<countBad(arr,arr1,2);
    return 0;
}