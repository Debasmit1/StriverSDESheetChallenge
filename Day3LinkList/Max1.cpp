// https://leetcode.com/problems/max-consecutive-ones/description/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt{},ans{};
        for(int i=0;i<nums.size();i++){
            if(nums[i]){
                cnt++;
                ans=max(ans,cnt);
            }else{
                cnt=0;
            }
        }
        return ans;
    }
};