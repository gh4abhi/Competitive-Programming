// Problem Link - https://www.codingninjas.com/codestudio/problems/920454?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h> 
#define ll int
/********************************

    Following is the class structure of the Node class:
    
    class Node
    {
        public:
            int data;
            Node *next;
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
    };

********************************/


Node *rotate(Node *head, int k) {
        if(head==nullptr or head->next==nullptr)
            return head;
        ll sz = 1;
        Node* temp = head;
        while(temp->next)
            sz++, temp = temp->next;
        temp->next = head;
        Node* newHead = head;
        k = k%sz;
        k = sz - k;
        Node* dummy = newHead;
        while(k--)
            dummy = newHead, newHead = newHead->next;
        dummy->next = nullptr;
        return newHead;
}