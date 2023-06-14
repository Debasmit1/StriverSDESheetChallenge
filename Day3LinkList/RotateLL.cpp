// https://leetcode.com/problems/rotate-list/description/

class Solution {
    ListNode *findTail(ListNode *head){
        ListNode *cur=head;

        while(cur->next->next){
            cur=cur->next;
        }

        return cur;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next)return head;

        int cnt(1);
        ListNode *cur=head;
        while(cur->next){
            cur=cur->next;
            cnt++;
        }
        k = k%cnt;

        for(int i=1;i<=k;i++){
            ListNode *prevTail = findTail(head);
            prevTail->next->next=head;
            head=prevTail->next;
            prevTail->next=NULL;
        }

        return head;
    }
};