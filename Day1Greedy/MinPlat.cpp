// https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#

class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	sort(arr,arr+n);
    	sort(dep,dep+n);

    	int maxS{},needS(1);
    	int i{},j{};

    	while(i<n){
    	    if(arr[i]>dep[j]){
    	        j++;
    	        needS=max(needS,maxS);
    	        maxS--;
    	    }else if(maxS==0 || arr[i]<=dep[j]){
    	        i++;
    	        maxS++;
    	    }
    	}
    	return needS;

    }
};
