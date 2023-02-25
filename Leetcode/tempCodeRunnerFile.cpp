// AUTHOR : SHIVAM DARGAN
// LANGAUGE : CPP
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascalTriangle;
        vector<int> row;
        for(int i=0;i<numRows;i++){
            if(i==0){
                pascalTriangle.push_back({1});
            }
            else if(i==1){
                pascalTriangle.push_back({1,1});
            }
            else
            {
                for(int j=0;j<=i;j++){
                    if(j==0){
                        row.push_back(1);
                    }
                    else if(j==i){
                        row.push_back(1);
                    }
                    else{
                        // cout<<"Value:"<<pascalTriangle[i-1][j-1]<<" "<<pascalTriangle[i-1][j];
                        int val = pascalTriangle[i-1][j-1] + pascalTriangle[i-1][j];
                        row.push_back(val);
                    }
                }
                pascalTriangle.push_back(row);
            }
        }
        return pascalTriangle;
}

int main()
{
    vector<vector<int>> out;
	out = generate(3);
    for(auto &vec:out){
        for(auto val:vec){
            cout<<val<<" ";
        }
        cout<<endl;
    }
    return 0;
}
