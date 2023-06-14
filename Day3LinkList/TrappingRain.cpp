// https://leetcode.com/problems/trapping-rain-water/description/

class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()<3)return 0;
        int n=height.size();
        vector<int>pre(n),suc(n);

        pre[0]=height[0];

        for(int i=1;i<n;i++){
            pre[i]=max(pre[i-1],height[i]);
        }

        suc[n-1]=height[n-1];

        for(int i=n-2;i>0;i--){
            suc[i]=max(suc[i+1],height[i]);
        }

        int ans{};

        for(int i=1;i<n-1;i++){
            ans+=min(pre[i],suc[i])-height[i];
        }

        return ans;
    }
};