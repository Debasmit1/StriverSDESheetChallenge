// https://leetcode.com/problems/add-two-numbers/description/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dmyNode(0);
        ListNode *ptr=&dmyNode;

        int sum{},c{};
        while(l1 && l2){
            sum=l1->val+l2->val+c;
            ptr->next=new ListNode(sum%10);
            ptr=ptr->next;
            c=sum/10;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1){
            sum=l1->val+c;
            ptr->next=new ListNode(sum%10);
            ptr=ptr->next;
            c=sum/10;
            l1=l1->next;
        }
        while(l2){
            sum=l2->val+c;
            ptr->next=new ListNode(sum%10);
            ptr=ptr->next;
            c=sum/10;
            l2=l2->next;
        }
        if(c){
            ptr->next=new ListNode(c);
        }
        return dmyNode.next;
    }
};