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
    vector<int> rightSideView(TreeNode* root) {
        
        queue<TreeNode*> q;
        vector<int> result;
        
        if(root != NULL) {
            q.push(root);
        }
        
        while(!q.empty()) {
            
            queue<TreeNode*> temp = q;
            q={};
            TreeNode *prev = NULL;

            while(!temp.empty()) {
                TreeNode *node = temp.front();
                temp.pop();
                
                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);

                prev = node;
            }
            if(prev != NULL) {
                result.push_back(prev->val);
            }
        }
        return result;
    }
};