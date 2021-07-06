// Problem Statement - https://leetcode.com/problems/same-tree/

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool testLeft=0,testRight=0,curTest=0;
        if(p!=nullptr and q!=nullptr)
        {
            if(p->val == q->val)
            {
                curTest=1;
            }
            testLeft = isSameTree(p->left,q->left);
            testRight = isSameTree(p->right,q->right);
        }
        if(p==nullptr and q==nullptr)
        {
            curTest=1;
            testLeft=1;
            testRight = 1;
        }
        return curTest and testLeft and testRight;
    }
};
