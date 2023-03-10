// Problem Link - https://www.codingninjas.com/codestudio/problems/628974?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

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

bool detectCycle(Node *head)
{
    Node* fast = head;
    Node* slow = head;
    while(fast->next and fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        if(slow==fast)
            return true;
    }
    return false;
}