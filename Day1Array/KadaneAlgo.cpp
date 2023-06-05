// https://leetcode.com/problems/maximum-subarray/description/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans(-1e4-1),sum{};
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            ans=max(ans,sum);
            if(sum<0)sum=0;
        }
        return ans;
    }
};