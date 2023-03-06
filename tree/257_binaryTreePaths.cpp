#include <string>
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
    vector<string> binaryTreePaths(TreeNode* root)
    {
        vector<string> res;
        preOrder(root, res, "");
        return res;
    }
    void preOrder(TreeNode* node, vector<string>& res, string str)
    {
        str += to_string(node->val);
        if (!node->left && !node->right) {  //判断是不是叶子节点
            res.emplace_back(str);
            return;
        }
        if (node->left)
            preOrder(node->left, res, str + "->");
        if (node->right)
            preOrder(node->right, res, str + "->");
    }
};
