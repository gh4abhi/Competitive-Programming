// Problem Link - https://www.interviewbit.com/problems/recover-binary-search-tree/

#define ll int
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class recover
{
    private:
    TreeNode* first, *middle, *prev, *last;
    vector<ll> ans;
    public:
    recover()
    {
        first = middle = last = nullptr;
        prev = new TreeNode(INT_MIN);
    }
    void inorder(TreeNode* root)
    {
        if(root==nullptr)
        return;
        inorder(root->left);
        if(prev!=nullptr and root->val<prev->val)
        {
        if(first==nullptr)
        first = prev, middle = root;
            else
                last = root;
        }
        prev = root;
        inorder(root->right);
    }
    
    vector<ll> answer(TreeNode* root)
    {
        inorder(root);
        if(first and last)
        ans.push_back(min(first->val,last->val)), ans.push_back(max(first->val,last->val));
        else if(first and middle)
        ans.push_back(min(first->val,middle->val)), ans.push_back(max(first->val,middle->val));
        return ans;
    }
};
vector<int> Solution::recoverTree(TreeNode* root) {
    vector<ll> ans;
    recover bst = recover();
    ans = bst.answer(root);
    return ans;
}
