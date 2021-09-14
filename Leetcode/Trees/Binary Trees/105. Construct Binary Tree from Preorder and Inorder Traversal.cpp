//Problem Link - https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

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
    TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, int inS, int inE, int prS, int prE)
    {
        if(inS>inE)
        {
            return nullptr;
        }
        int rootVal = preorder[prS];
        int rootIndex = -1;
        for(int i=inS;i<inE+1;i++)
        {
            if(rootVal==inorder[i])
            {
                rootIndex=i;
                break;
            }
        }
        int lprS = prS+1;
        int linS = inS;
        int linE = rootIndex-1;
        int lprE = lprS + linE - linS;
        int rinS = rootIndex+1;
        int rinE = inE;
        int rprE = prE;
        int rprS = rinS - rinE + rprE;
        
        TreeNode* root = new TreeNode(rootVal);
        root->left = buildTreeHelper(preorder, inorder, linS, linE, lprS, lprE); 
        root->right = buildTreeHelper(preorder, inorder, rinS, rinE, rprS, rprE);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTreeHelper(preorder, inorder, 0, inorder.size()-1, 0, preorder.size()-1);
    }
};
