// Problem Link - https://www.interviewbit.com/problems/path-to-given-node/

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
bool DFS(TreeNode* A, vector<ll>& ans, ll B)
{
    if(A==nullptr)
        return false;
    ans.push_back(A->val);
    if(A->val==B)
        return true;
    if(A->left)
        if(DFS(A->left,ans,B))
            return true;
    if(A->right)
        if(DFS(A->right,ans,B))
            return true;
    ans.pop_back();
    return false;
}
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<ll> ans;
    DFS(A,ans,B);
    return ans;
}
