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
//下标可以超过数组最大下标用来判断，而迭代器不能
// end()迭代器只想最后一个元素的后一个位置
class Solution {
  public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums)
    {
        return construct(nums.begin(), nums.end());
    }

    TreeNode* construct(const vector<int>::iterator left,
                        const vector<int>::iterator right)
    {
        if (left == right) {
            return nullptr;
        }
        auto it = max_element(left, right);
        auto* node = new TreeNode(*it);
        node->left = construct(left, it);
        node->right = construct(it + 1, right);
        return node;
    }
};