// Problem Link - https://leetcode.com/problems/binary-tree-paths/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<string> vect;
    string str;
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root)
        {
            str+=to_string(root->val);
            addToVect("","",str,root);
        }
        return vect;
    }
    void addToVect(string str1,string str2,string str, TreeNode* root)
    {
        str1 = str2 = str;
        if(root->left==nullptr and root->right == nullptr)
        {
            vect.push_back(str);
            return;
        }
        if(root->left!=nullptr)
        {
            str1 += "->"+to_string(root->left->val);
            addToVect("","",str1,root->left);
        }
         if(root->right!=nullptr)
        {
            str2 += "->"+to_string(root->right->val);
            addToVect("","",str2,root->right);
        }
    }
};
