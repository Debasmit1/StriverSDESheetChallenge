// https://leetcode.com/problems/longest-consecutive-sequence/description/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()<2)return nums.size();
        int ans(1);
        sort(nums.begin(),nums.end());
        int l{},h{},cnt{};
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                cnt++;
                h++;
            }
            else if(nums[i]+1==nums[i+1]){
                h++;
            }else{
                ans=max(ans,h-l+1-cnt);
                l=i+1;
                h=i+1;
                cnt=0;
            }
        }
        ans=max(ans,h-l+1-cnt);
        return ans;
    }
};