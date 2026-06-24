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
        return buildTreeRec(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }

    TreeNode* buildTreeRec(
        vector<int>& preorder, int preStart, int preEnd, 
        vector<int>& inorder, int inStart, int inEnd
    ) {
        if (preStart > preEnd || inStart > inEnd) return nullptr;
        int rootVal = preorder[preStart];
        int rootInIdx;
        for (int i = inStart; i <= inEnd; i++) {
            if (inorder[i] == rootVal) {
                rootInIdx = i;
                break;
            }
        }
        return new TreeNode(
            rootVal,
            buildTreeRec(
                preorder, preStart + 1, preStart + rootInIdx - inStart,
                inorder, inStart, rootInIdx - 1
            ),
            buildTreeRec(
                preorder, preStart + 1 + rootInIdx - inStart, preEnd,
                inorder, rootInIdx + 1, inEnd
            )
        );
    }

};
