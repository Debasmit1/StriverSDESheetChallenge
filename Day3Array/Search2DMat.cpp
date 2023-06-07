// https://leetcode.com/problems/search-a-2d-matrix/solutions/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row(matrix.size()),col(matrix[0].size());
        for(int i=0;i<row;i++){
            if(matrix[i][col-1]<target)continue;
            else if(matrix[i][0]>target)break;
            int low=0,high=col-1;
            while(low<=high){
                int mid=(high-low)>>1;
                mid+=low;
                if(matrix[i][mid]==target)return 1;
                else if(matrix[i][mid]<target)low=mid+1;
                else high=mid-1;
            }
        }
        return 0;
    }
};