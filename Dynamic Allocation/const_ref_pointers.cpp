// AUTHOR : SHIVAM DARGAN
// LANGAUGE : CPP
#include <bits/stdc++.h>
using namespace std;

void reference()
{
    	//constant reference from const int
    const int j=12;
    const int &k= j;
    // j++; NOT POSSIBLE

   //constant reference from a non constant int
   int i =12;
   const int &o=i;
   cout<<"Before Incrementing In The Same Category "<<o<<endl;
   i++;
   cout<<"Constant Reference From A Non constant Int : "<<o<<endl;

    //reference from const int
    int const j3=20;
   // int & j2 = j3; C++ Does Not Allow  binding 'const int' to reference of type 'int&' discards qualifiers
   // j2++; // PATH IS A READ ONLYT PATH AND NOT EDITABLE 
}

void pointers()
{
    int const i=10;
  //  int *p =&i; // DOES NOT ALLOW invalid conversion from 'const int*' to 'int*
    
    // Const Pointer To A Non Const Int
    int j=12;
    int const *p2 = &j;
    cout<<"Const Pointer : "<<*p2<<endl;
    j++;
    cout<<"Const Pointer : "<<*p2<<endl;
}


int main()
{
    reference();
    pointers();
    int j= 20;
    int i=10;
    //Three Different Constant Variables Combination 
    
    //CANT CHANGE VALUE
    int const * p = &i;
    p=&i; // POSSIBLE
    //(*p)++; // NOT POSSIBLE increment of read-only location '* p'

    //CANT CHANGE PATH
    int * const p2=&j;
    (*p2)++; //POSSIBLE
   // *p2 = &i; // CANT CHANGE PATH invalid conversion from 'int*' to 'int'

    // NOT POSSIBLE TO CHANGE BOTH PATH AND VALUE
    int const *const p3 = &i;
     //p3=&j; // NOT POSSIBLE assignment of read-only variable 'p3'
    // (*p3)++; //NOT POSSIBLE increment of read-only location '*(const int*)p3'

    return 0;
}
