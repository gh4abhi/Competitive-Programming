// Problem Link - https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* DFS(Node* head)
    {
        if(head==nullptr)
            return head;
        Node* temp = head;
        Node* dummy;
        while(temp)
        {
            dummy = temp;
            if(temp->child)
            {
                Node* tempNext = temp->next;
                temp->next = temp->child;
                temp->child = nullptr;
                temp->next->prev = temp;
                if(tempNext==nullptr)
                    return DFS(temp->next);
                else
                    tempNext->prev = DFS(temp->next), tempNext->prev->next = tempNext;
                temp = tempNext;
            }
            else
                temp = temp->next;
        }
        return dummy;
    }
    Node* flatten(Node* head) {
        if(head==nullptr)
            return head;
        DFS(head);
        return head;
    }
};