// Problem Link - https://leetcode.com/problems/linked-list-in-binary-tree/

#define ll int

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    
    bool check(ListNode* head, TreeNode* root)
    {
        if(head==nullptr)
            return true;
        if(root==nullptr)
            return false;
        if(root->val!=head->val)
            return false;
        return check(head->next,root->left) or check(head->next,root->right);
    }
    
    bool DFS(ListNode* head, TreeNode* root)
    {
        if(root==nullptr)
            return false;
        if(root->val==head->val)
            if(check(head,root))
                return true;
        return DFS(head,root->left) or DFS(head,root->right);
    }
    
    bool isSubPath(ListNode* head, TreeNode* root) {
        return DFS(head,root);
    }
};