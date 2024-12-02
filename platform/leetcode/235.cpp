/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 在二分搜索树上寻找Lowset Common Ancestor

class Solution {
private:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    };

public:
    // recursive
    TreeNode* lowestCommonAncestorA(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root->val > p->val && root->val > q->val) return lowestCommonAncestor(root->left, p, q);
        if (root->val < p->val && root->val < q->val) return lowestCommonAncestor(root->right, p, q);
        return root;
    }

    // iterative
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (true) {
            if (root->val > p->val && root->val > q->val) root = root->left;
            else if (root->val < p->val && root->val < q->val) root = root->right;
            else return root;  // 第一次与其中一个相同或者p,q分立在root两边
        }
    }
};
