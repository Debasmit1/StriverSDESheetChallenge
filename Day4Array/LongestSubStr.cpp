// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

class Solution {
    int max(int x,int y){
        if(x>y)return x;
        else return y;
    }
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()<2)return s.size();

        unordered_set<int>stt;
        int l{},ans{};
        for(int i=0;i<s.size();i++){
            if(stt.find(s[i])!=stt.end()){
                ans=max(ans,i-l);
                while(s[l]!=s[i]){
                    stt.erase(s[l]);
                    l++;
                }
                stt.erase(s[l]);
                l++;
            }
                stt.insert(s[i]);
        }
        ans=max(ans,s.size()-l);
        return ans;
    }
};