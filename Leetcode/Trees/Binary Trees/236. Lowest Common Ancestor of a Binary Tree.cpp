// Problem Link - https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    
    pair<TreeNode*, pair<bool,bool>> lowestCommonAncestorHelper(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        TreeNode* val = nullptr;
        TreeNode* lVal = nullptr;
        TreeNode* rVal = nullptr;
        bool node1L = false, node1R = false, node2L = false, node2R = false;

        pair<TreeNode*,pair<bool,bool>> l,r;
        bool rootNodeCheck1 = false, rootNodeCheck2 = false;

        if(root->val == p->val)
        {
            rootNodeCheck1 = true;
        }
        if(root->val == q->val)
        {
            rootNodeCheck2 = true;
        }
        if(root->left)
        {      
            l = lowestCommonAncestorHelper(root->left,p,q);
            lVal = l.first;
            node1L = l.second.first;
            node2L = l.second.second;
        }
        if(root->right)
        {
            r = lowestCommonAncestorHelper(root->right,p,q);
            rVal = r.first;
            node1R = r.second.first;
            node2R = r.second.second;
        }
            rootNodeCheck1 = rootNodeCheck1 or node1L or node1R;
            rootNodeCheck2 = rootNodeCheck2 or node2L or node2R;

    
        if(rootNodeCheck2 and rootNodeCheck1 and lVal== nullptr and rVal==nullptr)
        {
        val = root;
        }
    
        if(lVal)
        {
            val = lVal;
        }
        else if(rVal)
        {
            val = rVal;
        }
            return make_pair(val, make_pair(rootNodeCheck1,rootNodeCheck2));

       }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode* val;
    bool rootNodeCheck1, rootNodeCheck2;
    pair<TreeNode*,pair<bool,bool>> ans;
    ans = lowestCommonAncestorHelper(root, p, q);
    val = ans.first;
    rootNodeCheck1 = ans.second.first;
    rootNodeCheck2 = ans.second.second;
    if(rootNodeCheck1 and !rootNodeCheck2)
    {
        return p;
    }
    else if(rootNodeCheck2 and !rootNodeCheck1)
    {
        return q;
    }
    else if(!rootNodeCheck1 and !rootNodeCheck2)
    {
        return nullptr;
    }
    else
    {
        return val;
    }  
        return nullptr;
    }
};
