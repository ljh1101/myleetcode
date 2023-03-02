#include <algorithm>
#include <stack>
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
    void postOrder(TreeNode* node)
    {
        if (node == nullptr)
            return;

        postOrder(node->left);
        postOrder(node->right);
        TreeNode* left = node->left;
        TreeNode* right = node->right;
        node->left = right;
        node->right = left;
    }
    TreeNode* invertTree(TreeNode* root) {
        TreeNode* node = root;
        postOrder(node);
        
        return root;
    }
};