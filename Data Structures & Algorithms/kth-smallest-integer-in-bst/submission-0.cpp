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
    void dfs(TreeNode* root, vector<int>& ans){
        if(root == nullptr){
            return;
        }
        if(root->left != nullptr){
            dfs(root->left, ans);
        }
        ans.push_back(root->val);
        if(root->right){
            dfs(root->right, ans);
        }
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> ans;
        dfs(root, ans);
        for(int i =0;i<=k; i++){
            if(i == k-1){
                return ans[i];
            }
        }
    }
};
