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
    unordered_map<TreeNode*, int> cache;
    int getChildrens(TreeNode *root) {
        int value = 0;
        if(root == NULL) return 0;
        if(root->left != NULL) {
            value += cache[root->left];
        }
        if(root->right != NULL) {
            value += cache[root->right];
        }
        return value;
    }
    int rob(TreeNode* root) {
        if(root == NULL) return 0;
        
        if(cache.find(root) != cache.end()) {
            return cache[root];
        }
        
        int value1 = rob(root->left) + rob(root->right);
        int value2 = getChildrens(root->left) + getChildrens(root->right) + root->val;
        cache[root] = max(value1, value2);
        return cache[root];
    }
};