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
class BSTIterator {
private: 
    TreeNode* ptr;
    vector<int>v;
    int i;
    void inorder(TreeNode* ptr, vector<int> &v){
        if(ptr == NULL) return;

        inorder(ptr->right, v);
        v.push_back(ptr->val);
        inorder(ptr->left,v);
    }

public:
    BSTIterator(TreeNode* root) {
        ptr = root;
        inorder(root, v);
        i=v.size();
    }
    
    int next() {
        i--;
        return v[i];
    }
    
    bool hasNext() {
        if(i>0)    return true;
        else return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */