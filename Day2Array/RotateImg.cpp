// https://leetcode.com/problems/rotate-image/description/

class Solution {
    void solve(vector<vector<int>>&matrix,int &i,int &k,int &n){
        for(int j=0;j<k;j++){
            int t=matrix[i][i+j];
            matrix[i][i+j]=matrix[n-i-1-j][i];
            matrix[n-i-1-j][i]=matrix[n-i-1][n-i-1-j];
            matrix[n-i-1][n-i-1-j]=matrix[i+j][n-i-1];
            matrix[i+j][n-i-1]=t;
        }
    }
public:
    void rotate(vector<vector<int>>& matrix) {
        int i{},n(matrix.size()),k(n-1);

        while(k>0){
            solve(matrix,i,k,n);
            i++;
            k-=2;
        }
    }
};