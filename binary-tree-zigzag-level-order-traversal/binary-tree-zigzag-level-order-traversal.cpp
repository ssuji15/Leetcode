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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        
        bool shouldReverse = false;
        
        while(!q.empty()) {
            queue<TreeNode*> temp = q;
            q = {};
            vector<int> result;
            while(!temp.empty()) {
                TreeNode *top = temp.front();
                temp.pop();
                result.push_back(top->val);
                if(top->left != NULL) {
                    q.push(top->left);
                }
                if(top->right != NULL) {
                    q.push(top->right);
                }
            }
            
            if(shouldReverse) {
                reverse(result.begin(),result.end());
            }
            shouldReverse = !shouldReverse;
            ans.push_back(result);
        }
        
        return ans;
    }
};