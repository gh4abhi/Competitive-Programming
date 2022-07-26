// Problem Link - https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

#define ll int

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        if(root==nullptr)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size())
        {
            TreeNode* cur = q.front();
            q.pop();
            if(cur!=nullptr)
            {
                ans += to_string(cur->val)+',';
                q.push(cur->left);
                q.push(cur->right);
            }
            else
                ans +="#,";
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.length()==0)
            return nullptr;
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(q.size())
        {
            TreeNode* cur = q.front();
            q.pop();
            getline(s,str,',');
            if(str=="#")
                cur->left=nullptr;
            else
            {
                TreeNode* node = new TreeNode(stoi(str));
                cur->left = node;
                q.push(node);
            }
            getline(s,str,',');
            if(str=="#")
                cur->right=nullptr;
            else
            {
                TreeNode* node = new TreeNode(stoi(str));
                cur->right = node;
                q.push(node);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));