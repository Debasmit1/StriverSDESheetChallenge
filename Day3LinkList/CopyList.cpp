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