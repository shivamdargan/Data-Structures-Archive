// AUTHOR : SHIVAM DARGAN
// LANGAUGE : CPP
#include <bits/stdc++.h>
using namespace std;
void print_subs(string input, string output)
{
    if(input.length() == 0)
    {
        cout<<output<<endl;
        return;
    }
    print_subs(input.substr(1),output);
    print_subs(input.substr(1),output + input[0]);
}
int main()
{
	string s;
    cin>>s;
    string output = "";
    print_subs(s,output);
    return 0;
}
