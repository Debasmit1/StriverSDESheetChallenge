//https://leetcode.com/problems/merge-two-sorted-lists/description/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dmyPtr(0);
        ListNode *ptr=&dmyPtr;
        while(list1 && list2){
            if(list1->val<=list2->val){
                ptr->next=list1;
                list1=list1->next;
            }else{
                ptr->next=list2;
                list2=list2->next;
            }
            ptr=ptr->next;
        }

        if(list1)ptr->next=list1;
        else if(list2)ptr->next=list2;

        return dmyPtr.next;
    }
};