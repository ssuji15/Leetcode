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
    void construct(TreeNode *root, string &s) {
        if(root == NULL) {
            s += '#';
            return;
        }
        
        s += root->val;
        construct(root->left, s);
        construct(root->right, s);
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string s1 = "", s2 = "";
        construct(root, s1);
        construct(subRoot, s2);
        return s1.find(s2) != std::string::npos;
    }
};
