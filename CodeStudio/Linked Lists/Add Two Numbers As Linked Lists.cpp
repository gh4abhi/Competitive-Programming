// Problem Link - https://www.codingninjas.com/codestudio/problems/add-two-numbers-as-linked-lists_1170520?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h> 
#define ll int
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

Node *addTwoNumbers(Node *l1, Node *l2)
{
        Node* dummy = new Node(-1);
        Node* temp = dummy;
        ll carry = 0;
        ll sum = 0;
        while(l1 or l2 or carry)
        {
            sum = 0;
            if(l1)
                sum += l1->data, l1 = l1->next;
            if(l2)
                sum += l2->data, l2 = l2->next;
            sum += carry;
            carry = sum/10;
            Node* newNode = new Node(sum%10);
            temp->next = newNode;
            temp = newNode;
        }
        return dummy->next;
}