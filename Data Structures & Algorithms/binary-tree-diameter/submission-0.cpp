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
    int maxDia = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        findHeight(root);

        return maxDia;
    }
private:
    int findHeight(TreeNode* node){
        if(node == nullptr){
            return 0 ;
        } 
        int leftHeight = findHeight(node->left);
        int rightHeight = findHeight(node->right);

        maxDia = max(maxDia, leftHeight + rightHeight);

        return 1 + max(leftHeight, rightHeight);
    }
};

