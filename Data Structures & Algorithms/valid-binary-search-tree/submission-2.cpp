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
    bool isValidBST(TreeNode* root) {
        vector<int> inorder;
        buildInorder(root, &inorder);
        return isSorted(inorder);
    }

    void buildInorder(TreeNode* root, vector<int>* res) {
        if (root == nullptr) return;
        buildInorder(root->left, res);
        res->push_back(root->val);
        buildInorder(root->right, res);
    }

    bool isSorted(const vector<int>& a) {
        if (a.size() <= 1) return true;
        for (int i = 1; i < a.size(); i++) {
            if (a[i] <= a[i-1]) return false;
        }
        return true;
    }
};
