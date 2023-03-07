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
    int sumOfLeftLeaves(TreeNode* root)
    {
        int sum = 0;
        f(root, sum);
        return sum;
    }

    void f(TreeNode* root, int& sum)
    {
        if (!root) {
            return;
        }
        TreeNode* left = root->left;
        if (left && !left->left && !left->right) {
            sum += left->val;
        }
        f(root->left, sum);
        f(root->right, sum);
    }
};

class Solution1 {
  public:
    int sumOfLeftLeaves(TreeNode* root)
    {
        if (!root) {
            return 0;
        }
        int sum = 0;
        TreeNode* left = root->left;
        if (left && !left->left && !left->right) {
            sum += left->val;
        }
        return sumOfLeftLeaves(root->left)+sumOfLeftLeaves(root->right)+sum;
    }
};