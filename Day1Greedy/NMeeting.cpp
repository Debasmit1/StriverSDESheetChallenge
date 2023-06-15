// https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

class Solution
{
    static bool cmp(pair<int,int>&a,pair<int,int>&b){
        return a.second<b.second;
    }
    public:
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>>vec;
        for(int i=0;i<n;i++){
            vec.push_back(make_pair(start[i],end[i]));
        }
        sort(vec.begin(),vec.end(),cmp);
        int ans(1);
        int endT=vec[0].second;
        for(int i=1;i<n;i++){
            if(vec[i].first>endT){
                ++ans;
                endT=vec[i].second;
            }
        }
        return ans;
    }
};