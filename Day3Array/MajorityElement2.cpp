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

// Updated Solution

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        int e1(INT_MIN),e2(INT_MAX),cnt1{},cnt2{};

        for(int i=0;i<nums.size();i++){
            if(cnt1==0 && nums[i]!=e2){
                e1=nums[i];
                cnt1++;
            }else if(cnt2==0 && nums[i]!=e1){
                e2=nums[i];
                cnt2++;
            }else if(nums[i]==e1){
                cnt1++;
            }else if(nums[i]==e2){
                cnt2++;
            }else{
                cnt1--;
                cnt2--;
            }
        }
        cout<<e1<<' '<<e2;

        cnt1=0,cnt2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==e1)cnt1++;
            else if(nums[i]==e2)cnt2++;
        }
        int k=nums.size()/3;
        vector<int>ans;
        if(cnt1>k)ans.push_back(e1);
        if(cnt2>k)ans.push_back(e2);

        return ans;
    }
};