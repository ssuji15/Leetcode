/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *successor;
    void inorderSuccessor(TreeNode *root, TreeNode *p, bool &found) {
        if(root == NULL || successor != NULL) return;
        
        inorderSuccessor(root->left, p, found);
        
        if(found && successor == NULL) {
            successor = root;
            return;
        }
        else if(root == p) {
            found = true;
        }
        
        inorderSuccessor(root->right,p,found);
    }
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        bool found = false;
        successor = NULL;
        inorderSuccessor(root, p, found);
        return successor;
    }
};