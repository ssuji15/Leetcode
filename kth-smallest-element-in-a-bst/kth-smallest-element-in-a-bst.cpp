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
    int num;
    TreeNode* find(TreeNode *root, int k) {
        
        if(root == NULL) return NULL;
        
        TreeNode *temp = find(root->left, k);
        if(temp != NULL) return temp;
        
        num++;
        if(num == k) {
            return root;
        }

        temp = find(root->right, k);
        return temp;
    }
    
    int kthSmallest(TreeNode* root, int k) {
        num = 0;
        TreeNode *temp = find(root, k);
        return temp->val;
    }
};