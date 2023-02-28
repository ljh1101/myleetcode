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
    void postOrder(TreeNode* node, vector<int>& res)
    {
        if (node == nullptr)
            return;

        postOrder(node->left, res);
        postOrder(node->right, res);
        res.emplace_back(node->val);
    }
    vector<int> postorderTraversal(TreeNode* root)
    {
        vector<int> res;
        postOrder(root, res);
        return res;
    }
};

class Solution1 {
  public:
    vector<int> postorderTraversal(TreeNode* root)
    {
        vector<int> res;
        stack<TreeNode*> st;
        if (root)
            st.emplace(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            res.emplace_back(node->val);
            if (node->left)
                st.emplace(node->left);
            if (node->right)
                st.emplace(node->right);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};