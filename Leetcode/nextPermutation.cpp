// AUTHOR : SHIVAM DARGAN
// LANGAUGE : CPP
#include <bits/stdc++.h>
using namespace std;
void nextPermutation(vector<int>& nums) {
    int ind1,ind2,flag=0;
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                flag=1;
                ind1=i;
                break;
            }
        }
        if(!flag){
            sort(nums.begin(),nums.end());
            for(auto &val:nums){
                    cout<<val<<endl;
                }
            return;
        }
        else
        {
            for (int i = nums.size() - 1; i >= 0; i--)
            {
                if (nums[i] > nums[ind1])
                {
                    ind2 = i;
                    break;
                }
            }
            cout<<"val:  "<<ind1<<" "<<ind2<<endl; 
            swap(nums[ind1],nums[ind2]);
            reverse(nums.begin() + ind1 + 1,nums.end());
                for(auto &val:nums){
                    cout<<val<<endl;
                }
            return;
        }
    }
int main()
{
    vector<int> vec = {1,3,5,4,2};
	nextPermutation(vec);
    return 0;
}
