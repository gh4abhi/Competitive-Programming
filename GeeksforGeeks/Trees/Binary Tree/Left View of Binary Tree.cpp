// Problem Link - https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1

#define ll int
/* A binary tree node

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

//Function to return a list containing elements of left view of the binary tree.

void DFS(Node* root, vector<ll>& ans, ll level)
{
    if(root==nullptr)
        return;
    if(level==ans.size())
        ans.push_back(root->data);
    DFS(root->left,ans,level+1);
    DFS(root->right,ans,level+1);
}

vector<int> leftView(Node *root)
{
   vector<ll> ans;
   DFS(root,ans,0);
   return ans;
}