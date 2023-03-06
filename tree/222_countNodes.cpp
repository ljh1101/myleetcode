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

// 递归
class Solution {
  public:
    int countNodes(TreeNode* root)
    {
        if (!root)
            return 0;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};

//递归+二分
class Solution1 {
  public:
    int countNodes(TreeNode* root)
    {
        if (!root)
            return 0;
        int left = countHeight(root->left);
        int right = countHeight(root->right);
        if (left == right)
            return countNodes(root->right) + (1 << left);
        else
            return countNodes(root->left) + (1 << right);
    }

    int countHeight(TreeNode* root)
    {
        int height = 0;
        while (root) {
            root = root->left;
            ++height;
        }
        return height;
    }
};
