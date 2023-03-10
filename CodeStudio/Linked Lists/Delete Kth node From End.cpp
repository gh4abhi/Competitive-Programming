// Problem Link - https://www.codingninjas.com/codestudio/problems/799912?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h> 
#define ll int
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

LinkedListNode<int>* removeKthNode(LinkedListNode<int> *head, int k)
{
    if(head==nullptr)
        return head;
    if(k==0)
        return head;
    LinkedListNode<int>* first = head;
    while(k--)
        first = first->next;
    if(first==nullptr)
        return head->next;
    LinkedListNode<int>* second = head;
    while(first->next)
    {
        first = first->next;
        second = second->next;
    }
    second->next = second->next->next;
    return head;
}