// https://leetcode.com/problems/palindrome-linked-list/description/

class Solution {
    bool check(vector<int>&vals){
        int i{},j(vals.size()-1);

        while(i<j){
            if(vals[i]!=vals[j]){
                return 0;
            }
            i++;j--;
        }

        return 1;
    }
public:
    bool isPalindrome(ListNode* head) {
        vector<int>vals;
        while(head){
            vals.push_back(head->val);
            head=head->next;
        }
        return check(vals);
    }
};