// AUTHOR : SHIVAM DARGAN
// LANGAUGE : CPP
#include <bits/stdc++.h>
using namespace std;
bool isValid(string s) {
    stack<char> st;
    for(auto &ch:s)
    {
        if(ch == '{' || ch == '(' || ch == '[')
        {
            st.push(ch);
        }
        else
        {
            if(!st.empty() && ((st.top() == '{' && ch == '}') || (st.top() == '(' && ch == ')' ) || (st.top() == '[' && ch == ']')))
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
    }  
    if(st.empty())
    {
        return true;
    }      
    else
    {
        return false;
    }
}
int main()
{
	string m;
    cin>>m;
    bool value = isValid(m);
    cout<<value;
    return 0;
}
