// https://leetcode.com/problems/reverse-nodes-in-k-group/description/

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n(1);
        ListNode *cur=head;
        while(cur){
            cur=cur->next;
            n++;
        }
        ListNode *ans=NULL;
        cur=head;
        ListNode *prev=NULL,*nxt=NULL,*prevN=NULL;

        while(n>k){

            ListNode*temp=cur;
            for(int i=1;i<=k;i++){
                nxt=cur->next;
                cur->next=prev;
                prev=cur;
                cur=nxt;
            }
            if(!ans){
                ans=prev;
            }else{
            prevN->next=prev;
            }
            prevN=temp;
            temp->next=cur;
            prev=NULL;
            n-=k;
        }

        return ans;
    }
};