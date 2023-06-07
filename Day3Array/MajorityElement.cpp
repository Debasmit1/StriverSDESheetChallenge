// https://leetcode.com/problems/majority-element/description/


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int k=nums.size()/2;
        unordered_map<int,int>mpp;

        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
            if(mpp[nums[i]]>k)return nums[i];
        }
        return 1;
    }
};

//Updated Solution

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt(1);
        int maxi=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]==maxi){
                cnt++;
            }else{
                cnt--;
                if(cnt<0){
                    cnt=1;
                     maxi=nums[i];
                }
            }
        }
        return maxi;
    }
};