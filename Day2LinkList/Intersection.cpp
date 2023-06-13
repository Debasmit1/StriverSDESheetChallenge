// https://leetcode.com/problems/intersection-of-two-linked-lists/description/

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1(1),l2(1);
        ListNode *cur1=headA,*cur2=headB;
        while(cur1){
            cur1=cur1->next;
            l1++;
        }
        while(cur2){
            cur2=cur2->next;
            l2++;
        }

        cur1=headA,cur2=headB;
        while(l1>l2){
            cur1=cur1->next;
            l1--;
        }
        while(l2>l1){
            cur2=cur2->next;
            l2--;
        }
        while(cur1 && cur1!=cur2){
            cur1=cur1->next;
            cur2=cur2->next;
        }
        return cur1;
    }
};