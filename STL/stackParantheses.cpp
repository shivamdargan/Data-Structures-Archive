// AUTHOR : SHIVAM DARGAN
// LANGAUGE : CPP
#include <bits/stdc++.h>
using namespace std;

vector<int> NGE(vector<int> nge, int size)
{
    vector<int> NGEResult(size);
    stack<int> st;
    for(int i=0;i<size;++i)
    {
        while(!st.empty() && nge[i]>nge[st.top()])
        {
            NGEResult[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty())
    {
        NGEResult[st.top()] = -1;
        st.pop();
    }
    return NGEResult;
}
int main()
{
	cout<<"Enter The Length Of The Vector"<<endl;
    int n;
    cin>>n;
    vector<int> ngeArray(n);
    for(int i=0;i<n;++i)
    {
      cin>>ngeArray[i];
    }
    vector<int> NGEResult = NGE(ngeArray,n);
    cout<<"The Next Greater Elements Of The Given Array Are As Follows : "<<endl;
    for(int i=0;i<n;++i)
    {
        cout<<ngeArray[i]<<" "<<(NGEResult[i] == - 1 ? -1 : ngeArray[NGEResult[i]])<<endl;
    }
    return 0;
}
