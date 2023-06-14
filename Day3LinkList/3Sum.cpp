// https://leetcode.com/problems/3sum/description/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>>stt;
        sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size()-2;i++){
            int j=i+1,k=nums.size()-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum>0){
                    k--;
                }else if(sum<0){
                    j++;
                }else{
                    vector<int>temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);
                    stt.insert(temp);
                    while(j<k && nums[j]==nums[j+1])j++;
                    while(j<k && nums[k-1]==nums[k])k--;
                    j++,k--;
                }
            }
            while(i<nums.size()-2 && nums[i]==nums[i+1])i++;
        }
        vector<vector<int>>ans;
        for(auto it:stt){
            ans.push_back(it);
        }
        return ans;
    }
};