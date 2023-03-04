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

// 层次遍历做法
class Solution {
  public:
    int maxDepth(TreeNode* root)
    {
        if (!root)
            return 0;
        int depth = 0;
        queue<TreeNode*> q;
        q.emplace(root);
        while (!q.empty()) {
            int num = q.size();
            for (int i = 0; i < num; i++) {
                TreeNode* node = q.front();
                if (node->left) {
                    q.emplace(node->left);
                }
                if (node->right) {
                    q.emplace(node->right);
                }

                q.pop();
            }
            ++depth;
        }
        return depth;
    }
};

// 深度优先遍历做法
// 没想到这种做法，主要是分解的思想，把一个把一个大问题分解为两个小问题，然后依此分解，把树分为左子树和右子树，层高就是左子树和右子树的最大层高+1
class Solution1 {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};
