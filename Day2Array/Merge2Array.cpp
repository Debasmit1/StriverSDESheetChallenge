// https://leetcode.com/problems/merge-sorted-array/description/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i{},j{},k(m-1);

        while(i<=k && j<n){
            if(nums1[i]>=nums2[j]){
                swap(nums1[k--],nums2[j++]);
            }else{
                i++;
            }
        }

        sort(nums1.begin(),nums1.begin()+m);
        sort(nums2.begin(),nums2.end());

        for(int i=0;i<n;i++){
            nums1[m+i]=nums2[i];
        }
    }
};