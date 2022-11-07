// AUTHOR : SHIVAM DARGAN
// LANGAUGE : CPP

// unordered_Set can be replaced by ordered_set To Make The Set Overall Set Ordered As Well 
//same follows for multiset to accept multiple duplicate values
#include <bits/stdc++.h>
using namespace std;
void printSet(unordered_set<int> &s1){
    cout<<"***********"<<endl;
    for(auto &value:s1)
    {
        cout<<value<<endl;
    }
    cout<<"***********"<<endl;
}
int main()
{
    unordered_set<int> s1;
    cout<<"Enter Number Of Elements"<<endl;
    int n;
    cin >>n;
    int num;
    for(int i=0;i<n;i++)
    {
        cin>>num;
        s1.insert(num);
    }
    printSet(s1);
    cout<<"Enter The Value To Be Deleted "<<endl;
    int val;
    cin>>val;
    auto it = s1.find(val);
    s1.erase(it);
    cout<<"The Set After Deleting The Value Is As Follows: "<<endl;
    printSet(s1);
    return 0;
}
