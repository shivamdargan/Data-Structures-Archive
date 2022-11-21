// AUTHOR : SHIVAM DARGAN
// LANGAUGE : CPP
#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b)
{
    return a<b;
}
int main()
{
	vector<int> vec(5);
    for(int i=0;i<5;++i)
    {   
        cin>>vec[i];
    }
    sort(vec.begin(),vec.end(),cmp);
    cout<<"******OUTPUT******"<<endl;
    for(int i=0;i<5;i++)
    {
        cout<<vec[i]<<endl;
    }

    return 0;
}
