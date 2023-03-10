// Problem Link - https://www.codingninjas.com/codestudio/problems/630457?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

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

int findIntersection(Node *headA, Node *headB)
{
        if(headA==nullptr or headB==nullptr)
           return -1;
        Node* l1 = headA;
        Node* l2 = headB;
        while(l1!=l2)
        {
            if(l1==nullptr)
                l1 = headB;
            else
                l1 = l1->next;
            if(l2==nullptr)
                l2 = headA;
            else
                l2 = l2->next;
        }
        if(l2==nullptr)
            return -1;
        return l2->data;
}