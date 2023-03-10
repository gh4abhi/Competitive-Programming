// Problem Link - https://www.codingninjas.com/codestudio/problems/973250?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h> 
/****************************************************************

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

*****************************************************************/

Node *findMiddle(Node *head) {
    if(head==nullptr or head->next==nullptr)
        return head;
    Node* fast = head;
    Node* slow = head;
    while(fast and fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}