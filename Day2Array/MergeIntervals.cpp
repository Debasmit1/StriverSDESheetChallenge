// https://leetcode.com/problems/merge-intervals/submissions/965399768/

class Solution {
    static bool cmp(vector<int>&a,vector<int>&b){
        return a[0]<b[0];
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);

        vector<vector<int>>ans;

        ans.push_back({intervals[0][0],intervals[0][1]});
        int s=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(s>=intervals[i][0]){
                ans[ans.size()-1][1]=max(intervals[i][1],s);
                s=ans[ans.size()-1][1];
            }else{
                ans.push_back({intervals[i][0],intervals[i][1]});
                s=ans[ans.size()-1][1];
            }
        }

        return ans;
    }
};