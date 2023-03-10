// Problem Link - https://leetcode.com/problems/maximum-depth-of-n-ary-tree/

#define ll int

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    ll DFS(Node* root)
    {
        if(root==nullptr)
            return 0;
        if(root->children.size()==0)
            return 1;
        ll cur = 0;
        for(auto j:root->children)
            cur = max(cur,DFS(j));
        return 1+cur;
    }
    int maxDepth(Node* root) {
        return DFS(root);
    }
};