// AUTHOR : SHIVAM DARGAN
// LANGAUGE : CPP
#include <bits/stdc++.h>
using namespace std;

void takeInput(map<pair<string,string>,vector<int>> &m1)
{
        string fn,ln;
        int ct,x;
        cin>>fn>>ln>>ct;
        vector<int> temp;
        for(int j=0;j<ct;j++)
        {
            cin>>x;
            temp.push_back(x);
        }
        m1[{fn,ln}] = temp;
}
void printOutput(map<pair<string,string>,vector<int>> &m1)
{
    cout<<"***********"<<endl;
    for(auto &pr:m1)
    {
        cout<<"First Name: "<<(pr.first).first<<endl;
        cout<<"Last Name: "<<(pr.first).second<<endl;
        cout<<"Marks In The Subjects Are As Follows:" <<endl;
        for(auto &vec:pr.second)
        {
            cout<<vec<<"  ";
        }
        cout<<endl;
    }
    cout<<"***********"<<endl;
}
int main()
{
    map<pair<string,string>,vector<int>> m1;
    int t;
    cin>>t;
    while(t!=0)
    {
        t--;
        takeInput(m1);

    }
    printOutput(m1);
    return 0;
}
