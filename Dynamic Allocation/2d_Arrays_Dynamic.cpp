// AUTHOR : SHIVAM DARGAN
// LANGAUGE : CPP
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int row,col;
    cout<<"Enter The Rows Of 2-d matrix"<<endl;
    cin>>row;
    cout<<"Enter The Columns Of 2-D Matrix"<<endl;
    cin>>col;
    int **arr =new int*[row];    
    cout<<"Enter The Elements Of The array"<<endl;
    for(int i=0;i<row;i++)
    {
        arr[i] = new int[i];
        for(int j=0;j<col;j++)
        {
            cin>>arr[i][j];
        }
    }

    cout<<"Entered Array Is: "<<endl;
    for (int i = 0; i < row; i++)
    {
        cout<<endl;
        for (int j = 0; j < col; j++)
        {
            cout<<arr[i][j]<<" ";    
        }
    
    }

    //Deallocating Memory 

    for(int i=0;i<row;i++)
    {
        delete [] arr[i];
    }    
    delete [] arr;


    return 0;
}
