//https://leetcode.com/problems/set-matrix-zeroes/description/

//1
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row(matrix.size()),col(matrix[0].size());
        int zCol=0;

        for(int i=0;i<row;i++){
            if(!matrix[i][0])
            zCol=1;

            for(int j=1;j<col;j++){
                if(!matrix[i][j]){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }

        for(int i=1;i<row;i++){
            for(int j=1;j<col;j++){
                if(!matrix[i][0] || !matrix[0][j]){
                    matrix[i][j]=0;
                }
            }
        }
        if(!matrix[0][0]){
            for(int j=1;j<col;j++){
                matrix[0][j]=0;
            }
        }

        if(zCol){
            for(int i=0;i<row;i++){
                matrix[i][0]=0;
            }
        }
    }
};