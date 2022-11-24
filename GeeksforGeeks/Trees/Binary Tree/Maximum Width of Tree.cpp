// Problem Link - https://practice.geeksforgeeks.org/problems/maximum-width-of-tree/1

#define ll long long

/*  Structure of a Binary Tree


struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution {
  public:
    // Function to get the maximum width of a binary tree.
    int getMaxWidth(Node* root) {
        if(root==nullptr)
            return 0;
        ll op = 0, mini = 0, maxi = 0;
        queue<pair<Node*,ll>> q;
        q.push({root,0});
        q.push({nullptr,-1});
        ll ans = 0;
        ll flag = 1;
        while(q.size())
        {
            auto cur = q.front();
            q.pop();
            if(cur.first==nullptr)
            {
                if(q.size()==0)
                    break;
                flag = 1;
                op = 0;
                q.push({nullptr,-1});
                continue;
            }
            op++;
            cur.second -= op;
            mini = min(mini,cur.second);
            maxi = max(maxi,cur.second);
            if(cur.first->left)
                q.push({cur.first->left,2ll*cur.second+1});
            if(cur.first->right)
                q.push({cur.first->right,2ll*cur.second+2});
            ans = max(ans,op);
        }
        return ans;
    }