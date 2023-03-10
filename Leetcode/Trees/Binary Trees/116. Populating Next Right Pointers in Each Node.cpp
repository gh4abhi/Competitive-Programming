// Problem Link - https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

#define ll long long
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root)
        {
            queue<Node*> pendingNodes,fNodes;
            pendingNodes.push(root);
            while(pendingNodes.size()!=0)
            {
                ll sz = pendingNodes.size();
                for(ll i=0;i<sz;i++)
                {
                Node* current = pendingNodes.front();
                pendingNodes.pop();
                    fNodes.push(current);
                    if(current->left)
                    {
                        pendingNodes.push(current->left);
                    }
                    if(current->right)
                    {
                        pendingNodes.push(current->right);
                    }
                }
                fNodes.push(nullptr);
            }
            while(fNodes.size()!=0)
            {
                Node* current = fNodes.front();
                fNodes.pop();
                if(fNodes.front()!=nullptr)
                {
                current->next = fNodes.front();
                }
                else
                {
                    current->next=nullptr;
                    fNodes.pop();
                }
            }
        }
        return root;
    }
};
