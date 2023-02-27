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

// 递归法

class Solution {
  public:
    void preOrder(TreeNode* node, vector<int>& res)
    {
        if (node == nullptr)
            return;
        res.emplace_back(node->val);
        preOrder(node->left, res);
        preOrder(node->right, res);
    }
    vector<int> preorderTraversal(TreeNode* root)
    {
        vector<int> res;
        preOrder(root, res);
        return res;
    }
};

// 迭代法

class Solution1 {
  public:
    vector<int> preorderTraversal(TreeNode* root)
    {
        vector<int> res;
        stack<TreeNode*> st;
        if (root)
            st.emplace(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            res.emplace_back(node->val);
            if (node->right)
                st.emplace(node->right);
            if (node->left)
                st.emplace(node->left);
        }
        return res;
    }
};