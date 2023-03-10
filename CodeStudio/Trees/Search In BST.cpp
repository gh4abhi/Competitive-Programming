// Problem Link - https://www.codingninjas.com/codestudio/problems/search-in-bst_1402878?source=youtube&campaign=Striver_Tree_Videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=Striver_Tree_Videos&leftPanelTab=0

/*
    Following is the Binary Tree node structure:

    class BinaryTreeNode {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };
*/

bool searchInBST(BinaryTreeNode<int> *root, int x) {
    BinaryTreeNode<int> * op = root;
    while(op)
    {
        if(op->data>x)
            op = op->left;
        else if(op->data<x)
            op = op->right;
        else
            return true;
    }
    return false;
}