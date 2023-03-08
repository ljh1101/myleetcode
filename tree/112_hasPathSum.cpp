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
//错误的逻辑
class Solution {
  public:
    bool hasPathSum(TreeNode* root, int targetSum)
    {
        bool flag = false;
        int sum = 0;
        preOrder(root, targetSum, sum, flag);
        return flag;
    }

    void preOrder(TreeNode* node, const int targetSum, int& sum, bool& flag)
    {
        if (!node) {
            return;
        }
        sum += node->val;
        if (sum > targetSum)
            return;
        if (sum == targetSum) {
            flag = true;
            return;
        }
        if (node->left)
            preOrder(node->left, targetSum, sum, flag);
        if (node->right)
            preOrder(node->right, targetSum, sum, flag);
    }
};
//好方法 我怎么想不到
//非常精妙，
class Solution1 {
  public:
    bool hasPathSum(TreeNode* root, int targetSum)
    {
        if (!root)
            return false;
        if (!root->left && !root->right)
            return targetSum - root->val == 0;
        return hasPathSum(root->left, targetSum - root->val) ||
               hasPathSum(root->right, targetSum - root->val);
    }
};