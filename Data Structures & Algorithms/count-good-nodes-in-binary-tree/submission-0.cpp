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
    int dfs(TreeNode* root, int maxSoFar){
        if(root == nullptr ){
            return 0;
        }
        int count =0;

        if(root->val >= maxSoFar){
            count = 1;
            maxSoFar = root->val;
        }
        
        int leftCount = dfs(root->left, maxSoFar);
        int rightCount = dfs(root->right,maxSoFar);

        return count + leftCount + rightCount;
    }
        

public:
    int goodNodes(TreeNode* root) {
        return dfs(root,root->val);
    }
};