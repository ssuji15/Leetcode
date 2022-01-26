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
    TreeNode *prev;
    TreeNode* flattenTree(TreeNode *root) {

        if(root == NULL) return NULL; 
        
        if(prev != NULL) {
            prev->right = root;
        }
        prev = root;
        TreeNode *right = root->right;
        
        root->right = flattenTree(root->left);
        root->left = NULL;

        flattenTree(right);
        return root;
    }
    void flatten(TreeNode* root) {
        
        prev=NULL;
        flattenTree(root);
    }
};