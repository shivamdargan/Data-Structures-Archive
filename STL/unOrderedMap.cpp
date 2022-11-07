// AUTHOR : SHIVAM DARGAN
// LANGAUGE : CPP
#include <bits/stdc++.h>
using namespace std;
void takeInput(unordered_map<int,int> &m1)
{
    int key;
    cin>>key;
    m1[key] = m1[key] + 1;
}
void printMap(unordered_map<int,int> &m1)
{
    cout<<"*******************"<<endl;
    for(auto &ele:m1)
    {
        cout<<ele.first<<" "<<ele.second<<endl;
    }
    cout<<"*******************"<<endl;
}
int main()
{
	unordered_map<int,int> m1;
    cout<<"Enter The Amount Of Numbers You Want To Enter"<<endl;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        takeInput(m1);
    }
    printMap(m1);

    // Finding A VALUE in The Map
    int key;
    cout<<"Enter The Key For Which You Want To Find The Value For?"<<endl;
    cin>>key;
    auto it = m1.find(key);
    if(it != m1.end())
    {
        cout<<"The Value For The Given Key Is : "<<(*it).second<<endl;
    }
    else{
        cout<<"No Such Value Exists For The Given Key :("<<endl;
    }
    return 0;
}
