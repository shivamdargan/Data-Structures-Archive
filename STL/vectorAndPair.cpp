// AUTHOR : SHIVAM DARGAN
// LANGAUGE : CPP
#include <bits/stdc++.h>
using namespace std;
void PrintVec(vector<pair<int,string>> &vec)
{
    cout<<"Size Of Vector: "<<vec.size()<<endl;
    for(auto &value: vec)
    {
        cout<<value.first<<" "<<value.second<<endl;
    }
}
int main()
{
	vector<pair<int,string>> v_p;
    for(int i=0;i<5;i++)
    {
        pair <int,string> temp;
        cout<<"Enter First And Second Value Of The Pair"<<endl;
        cin>>temp.first>>temp.second;
        v_p.push_back(temp);
        cout<<"Size And Information Of Vector Is As Follows :"<<endl;
        PrintVec(v_p);
    }
            
    return 0;
}
