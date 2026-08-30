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
    // DFS returns {isBST, minimum, maximum, sum}
    // We use a struct to keep it clear.
    struct Info {
        bool isBST;
        int mn;   // minimum value in this subtree
        int mx;   // maximum value in this subtree
        int sum;  // sum of all values in this subtree
    };

    int best = 0;  // global result

    Info dfs(TreeNode* root) {
        // Null node represents a valid empty "BST".
        if (!root) return {true, INT_MAX, INT_MIN, 0};

        Info left  = dfs(root->left);
        Info right = dfs(root->right);

        // Valid BST if both children are BSTs and
        // root value fits between left's max and right's min.
        // (BST property: strictly greater than all left, strictly less than all right)
        if (left.isBST && right.isBST
            && root->val > left.mx
            && root->val < right.mn) {

            int sum = root->val + left.sum + right.sum;
            best = max(best, sum);

            int mn = min(root->val, left.mn);
            int mx = max(root->val, right.mx);
            return {true, mn, mx, sum};
        }

        // Not a valid BST; return a marker that can't combine with anything
        return {false, 0, 0, 0};
    }

    int maxSumBST(TreeNode* root) {
        dfs(root);
        return best;
    }
};