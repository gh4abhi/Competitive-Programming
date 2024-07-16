// Problem Statement - https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/

#define ll int

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

    string ans;
    TreeNode* start;
    ll flag;
    ll n;
    void DFS(TreeNode*s, ll &d, unordered_map<ll,TreeNode*> &par, string &str, vector<ll> &vis)
    {
        if(s==nullptr)
            return;
        vis[s->val] = 1;
        if(s->val==d)
        {
            ans  = str;
            flag = 1;
            return;
        }
        if(s->left and vis[s->left->val]==0 and !flag)
            str += "L", DFS(s->left,d,par,str,vis),str.pop_back();
        if(s->right and vis[s->right->val]==0 and !flag)
            str += "R",DFS(s->right,d,par,str,vis),str.pop_back();
        if(par[s->val] and vis[par[s->val]->val]==0 and !flag)
            str += "U",DFS(par[s->val],d,par,str,vis),str.pop_back();
    }

    void makePar(TreeNode* root, ll startValue, unordered_map<ll,TreeNode*> &par, ll &n)
    {
        if(root==nullptr)
            return;
        n+=1;
        if(root->left)
            par[root->left->val] = root;
        if(root->right)
            par[root->right->val] = root;
        if(root->val==startValue)
            start = root;
        makePar(root->left,startValue,par, n);
        makePar(root->right,startValue,par, n);
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        unordered_map<ll,TreeNode*> par;
        flag = 0;
        n = 0;
        makePar(root,startValue,par, n);
        string str = "";
        vector<ll> vis(n+1,0);
        DFS(start,destValue,par,str,vis);
        return ans;
    }
};