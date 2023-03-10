// Problem Link - https://www.codingninjas.com/codestudio/problems/873376?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h> 
#define ll int

/*************************************************************

    Following is the LinkedListNode class structure

    template <typename T>   
    class LinkedListNode
    {
        public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*************************************************************/

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
        unordered_map<LinkedListNode<int> *,LinkedListNode<int> *> m;
        LinkedListNode<int> *temp = head;
        while(temp)
        {
            LinkedListNode<int> *newNode = new LinkedListNode<int>(temp->data);
            m[temp] = newNode;
            temp = temp->next;
        }
        temp = head;
        while(temp)
        {
            if(temp->next)
                m[temp]->next = m[temp->next];
            else
                m[temp]->next = nullptr;
            if(temp->random)
                m[temp]->random = m[temp->random];
            else
                m[temp]->random = nullptr;
            temp = temp->next;
        }
        return m[head];
}
