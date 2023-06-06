// https://leetcode.com/problems/find-the-duplicate-number/submissions/965416410/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int>stt;

        for(int i=0;i<nums.size();i++){
            if(stt.find(nums[i])!=stt.end()){
                return nums[i];
            }
            stt.insert(nums[i]);
        }
        return 0;
    }
};