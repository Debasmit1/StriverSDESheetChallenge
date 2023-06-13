//https://leetcode.com/problems/linked-list-cycle/description/

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head || !head->next)return 0;

        ListNode *slow=head,*fast=head;

        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow == fast)return 1;
        }
        return 0;
    }
};