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

// Recursion

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *res;
        res=NULL;

        if(!list2){
            return list1;
        }else if(!list1){
            return list2;
        }

        if(list1->val<=list2->val){
            res=list1;
            res->next=mergeTwoLists(list1->next,list2);
        }else{
            res=list2;
            res->next=mergeTwoLists(list1,list2->next);
        }
        return res;
    }
};