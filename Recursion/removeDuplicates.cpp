// AUTHOR : SHIVAM DARGAN
// LANGAUGE : CPP
#include <bits/stdc++.h>
using namespace std;
int removeDuplicates(char *str, char prev = '0')
{
    if(str[0] == '\0')
    {
        return 0;
    }
    if(str[0] == prev)
    {
        int i=1;
        for(;str[i]!='\0';i++)
        {
            str[i-1]=str[i];
        }
        str[i-1]=str[i];
   }
   removeDuplicates(str+1,str[0]);
}
int main()
{
	char str[100];
    cout<<"Enter String"<<endl;
    cin>>str;
     removeDuplicates(str);
    cout<<str<<endl;
    return 0;
}
