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
    bool findNode(TreeNode* root, TreeNode* current, int target){
        if(root == NULL){
            return false;
        }
        if(root-> val == target && root != current){
            return true;
        }
        return findNode(root -> left, current, target)|| findNode(root -> right, current, target);
    }

    bool dfs(TreeNode* root, TreeNode* current, int k){
        if(current == NULL){
            return false;
        }
        if (findNode(root, current, k - current->val)) {
            return true;
        }
        return dfs(root, current -> left, k) || dfs(root, current -> right, k);
    }

    bool findTarget(TreeNode* root, int k) {
        return dfs(root, root,k);
    }
};