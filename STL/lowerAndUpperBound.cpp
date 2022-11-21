// AUTHOR : SHIVAM DARGAN
// LANGAUGE : CPP
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v(5);
    for(int i=0;i<5;i++){
        cin>>v[i];
    }
    cout<<"Enter The Number To Check For Lower Bound And Upper Bound"<<endl;
    int num;
    cin>>num;
    auto it1 = lower_bound(v.begin(),v.end(),num);
    auto it2 = upper_bound(v.begin(),v.end(),num);
    cout<<"The Lower Bound Is: "<<*it1<<endl;
    cout<<"The Upper Bound Is: "<<*it2;
    return 0;
}
