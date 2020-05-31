#include "iostream"
#include "vector"
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> res;
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == nullptr) {
            return res;
        }
        // 中序遍历
        inorderTraversal(root->left);
        res.push_back(root->val);
        inorderTraversal(root->right);
        // 前序遍历
        res.push_back(root->val);
        inorderTraversal(root->left);
        inorderTraversal(root->right);
        // 后序遍历
        inorderTraversal(root->left);
        inorderTraversal(root->right);
        res.push_back(root->val);

        return res;
    }
};