// https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len{};
        ListNode *cur=head;
        while(cur){
            cur=cur->next;
            len++;
        }
        len-=n;
        if(!len){
            return head->next;
        }
        cur=head;
        int i(1);
        while(i<len){
            cur=cur->next;
            i++;
        }
        cur->next=cur->next->next;
        return head;
    }
};