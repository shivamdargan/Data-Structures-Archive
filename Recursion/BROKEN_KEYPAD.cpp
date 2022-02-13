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
string* keypad(int input)
{
     string *output = new string[100];
    if(input ==0 )
    {
        output[0] = "";
        return output;
    }
    int smallerNumber = input/10;
    cout<<smallerNumber<<endl;
    int lastDigit = input % 10;
    string *smallerOutput = new string [100];
     smallerOutput = keypad(smallerNumber);
    string optionForLastDigit = getString(lastDigit);
    int smallerOutputSize = (*smallerOutput).size();
    for(int i=0;i<smallerOutputSize;i++)
    {
        for(int j=0;j<optionForLastDigit.size();j++)
        {
            output[i+smallerOutputSize+j] = smallerOutput[i]+optionForLastDigit[j];
        }
    }
    cout<<*output<<endl;
    return(output);

}
int main()
{
	int s;
    cout<<"Enter Number"<<endl;
    cin>>s;
    string *out1 = new string[1000];
    out1 = keypad(s);
    cout<<"___________________"<<endl;
    cout<<"All Keypad Combinations Of The String Are As Follows :"<<endl;
    for(int i=0;i<9;i++)
    {
        cout<<out1[i]<<endl;
    }
    
    cout<<"__________________";
    delete [] out1;
    return 0;
}
