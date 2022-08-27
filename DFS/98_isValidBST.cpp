/*
 * @Author: Liu Jiahui
 * @Date: 2022-08-27 17:02:04
 * @Last Modified by: Liu Jiahui
 * @Last Modified time: 2022-08-27 17:07:40
 */

/*
给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。
有效 二叉搜索树定义如下：
节点的左子树只包含 小于 当前节点的数。
节点的右子树只包含 大于 当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。
*/
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
    bool isValidBST(TreeNode* root)
    {
        vector<int> node;
        in_order(root, node);
        if (node.size() <= 1)
            return true;
        for (int i = 1; i < node.size(); ++i) {
            if (node[i] < node[i - 1])
                return false;
        }
        return true;
    }

    void in_order(TreeNode* root, vector<int>& node)
    {
        if(root==nullptr)
            return;
        in_order(root->left, node);
        node.emplace_back(root->val);
        in_order(root->right, node);
    }
};