// Problem Link - https://www.codingninjas.com/codestudio/problems/800332?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h> 
#define ll int
/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* l1, Node<int>* l2)
{
        if(l1==nullptr)
            return l2;
        if(l2==nullptr)
            return l1;
        if(l1->data>l2->data)
            swap(l1,l2);
        Node<ll>* head = l1;
        while(l1 and l2)
        {
            Node<ll>* temp  = l1;
            while(l1 and l1->data<=l2->data)
                temp = l1, l1 = l1->next;
            temp->next = l2;
            swap(l1,l2);
        }
        return head;
}
