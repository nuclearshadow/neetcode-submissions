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
    int goodNodes(TreeNode* root) {
        int count = 0;
        rec(root, INT_MIN, &count);
        return count;
    }

    void rec(TreeNode* node, int pathMax, int* count) {
        if (node == nullptr) return;
        if (node->val >= pathMax) {
            (*count)++;
        }
        rec(node->left, max(node->val, pathMax), count);
        rec(node->right, max(node->val, pathMax), count);
    }
};
