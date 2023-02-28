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

class Solution {
  public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if (root)
            q.emplace(root);
        while (!q.empty()) {
            int num = q.size();
            vector<int> v;
            for (int i = 0; i < num; i++) {
                TreeNode* node = q.front();
                if (node->left) {
                    q.emplace(node->left);
                }
                if (node->right) {
                    q.emplace(node->right);
                }
                v.emplace_back(node->val);
                q.pop();
            }
            res.emplace_back(v);
        }
        return res;
    }
};