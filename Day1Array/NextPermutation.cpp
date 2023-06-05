// https://leetcode.com/problems/next-permutation/solutions/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int idx(-1),i(nums.size()-1);
        while(i>0){
            if(nums[i]>nums[i-1]){
                idx=i-1;
                break;
            }
            i--;
        }
        if(idx==-1){
            reverse(nums.begin(),nums.end());
        }else{
            int j=nums.size()-1;
            while(nums[idx]>=nums[j]){
                j--;
            }
            swap(nums[idx],nums[j]);
            sort(nums.begin()+idx+1,nums.end());
        }
    }
};