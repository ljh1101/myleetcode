
#include <algorithm>
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

class Solution {
  public:
    bool isBalanced(TreeNode* root)
    {
        if (!root)
            return true;
        int left = countHeight(root->left);
        int right = countHeight(root->right);
        if (abs(left - right) <= 1)
            return isBalanced(root->left) && isBalanced(root->right);
        else
            return false;
    }

    int countHeight(TreeNode* root)
    {
        if (!root)
            return 0;
        int left = countHeight(root->left);
        int right = countHeight(root->right);
        return max(left, right) + 1;
    }
};
