// https://leetcode.com/problems/powx-n/

class Solution {
    #define ll long long
public:
    double myPow(double x, int n) {
        ll nn=0;
        if(n<0)nn=-1ll*n;
        else nn=n;
        double ans=1.0;
        while(nn){
            if(nn%2){
                ans*=x;
                nn--;
            }else{
                x*=x;
                nn>>=1;
            }
        }
        if(n<0)ans=double(1.0)/ans;
        return ans;
    }
};