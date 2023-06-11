// https://www.interviewbit.com/problems/subarray-with-given-xor/

int Solution::solve(vector<int> &A, int B) {
    unordered_map<int,int>mpp;
    mpp[0]++;
    int ans{},xr{};
    for(int i=0;i<A.size();i++){
        xr=xr^A[i];
        int x=xr^B;
        ans+=mpp[x];
        mpp[xr]++;
    }
    return ans;
}
