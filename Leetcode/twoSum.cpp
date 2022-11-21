// AUTHOR : SHIVAM DARGAN
// LANGAUGE : CPP
#include <bits/stdc++.h>
using namespace std;
vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[i] + nums[j] == target)
                {
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
        }
        
    }
int main()
{

    int n;
    cin>>n;
    vector<int> test(n);
    for(int i=0;i<n;i++)
    {
        cin>>test[i];
    }
    int target;
    cin>>target;
	vector<int> ans = twoSum(test,target);
    for(auto &ch:ans)
    {
        cout<<ch<<" ";
    }
    return 0;
}
