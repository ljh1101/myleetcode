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

//看题解做出来的， 最小深度不是最大把最大深度反过来就行的，因为一个节点只要有一个孩子节点，那他就还要继续遍历
// 所以，最后总结出来，有一个孩子节点，就向这个孩子节点继续遍历，不考虑另一个孩子没有；有两个孩子节点，都遍历。
class Solution {
  public:
    int minDepth(TreeNode* root)
    {
        if (!root)
            return 0;
        if (root->left && !root->right)
            return minDepth(root->left) + 1;
        else if (!root->left && root->right)
            return minDepth(root->right) + 1;
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};