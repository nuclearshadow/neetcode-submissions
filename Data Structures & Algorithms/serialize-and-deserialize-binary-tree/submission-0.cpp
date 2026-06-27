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

struct ListNode {
    int val, left, right;
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<ListNode> l;
        buildTreeList(root, l);
        auto str = listToStr(l);
        cout << str;
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        auto l = parseList(data);
        return buildTreeFromList(l, 0);
    }

    int buildTreeList(TreeNode* node, vector<ListNode>& l) {
        if (node == nullptr) return -1;
        int idx = l.size();
        l.push_back({ .val = node->val });
        int leftIdx = buildTreeList(node->left, l);
        int rightIdx = buildTreeList(node->right, l);
        l[idx].left = leftIdx;
        l[idx].right = rightIdx;
        return idx;
    }

    string listToStr(vector<ListNode>& l) {
        ostringstream oss;
        for (auto n : l) {
            oss << n.val << " " << n.left << " " << n.right << " ";
        }
        return oss.str();
    }

    vector<ListNode> parseList(string str) {
        istringstream iss(str);
        vector<ListNode> res;
        int val, left, right;
        while (iss >> val >> left >> right) {
            res.push_back({ val, left, right });
        }
        return res;
    }

    TreeNode* buildTreeFromList(vector<ListNode>& l, int idx) {
        if (l.size() <= 0 || idx == -1) return nullptr;
        auto node = new TreeNode(l[idx].val);
        node->left = buildTreeFromList(l, l[idx].left);
        node->right = buildTreeFromList(l, l[idx].right);
        return node;
    }
};
