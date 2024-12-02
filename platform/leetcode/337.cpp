#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <vector>

using namespace std;

// N=10000 所需时间复杂度<=O(n^sqrt(n))

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    unordered_map<TreeNode*, int> memo;

    // 返回root树的最大价值
    int backtracking(TreeNode* root) {
        // 递归终止条件
        if (root == nullptr) {
            return 0;
        }
        if (memo.find(root) != memo.end()) {
            return memo[root];
        }
        // 调用递归
        TreeNode *L = (*root).left;
        TreeNode *R = (*root).right;
        TreeNode *LL = L == nullptr ? nullptr : (*L).left;
        TreeNode *LR = L == nullptr ? nullptr : (*L).right;
        TreeNode *RL = R == nullptr ? nullptr : (*R).left;
        TreeNode *RR = R == nullptr ? nullptr : (*R).right;
        int tmp = (*root).val + backtracking(LL) + backtracking(LR) + backtracking(RL) + backtracking(RR);

        int ret = max(backtracking(L) + backtracking(R), tmp);
        memo.insert(make_pair(root, ret));
        return ret;
    }

    // 返回两个元素的数组，res[0]表示不包含root节点的最大结果，res[1]表示可能包含root节点的最大结果
    vector<int> tryRob(TreeNode* root) {
        if (root == nullptr)
            return vector<int>(2, 0);

        vector<int> resultL = tryRob(root->left);
        vector<int> resultR = tryRob(root->right);
        vector<int> res(2, 0);
        res[0] = resultL[1] + resultR[1];  // res[0]表示不包含root节点的最大结果
        res[1] = max(res[0], root->val + resultL[0] + resultR[0]);  // res[1]表示可能包含root节点的最大结果
        return res;
    }

// 这题dp可以用后序遍历，因为后序遍历中孩子节点肯定都遍历过了。
public:
    int rob_memo(TreeNode* root) {
        memo.clear();
        return backtracking(root);
    }

    // 树形DP
    int rob(TreeNode* root) {
        vector<int> result = tryRob(root);
        return max(result[0], result[1]);
    }

    int rob_dfs(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode* pre = NULL;
        TreeNode* cur = root;
        while (cur != nullptr || !stk.empty()) {
            while (cur != nullptr) {
                stk.push(cur);
                cur = cur->left;
            }
            cur = stk.top();
            stk.pop();

            // 决定在根本就没有右子树 或者 右边已经遍历过了的情况下执行后序遍历操作访问结点，否则访问右子树
            if (cur->right == nullptr || pre == cur->right) {
                // cout << "遍历：" << cur->val << endl;
                int t1 = cur->val;
                if (cur->left != nullptr && cur->left->left != nullptr)
                    t1 += cur->left->left->val;
                if (cur->left != nullptr && cur->left->right != nullptr)
                    t1 += cur->left->right->val;
                if (cur->right != nullptr && cur->right->left != nullptr)
                    t1 += cur->right->left->val;
                if (cur->right != nullptr && cur->right->right != nullptr)
                    t1 += cur->right->right->val;
                int t2 = (cur->left==nullptr ? 0 : cur->left->val) + (cur->right==nullptr ? 0 : cur->right->val);
                cur->val = max(t1, t2);
                pre = cur;
                cur = nullptr;
            } else {
                stk.push(cur);
                cur = cur->right;
            }
        }
        return root->val;
    }
};

int main()
{
    TreeNode LL(1), LR(3), RR(1), L(4, &LL, &LR), R(5, nullptr, &RR), node(3, &L, &R);
    cout<<Solution().rob(&node)<<endl;
    return 0;
}
