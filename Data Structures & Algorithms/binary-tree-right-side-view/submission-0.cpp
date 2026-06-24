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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) return res;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        while (!q.empty()) {
            auto [node, level] = q.front(); q.pop();

            if (q.empty() || q.front().second != level) {
                res.push_back(node->val);
            }

            if (node->left != nullptr)  q.push({node->left, level + 1});
            if (node->right != nullptr) q.push({node->right, level + 1});
        }
        return res;
    }
};
