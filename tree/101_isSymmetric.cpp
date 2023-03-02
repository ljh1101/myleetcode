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
// 想着中序遍历一下，看遍历出来的数组是不是对称的，如果左子树跟右子树的都是同一个数字而在不对称的位置，这个方法就失效了。
class Solutionfail {
    void inOrder(TreeNode* node, vector<int>& res)
    {
        if (node == nullptr)
            return;
        inOrder(node->left, res);
        res.emplace_back(node->val);
        inOrder(node->right, res);
    }

  public:
    bool isSymmetric(TreeNode* root)
    {
        vector<int> arr;
        inOrder(root, arr);
        int len = arr.size();
        if (len % 2 == 0)
            return false;
        for (int i = 0, j = len - 1; i < j; i++, j--)
            if (arr[i++] != arr[j--])
                return false;
        return true;
    }
};

// 还是得便利才行
class Solution {
    bool cmp(TreeNode* p, TreeNode* q)
    {
        if (!p && !q)
            return true;
        else if (p && q)
            if (p->val == q->val)
                return cmp(p->left, q->right) && cmp(p->right, q->left);
        return false;
    }

  public:
    bool isSymmetric(TreeNode* root)
    {
        return cmp(root->left, root->right);
    }
};