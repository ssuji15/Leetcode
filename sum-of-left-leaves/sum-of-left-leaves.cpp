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
    int ans;
    void findAns(TreeNode *root, int val) {
        if(root == NULL) return;
        if(val == 1 && root->left == NULL && root->right == NULL) {
            ans += root->val;
            return;
        }
        findAns(root->left, 1);
        findAns(root->right, -1);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        ans = 0;
        findAns(root,-1);
        return ans;
    }
};