// AUTHOR : SHIVAM DARGAN
// LANGAUGE : CPP
#include <bits/stdc++.h>
using namespace std;
 int maxSubArray(vector<int>& nums) {
        int maxSum=0,sum=0;
        bool isNegative = true;
        if(nums.size() == 1){
            return nums[0];
        }
        else
        {
                for(int i=0;i<nums.size();i++){
                    if(nums[i]>=0){
                        isNegative=false;
                    }
                    if(sum+nums[i]<0){
                        sum=0;
                    }
                    else{
                        sum+=nums[i];
                        if(sum>maxSum){
                            maxSum=sum;
                        }
                    }
            }
            if(isNegative){

                int max=nums[0];
                for(int i=1;i<nums.size();i++){
                    if(nums[i]>max){
                        max=nums[i];                    
                    }
                }
                return max;
            }
            else{
                return maxSum;

            }
        }
        
    }
int main()
{
    vector<int> vec = {-2,1,-3,4,-1,2,1,-5,4};
	cout<<maxSubArray(vec);
    return 0;
}
