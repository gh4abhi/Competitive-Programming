// Problem Link - https://www.codingninjas.com/codestudio/problems/799352?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

bool isPalindrome(LinkedListNode<int> *head) {
        if(head==nullptr or head->next==nullptr)
            return true;
        LinkedListNode<int> * fast = head;
        LinkedListNode<int> * slow = head;
        while(fast->next and fast->next->next)
            fast = fast->next->next, slow = slow->next;
        LinkedListNode<int> * temp = slow->next;
        LinkedListNode<int> * pre = nullptr;
        while(temp)
        {
            LinkedListNode<int> * nex = temp->next;
            temp->next = pre;
            pre = temp;
            temp = nex;
        }
        slow->next = pre;
        LinkedListNode<int> * op = head;
        slow = slow->next;
        LinkedListNode<int> * first = head;
        while(slow)
        {
            if(slow->data!=first->data)
                return false;
            slow = slow->next;
            first = first->next;
        }
        return true;

}