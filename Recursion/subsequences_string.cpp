// AUTHOR : SHIVAM DARGAN
// LANGAUGE : CPP
#include <bits/stdc++.h>
using namespace std;
int subsequence(string input, string output[])
{
   if(input.empty())
   {
       output[0]="";
       return 1;
   } 
   string smallString = input.substr(1);
   int smallOutputSize = subsequence(smallString, output);
   for(int i=0;i<smallOutputSize;i++)
   {
       output[i+smallOutputSize] = input[0] + output[i];
   }
   return 2*smallOutputSize;
}
int main()
{
	string s;
    cout<<"Enter String"<<endl;
    cin>>s;
    int size = s.size();
    cout<<size<<endl;
    size = pow(2,size);
    cout<<size<<endl;
    string *output = new string[size];
    int sequenceSize = subsequence(s, output);
    cout<<"___________________"<<endl;
    cout<<"All Subsequences Of The String Are As Follows :"<<endl;
    for(int i=0;i<sequenceSize;i++)
    {
        cout<<output[i]<<endl;
    }
    cout<<"__________________";
    return 0;
}
