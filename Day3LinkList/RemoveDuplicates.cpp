//https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left{},right(1);
        int size(nums.size());

        while(right<size){
            if(nums[left]<nums[right]){
                left++;
                nums[left]=nums[right];
            }
            right++;
        }
        return ++left;
    }
};