// Problem Link - https://leetcode.com/problems/n-ary-tree-level-order-traversal/

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
    
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> pendingNodes;
        pendingNodes.push(root);
        Node* dummy = new Node(-1);
        pendingNodes.push(dummy);
        vector<vector<ll>> ans;
        vector<ll> vect;
        if(root==nullptr)
            return ans;
        while(pendingNodes.size())
        {
          Node* cur = pendingNodes.front();
          pendingNodes.pop();
          if(cur->val==-1)
          {
              if(pendingNodes.size()>0)
                  pendingNodes.push(dummy);
              ans.push_back(vect);
              vect.clear();
                continue;
          }
            vect.push_back(cur->val);
            for(auto i:cur->children)
                pendingNodes.push(i);
        }
        return ans;
    }
};