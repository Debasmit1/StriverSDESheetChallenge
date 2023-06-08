// https://leetcode.com/problems/reverse-pairs/description/

class Solution {
#define ll long long
    void merge(vector<int>&nums,int& low,int& mid,int& high,int &ans){
        int fSize=mid-low+1;
        int sSize=high-mid;
        int t=mid+1;

        for(int i=low;i<=mid;i++){
            while(t<=high && nums[i]>2ll*nums[t]){
                t++;
            }
            ans+=t-mid-1;
        }

        int *fArr=new int[fSize],
        *sArr=new int[sSize];

        for(int i=0;i<fSize;i++){
            fArr[i]=nums[low+i];
        }
        for(int i=0;i<sSize;i++){
            sArr[i]=nums[mid+i+1];
        }

        int fIdx{},sIdx{},arrIdx(low);
        while(fIdx<fSize && sIdx<sSize){
            if(fArr[fIdx]<sArr[sIdx]){
                nums[arrIdx]=fArr[fIdx++];
            }else{
                nums[arrIdx]=sArr[sIdx++];
            }
            arrIdx++;
        }
        while(fIdx<fSize){
            nums[arrIdx++]=fArr[fIdx++];
        }
        while(sIdx<sSize){
            nums[arrIdx++]=sArr[sIdx++];
        }

        delete []fArr;
        delete []sArr;
    }

    void mergeSort(vector<int>&nums,int low,int high,int &ans){
        if(low>=high)return;

        int mid=(high-low)>>1;
        mid+=low;

        mergeSort(nums,low,mid,ans);
        mergeSort(nums,mid+1,high,ans);
        merge(nums,low,mid,high,ans);
    }

public:
    int reversePairs(vector<int>& nums) {
        int low{},high(nums.size()-1);
        int ans{};
        mergeSort(nums,low,high,ans);
        return ans;
    }
};