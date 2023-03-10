// Problem Link - https://www.codingninjas.com/codestudio/problems/763406?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

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

Node *getListAfterReverseOperation(Node *head, int n, int b[]){
        Node* dummy = new Node(-1);
        dummy->next = head;
        Node* cur = dummy;
        Node* pre = dummy;
        Node* nex = dummy;
        ll count = 0;
        while(cur->next)
            count++,cur=cur->next;
        for(ll i=0;i<n;i++)
        {
            ll op = min(count-1,b[i]-1);
            if(op==0)
            {
                if(pre)
                    pre = pre->next;
                if(nex)
                    nex = nex->next;
                continue;
            }
            if(op<0)
                continue;
            cur = pre->next;
            nex = cur->next;
            while(op>0)
            {
                cur->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
                nex = cur->next;
                op--;
            }
            pre = cur;
            count = max(0,count-b[i]);
        }
        return dummy->next;
}