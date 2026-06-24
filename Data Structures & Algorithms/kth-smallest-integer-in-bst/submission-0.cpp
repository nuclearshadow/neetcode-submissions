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
    int kthSmallest(TreeNode* root, int k) {
        int count = 0, minVal = 0;
        inorder(root, k, &count, &minVal);
        return minVal;
    }

    bool inorder(TreeNode* root, int k, int* count, int* minVal) {
        if (root == nullptr) return true;
        if (!inorder(root->left, k, count, minVal)) return false;
        (*count)++;
        if (*count == k) {
            *minVal = root->val;
        }
        if (!inorder(root->right, k, count, minVal)) return false;
        return true;
    }
};
