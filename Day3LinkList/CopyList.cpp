// https://leetcode.com/problems/copy-list-with-random-pointer/description/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*,Node*>mp;

     Node* temp = head;

    while(temp != NULL)
    {

        Node* copy = new Node(temp->val);
        mp[temp] = copy;
        temp = temp->next;
    }

    temp = head;
    while(temp != NULL)

    {
        mp[temp]->next = mp[temp->next];
        mp[temp]->random = mp[temp->random];
        temp = temp->next;
    }

    return mp[head];
    }
};

// Updated Solution

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head )return head;
        Node *temp=head;
        while(temp){
            Node *copy=new Node(temp->val);
            copy->next=temp->next;
            temp->next=copy;
            temp=copy->next;
        }
        temp=head;
        while(temp){
            if(temp->random)
            temp->next->random=temp->random->next;
            temp=temp->next->next;
        }
        Node dmyNode(0);
        dmyNode.next=head->next;
        Node *oldNode=head,*newNode=head->next;
        while(oldNode){
            oldNode->next = newNode->next;
            if(newNode->next)newNode->next=newNode->next->next;
            oldNode=oldNode->next;
            newNode=newNode->next;
        }
        return dmyNode.next;
    }
};