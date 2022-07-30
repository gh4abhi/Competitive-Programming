// Problem Link - https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1

#define ll int
/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;
    
    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }
    
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */

Node* merge(Node* l1, Node* l2)
{
    if(l1==nullptr)
        return l2;
    if(l2==nullptr)
        return l1;
    Node* dummy = new Node(-1);
    Node* temp = dummy;
    while(l1 and l2)
    {
        if(l1->data<=l2->data)
        {
            temp->bottom = l1;
            l1 = l1->bottom;
            temp = temp->bottom;
        }
        else
        {
            temp->bottom = l2;
            l2 = l2->bottom;
            temp = temp->bottom;
        }
    }
    
    if(l1)
    temp->bottom = l1;
    if(l2)
    temp->bottom = l2;
    return dummy->bottom;
}

Node *flatten(Node *root)
{
    if(root==nullptr or root->next==nullptr)
        return root;
    root->next = flatten(root->next);
    root = merge(root,root->next);
    return root;
}
