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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> inmap;
        for (int i = 0; i < inorder.size(); i++) {
            inmap[inorder[i]] = i;
        }
        return buildTreeRec(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inmap);
    }

    TreeNode* buildTreeRec(
        vector<int>& preorder, int preStart, int preEnd, 
        vector<int>& inorder, int inStart, int inEnd,
        map<int, int>& inmap
    ) {
        if (preStart > preEnd || inStart > inEnd) return nullptr;
        int rootVal = preorder[preStart];
        int rootInIdx = inmap[rootVal];
        return new TreeNode(
            rootVal,
            buildTreeRec(
                preorder, preStart + 1, preStart + rootInIdx - inStart,
                inorder, inStart, rootInIdx - 1,
                inmap
            ),
            buildTreeRec(
                preorder, preStart + 1 + rootInIdx - inStart, preEnd,
                inorder, rootInIdx + 1, inEnd,
                inmap
            )
        );
    }
};
