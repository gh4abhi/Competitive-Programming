// Problem Link - https://www.codingninjas.com/codestudio/problems/serialise-deserialise-a-binary-tree_920328?source=youtube&campaign=Striver_Tree_Videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=Striver_Tree_Videos&leftPanelTab=0

#include<bits/stdc++.h>
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

string serializeTree(TreeNode<int> *root)
{
   string ans = "";
        if(root==nullptr)
            return ans;
        queue<TreeNode<int> *> q;
        q.push(root);
        while(q.size())
        {
            TreeNode<int> * cur = q.front();
            q.pop();
            if(cur!=nullptr)
            {
                ans += to_string(cur->data)+',';
                q.push(cur->left);
                q.push(cur->right);
            }
            else
                ans +="#,";
        }
        return ans;

}

TreeNode<int>* deserializeTree(string &serialized)
{
     if(serialized.length()==0)
            return nullptr;
        stringstream s(serialized);
        string str;
        getline(s,str,',');
        TreeNode<int>* root = new TreeNode<int>(stoi(str));
        queue<TreeNode<int>*> q;
        q.push(root);
        while(q.size())
        {
            TreeNode<int>* cur = q.front();
            q.pop();
            getline(s,str,',');
            if(str=="#")
                cur->left=nullptr;
            else
            {
                TreeNode<int>* node = new TreeNode<int>(stoi(str));
                cur->left = node;
                q.push(node);
            }
            getline(s,str,',');
            if(str=="#")
                cur->right=nullptr;
            else
            {
                TreeNode<int>* node = new TreeNode<int>(stoi(str));
                cur->right = node;
                q.push(node);
            }
        }
        return root;
}



