
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        if (postorder.size() == 0) {
            return nullptr;
        }
        int rootVal = postorder[postorder.size() - 1];
        TreeNode* root = new TreeNode(rootVal);

        int index = 0;
        for (; index < inorder.size(); index++)
            if (inorder[index] == rootVal)
                break;
        vector<int> leftInorder(inorder.begin(), inorder.begin() + index);
        vector<int> rightInorder(inorder.begin() + index + 1, inorder.end());

        postorder.resize(postorder.size() - 1);
        vector<int> leftPostorder(postorder.begin(), postorder.begin() + index);
        vector<int> rightPostorder(postorder.begin() + index, postorder.end());
        root->left = buildTree(leftInorder, leftPostorder);
        root->right = buildTree(rightInorder, rightPostorder);

        return root;
    }
};