// Problem Link - https://leetcode.com/problems/copy-list-with-random-pointer/

#define ll int

/*-
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==nullptr)
            return nullptr;
        Node* cur = head;
        while(cur)
        {
            Node* newNode = new Node(cur->val);
            newNode->next = cur->next;
            cur->next = newNode;
            cur = cur->next->next;
        }
        cur = head;
        while(cur)
        {
            if(cur->random)
                cur->next->random = cur->random->next;
            cur = cur->next->next;
        }
        cur = head;
        Node* nex = cur->next->next;
        Node* newHead = cur->next;
        while(nex)
        {
            cur->next->next = nex->next;
            cur->next = nex;
            cur = nex;
            nex = nex->next->next;
        }
        cur->next=nullptr;
        return newHead;
    }
};