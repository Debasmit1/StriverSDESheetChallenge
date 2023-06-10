class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {
        // Your code here
        unordered_map<long long,int>mpp;
        int ans{};
        mpp[0]=0;
        long long sum{};
        for(int i=0;i<A.size();i++){
            sum+=A[i];
            if(mpp.find(sum)!=mpp.end()){
               ans=max(ans,i-mpp[sum]+1);
            }else{
                mpp[sum]=i+1;
            }
        }
        return ans;
    }
};