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
    void recoverTree(TreeNode* root) {
        vector<int>values;
        inorder(root,values);
        sort(values.begin(), values.end());
        int idx=0;
        reassing(root, values, idx);
    }

    void inorder(TreeNode* node, vector<int>& values){
        if(!node)   return;
        inorder(node -> left, values);
        values.push_back(node -> val);
        inorder(node -> right, values);
    }

    void reassing(TreeNode* node, vector<int>& values, int& idx){
        if(!node)   return;
        reassing(node -> left, values, idx);
        node -> val = values[idx++];
        reassing(node -> right, values, idx);   
    }
};