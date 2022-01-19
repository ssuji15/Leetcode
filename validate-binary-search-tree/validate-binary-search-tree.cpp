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
    bool check(TreeNode *root, long long minVal, long long maxVal) {

        if(root == NULL) return true;
        
        if(root->val >= minVal && root->val <= maxVal) {
            bool left = check(root->left, minVal, root->val-1L);
            bool right = check(root->right, root->val+1L, maxVal);
            return left && right;
        }
        return false;
    }
    bool isValidBST(TreeNode* root) {
        return check(root, INT_MIN, INT_MAX);
    }
};