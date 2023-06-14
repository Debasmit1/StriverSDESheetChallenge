// https://leetcode.com/problems/linked-list-cycle-ii/description/

// Brute Force

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next)return NULL;
        ListNode *cur=head;
        set<ListNode *>stt;
        stt.insert(cur);
        while(cur){
            cur=cur->next;
            if(stt.find(cur)!=stt.end()){
                return cur;
            }
            stt.insert(cur);
        }
        return NULL;
    }
};




// Optimal Solution

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next)return NULL;
        ListNode *slow=head,*fast=head,*cur=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                break;
            }
        }
        if(slow!=fast){
            return NULL;
        }
        while(cur != slow){
            cur=cur->next;
            slow=slow->next;
        }
        return cur;
    }
};