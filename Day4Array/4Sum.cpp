// https://leetcode.com/problems/4sum/description/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                int l=j+1,r=n-1;
                while(l<r){
                 long long preSum=nums[i];
                 preSum += nums[j];
                 long long rem = target-preSum;
                 if(rem>nums[l]+nums[r])l++;
                 else if(rem<nums[l]+nums[r])r--;
                 else{
                     vector<int>temp;
                     temp.push_back(nums[i]);
                     temp.push_back(nums[j]);
                     temp.push_back(nums[l]);
                     temp.push_back(nums[r]);
                     ans.push_back(temp);
                     while(l+1<r && nums[l]==nums[l+1])l++;
                     while(l+1<r && nums[r-1]==nums[r])r--;
                     l++,r--;
                 }
                }
                while(j<n-2 && nums[j]==nums[j+1])j++;
            }
            while(i<n-3 && nums[i]==nums[i+1])i++;
        }
        return ans;
    }
};