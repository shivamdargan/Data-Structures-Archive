// AUTHOR : SHIVAM DARGAN
// LANGAUGE : CPP
#include <bits/stdc++.h>
using namespace std;

void PrintVec(vector<vector<int>> &vec)
{
    cout<<"Size Of Outer Vector: "<<vec.size() <<endl;
    for(auto &value: vec)
    {
        cout<<"Size Of Inner Vector: "<<value.size() <<endl;
        for(auto innerValue: value)
        {
            cout<<innerValue<<" ";
        }
        cout<<endl;
    }
}
int main()
{
	vector<vector<int>> vv;
    int N,n,num;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>>n;
        vector<int> temp;
        for(int j=0;j<n;j++)
        {
            cin>>num;
            temp.push_back(num);
        }
        vv.push_back(temp);
    }
    PrintVec(vv);
    return 0;
}
