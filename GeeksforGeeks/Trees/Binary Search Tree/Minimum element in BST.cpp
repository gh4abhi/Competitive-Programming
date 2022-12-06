// Problem Link - https://practice.geeksforgeeks.org/problems/minimum-element-in-bst/1?page=1&company[]=Microsoft&category[]=Tree&sortBy=submissions

int minValue(Node* root) {
    if(root==nullptr)
        return -1;
    Node* op = root;
    while(op->left)
        op = op->left;
    return op->data;
}