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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        auto left = p->val < q->val ? p : q;
        auto right = p->val > q->val ? p : q;
        if (left->val <= root->val && root->val <= right->val) {
            return root;
        } else if (left->val < root->val && right->val < root->val) {
            return lowestCommonAncestor(root->left, p, q);
        } else if (left->val > root->val && right->val > root->val) {
            return lowestCommonAncestor(root->right, p, q);
        }
        throw;
    }
};
