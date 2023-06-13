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

// Updated Version

class Solution {
    ListNode *findMid(ListNode *slow,ListNode *fast){
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
public:
    bool isPalindrome(ListNode* head) {
        ListNode*slow=head,*fast=head;
        ListNode *mid=findMid(slow,head);
        ListNode *h1=mid->next;
        ListNode *prev=NULL,*nxt=NULL,*cur=h1;
        while(cur){
            nxt=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nxt;
        }
        h1=prev;
        while(h1 && head){
            if(h1->val != head->val){
                return 0;
            }
            h1=h1->next;
            head=head->next;
        }
        return 1;
    }
};