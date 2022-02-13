// AUTHOR : SHIVAM DARGAN
// LANGAUGE : CPP
#include <bits/stdc++.h>
using namespace std;
string getString(int d){
    if(d==2)
    {
        return("abc");
    }
    if(d==3)
    {
        return("def");
    }
    if(d==4)
    {
        return("ghi");
    }
    if(d==5)
    {
        return("jkl");
    }
      if(d==6)
    {
        return("mno");
    }
      if(d==7)
    {
        return("pqrs");
    }
      if(d==8)
    {
        return("tuv");
    }
      if(d==9)
    {
        return("wxyz");
    }
    return"";

}

void print_key(int input, string output)
{
    if(input== 0)
    {
        cout<<output<<endl;
        return;
    }
    int smallerNumber = input/10;
    int lastDigit = input % 10;
    string optionForLastDigit = getString(lastDigit);
    for(int i=0;i<optionForLastDigit.length();i++)
    {
        print_key(smallerNumber,optionForLastDigit[i] + output );
    }

}
int main()
{
    int n;
    cin>>n;
    string output="";
    cout<<"_____OUTPUT COMBINATIONS ARE_____"<<endl;
    print_key(n,output);
    cout<<"_________________________________"<<endl;
    return 0;
}
