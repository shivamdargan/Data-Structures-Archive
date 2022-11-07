// AUTHOR : SHIVAM DARGAN
// LANGAUGE : CPP
#include <bits/stdc++.h>
using namespace std;
vector<int> PrintVec(vector<int> &vec)
{
    for(auto &value: vec)
    {
        cout<<value<<endl;
    }
}
int main()
{
	vector <int> v;
    char ch;
    cout<<"Enter Choice y/n"<<endl;
    cin>>ch;
    int num;
    while(ch == 'y')
    {
        cout<<"Enter Number"<<endl;
        cin>>num;
        v.push_back(num);
        cout<<"The Vector Till Now Is:"<<endl;
        PrintVec(v);
        cout<<"Yes or No "<<endl;
        cin>>ch;
    }

    return 0;
}
