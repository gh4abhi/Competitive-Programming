// Problem Link - https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

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
    TreeNode* buildTreeHelper(vector<int>& inorder, vector<int>& postorder, int poS, int poE, int inS, int inE)
    {
        if(inS>inE)
        {
            return nullptr;
        }
        int rootVal = postorder[poE];
        int rootIndex = -1;
        for(int i=inS;i<=inE;i++)
        {
            if(inorder[i]==rootVal)
            {
                rootIndex = i;
                break;
            }
        }
        
        int lpoS = poS;
        int linS = inS;
        int linE = rootIndex-1;
        int lpoE = linE-linS+lpoS;
        int rpoE = poE-1;
        int rinS = rootIndex+1;
        int rinE = inE;
        int rpoS = rinS-rinE+rpoE;
        
        TreeNode*root = new TreeNode(rootVal);
        
        root->left = buildTreeHelper(inorder, postorder, lpoS, lpoE, linS, linE);
        root->right = buildTreeHelper(inorder, postorder, rpoS, rpoE, rinS, rinE);
            
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTreeHelper(inorder, postorder, 0, postorder.size()-1, 0, inorder.size()-1);
    }
};
