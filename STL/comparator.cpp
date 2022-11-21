// AUTHOR : SHIVAM DARGAN
// LANGAUGE : CPP
#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b)
{
    if(a.first != b.first){
        return a.first<b.first;
    }
    else{
        return a.second>b.second;
    }
}
int main()
{
	vector<pair<int,int>> vec(5);
    for(int i=0;i<5;++i)
    {   
        cin>>vec[i].first>>vec[i].second;
    }
    sort(vec.begin(),vec.end(),cmp);
    cout<<"******OUTPUT******"<<endl;
    for(int i=0;i<5;i++)
    {
        cout<<vec[i].first<<" "<<vec[i].second<<endl;
    }

    return 0;
}
