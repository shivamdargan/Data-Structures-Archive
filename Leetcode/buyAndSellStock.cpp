// AUTHOR : SHIVAM DARGAN
// LANGAUGE : CPP
#include <bits/stdc++.h>
using namespace std;
int maxProfit(vector<int>& prices) {
    int lsf =  INT_MAX;
    int op = 0;
    int pist; //profit if sold today
    for(auto &day:prices)
    {
        if(day<lsf)
        {   
            lsf = day;
        }
        pist = day-lsf;
        if(pist>op)
        {
            op = pist;
        }

    }
    return op;
}

int main()
{
    int n;
    cin>>n;
    vector<int> prices(n);
    for(int i=0;i<n;i++)
    {
        cin>>prices[i];
    }
    int value = maxProfit(prices);
    cout<<value;
    return 0;
}
