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
    int maxDia = 0;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return maxDia;
    }

    int height(TreeNode* root) {
        if (root == nullptr) return 0;
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        if (leftHeight + rightHeight > maxDia) {
            maxDia = leftHeight + rightHeight;
        }
        return 1 + max(leftHeight, rightHeight);
    }
};
