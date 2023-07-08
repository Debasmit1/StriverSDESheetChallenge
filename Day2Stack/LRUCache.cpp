// https://leetcode.com/problems/lru-cache/submissions/

class LRUCache
{
    int cnt;
    class Node
    {
    public:
        int key;
        int val;
        Node *prev;
        Node *next;
        Node(int key, int val)
        {
            this->key = key;
            this->val = val;
        }
    };

    unordered_map<int, Node *> mpp;
    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);

    void addNode(Node *newNode)
    {
        Node *temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }

    void deleteNode(Node *delNode)
    {
        Node *delPrev = delNode->prev;
        Node *delNext = delNode->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
    }

public:
    LRUCache(int capacity)
    {
        cnt = capacity;
        head->next = tail;
        tail->prev = head;
    }

    int get(int key)
    {
        if (mpp.find(key) != mpp.end())
        {
            Node *resNode = mpp[key];
            int res = resNode->val;
            deleteNode(resNode);
            addNode(new Node(key, res));
            mpp[key] = head->next;
            return res;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (mpp.find(key) != mpp.end())
        {
            Node *resNode = mpp[key];
            mpp.erase(key);
            deleteNode(resNode);
        }
        if (cnt == mpp.size())
        {
            mpp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new Node(key, value));
        mpp[key] = head->next;
    }
};