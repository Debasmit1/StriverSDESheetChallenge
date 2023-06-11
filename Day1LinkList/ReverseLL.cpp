// https://leetcode.com/problems/reverse-linked-list/description/

//Recursion

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next){
            return head;
        }

        ListNode *rest = reverseList(head->next);
        head->next->next=head;
        head->next=NULL;
        return rest;
    }
};

//Iterative

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next)return head;

        ListNode *prev=NULL,*cur=head,*nxt=NULL;
        while(cur){
            nxt = cur->next;
            cur->next=prev;
            prev=cur;
            cur=nxt;
        }
        return prev;
    }
};