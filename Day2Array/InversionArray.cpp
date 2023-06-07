// https://www.codingninjas.com/codestudio/problems/count-inversions_615?leftPanelTab=1

#include <bits/stdc++.h>
#define ll long long

void merge(ll *arr,ll low,ll mid,ll high,ll &ans){
    ll fIdx = mid-low+1;
    ll sIdx = high-mid;

    ll *first=new ll[fIdx],*second=new ll[sIdx];

    for(ll i=0;i<fIdx;i++){
        first[i]=arr[low+i];
    }
    for(ll i=0;i<sIdx;i++){
        second[i]=arr[mid+i+1];
    }

    ll arrIdx = low, fArr{}, sArr{};

    while(fArr<fIdx && sArr<sIdx){
        if(first[fArr]<second[sArr]){
            arr[arrIdx]=first[fArr];
            fArr++;
        }else{
            arr[arrIdx]=second[sArr];
            ans+=fIdx-fArr;
            sArr++;

        }
        arrIdx++;
    }

    while(fArr<fIdx){
        arr[arrIdx++]=first[fArr++];
    }

    while(sIdx<sIdx){
        arr[arrIdx++]=second[sArr++];
    }

    delete []first;
    delete []second;

}

void mergeSort(ll *arr,ll low,ll high,ll &ans){
    if(low>=high)return;

    ll mid = (high-low)>>1;
    mid+=low;

    mergeSort(arr,low,mid,ans);
    mergeSort(arr,mid+1,high,ans);
    merge(arr,low,mid,high,ans);
}

long long getInversions(long long *arr, int n){
    // Write your code here.
    ll ans {};

    ll low {},high(n-1);

    mergeSort(arr,low,high,ans);

    return ans;
}