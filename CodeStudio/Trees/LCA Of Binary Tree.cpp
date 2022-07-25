// Problem Link - https://www.codingninjas.com/codestudio/problems/920541?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#define ll int

/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

ll DFS(TreeNode<int> *root, ll x, ll y)
{
    if(root==nullptr)
        return -1;
    if(root->data==x or root->data==y)
        return root->data;
    ll lef = DFS(root->left,x,y);
    ll rig = DFS(root->right,x,y);
    if(lef==-1)
        return rig;
    else if(rig==-1)
        return lef;
    else
        return root->data;
}

int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
    return DFS(root,x,y);
}