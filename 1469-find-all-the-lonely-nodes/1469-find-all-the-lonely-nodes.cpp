/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void getLonelyNodes(TreeNode *root, vector<int> &result) {
        if(root == NULL) return;
        if(root->left == NULL && root->right != NULL) {
            result.push_back(root->right->val);
        }
        if(root->right == NULL && root->left != NULL) {
            result.push_back(root->left->val);
        }
        getLonelyNodes(root->left, result);
        getLonelyNodes(root->right, result);
    }
    vector<int> getLonelyNodes(TreeNode* root) {
        vector<int> result;
        getLonelyNodes(root, result);
        return result;
    }
};