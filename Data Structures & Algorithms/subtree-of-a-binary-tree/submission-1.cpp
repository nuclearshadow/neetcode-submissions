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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr && subRoot == nullptr) {
            return true;
        }
        if (root != nullptr && subRoot != nullptr) {
            if (root->val == subRoot->val
                && isSameTree(root->left, subRoot->left)
                && isSameTree(root->right, subRoot->right)
            ) {
                return true;
            } else {
                return isSubtree(root->left, subRoot)
                    || isSubtree(root->right, subRoot);
            }
        }
        return false;
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        return p == nullptr && q == nullptr 
            || p != nullptr && q != nullptr 
            && p->val == q->val
            && isSameTree(p->left, q->left) 
            && isSameTree(p->right, q->right);
    } 
};
