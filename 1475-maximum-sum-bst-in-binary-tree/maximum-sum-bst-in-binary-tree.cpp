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
    int ans = 0;
    struct Info{
        bool isBST;
        int minVal;
        int maxVal;
        int sum;
    };
    Info dfs(TreeNode* root){
        Info curr;
        if(!root){
            curr.isBST = true;
            curr.minVal = INT_MAX;
            curr.maxVal = INT_MIN;
            curr.sum = 0;
            return curr;
        }
        Info left = dfs(root->left);
        Info right = dfs(root->right);
        if(left.isBST && right.isBST && left.maxVal<root->val && right.minVal>root->val){
            curr.isBST = true;
            curr.minVal = min(left.minVal, root->val);
            curr.maxVal = max(right.maxVal, root->val);
            curr.sum = left.sum + right.sum + root->val;
            ans = max(ans, curr.sum);
        }else{
            curr.isBST = false;
            curr.sum = 0;
            curr.minVal = INT_MIN;
            curr.maxVal = INT_MAX;
        }
        return curr;
    }
    int maxSumBST(TreeNode* root) {
        dfs(root);
        return ans;
        
    }
};