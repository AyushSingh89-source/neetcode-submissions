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
private:
    bool dfs(TreeNode* root, long min_val, long max_val) {

        if (root == nullptr) {
            return true;
        }
        
        if (root->val <= min_val || root->val >= max_val) {
            return false;
        }
        bool isLeftValid = dfs(root->left, min_val, root->val);
        bool isRightValid = dfs(root->right, root->val, max_val);
        
        return isLeftValid && isRightValid;
    }

public:
    bool isValidBST(TreeNode* root) {
        return dfs(root, LONG_MIN, LONG_MAX);
    }
};