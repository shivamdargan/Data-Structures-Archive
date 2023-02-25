// AUTHOR : SHIVAM DARGAN
// LANGAUGE : CPP
#include <bits/stdc++.h>
using namespace std;
 vector<int>sortColors(vector<int>& nums) {
        int count0=0,count1=0,count2=0;
        for(auto &val:nums){
            if(val == 0){
                count0 +=1;
            }
            else if(val ==1){
                count1+=1;
            }
            else{
                count2+=1;
            }
        }
        for(int i=0;i<count0;i++){
            nums[i]=0;
        }
        int ind=count0;
        for(int i=0;i<count1;i++){
            nums[ind]=1;
            ind++;
        }
        for(int i=0;i<count2;i++){
            nums[ind]=2;
            ind++;
        }
        return nums;
    }
int main()
{
	vector<int> vec= {2,0,2,1,1,0};
    vec = sortColors(vec);
    for(auto &val:vec){
        cout<<val<<endl;
    }
    return 0;
}
