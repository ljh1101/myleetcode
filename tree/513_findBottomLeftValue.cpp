#include <queue>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right)
    {
    }
};
// 自己想出的方法 效率低 时间复杂度 O（logn*logn）
class Solution {
  public:
    int findBottomLeftValue(TreeNode* root)
    {
        TreeNode* node = root;
        int res = node->val;
        while (node->left || node->right) {
            int l = maxDepth(node->left);
            int r = maxDepth(node->right);
            node = l >= r ? node->left : node->right;
            res = node->val;
        }
        return res;
    }

    int maxDepth(TreeNode* root)
    {
        if (root == nullptr)
            return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

// 广度优先遍历（层次遍历）， 节点加入队列的时候先加右子树，再加左子树。
// 要发掘题目树的性质
class Solution1 {
  public:
    int findBottomLeftValue(TreeNode* root)
    {
        int res;
        queue<TreeNode*> q;
        q.emplace(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            if (node->right) {
                q.emplace(node->right);
            }
            if (node->left) {
                q.emplace(node->left);
            }
            q.pop();
            res = node->val;
        }
        return res;
    }
};