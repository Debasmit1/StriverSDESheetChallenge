// https://leetcode.com/problems/majority-element-ii/description/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int k=nums.size()/3;
        unordered_map<int,int>mpp;
        vector<int>ans;
        bool flag=0;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
            if(mpp[nums[i]]>k){
                if(!flag){
                    flag=1;
                    ans.push_back(nums[i]);
                }else{
                    if(ans.size()==1 && ans[0]!=nums[i]){
                        ans.push_back(nums[i]);
                    }
                }
            }
        }

        return ans;
    }
};