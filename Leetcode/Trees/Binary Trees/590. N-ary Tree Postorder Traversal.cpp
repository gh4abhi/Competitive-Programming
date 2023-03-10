//Problem Link - https://leetcode.com/problems/n-ary-tree-postorder-traversal/
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
    vector<int> postorder(Node* root) {
        vector<int> vect,v;
        if(root!=nullptr)
        {
            for(int i=0;i<root->children.size();i++)
            {
                v = postorder(root->children[i]);
                vect.insert(vect.end(),v.begin(),v.end());
            }
            vect.push_back(root->val);
        }
        return vect;
    }
};