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
    void inOrder(TreeNode* node, vector<int>& res)
    {
        if (node == nullptr)
            return;
        inOrder(node->left, res);
        res.emplace_back(node->val);
        inOrder(node->right, res);
    }
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> res;
        inOrder(root, res);
        return res;
    }
};

class Solution1 {
  public:
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode* curr = root;

        while (curr || !st.empty()) {
            if (curr) {
                st.emplace(curr);
                curr = curr->left;
            }
            else {
                curr = st.top();
                st.pop();
                res.emplace_back(curr->val);
                curr = curr->right;
            }
        }

        return res;
    }
};