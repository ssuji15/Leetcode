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
    void dfs(TreeNode *target, int distance, int targetDistance, vector<int> &result) {
        if(target == NULL) return;
        if(distance == targetDistance) {
            result.push_back(target->val);
            return;
        }
        dfs(target->left, distance+1, targetDistance, result);
        dfs(target->right, distance+1, targetDistance, result);
    }
    
    bool fillAncestors(TreeNode *root, TreeNode *target, stack<TreeNode*> &st) {
        if(root == NULL) return false;
        st.push(root);
        if(root == target) {
            return true;
        }
        if(fillAncestors(root->left,target,st)) return true;
        if(fillAncestors(root->right,target,st)) return true;
        st.pop();
        return false;
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> result;
        dfs(target,0,k,result);
        stack<TreeNode *> st;
        fillAncestors(root, target, st);
        int curDistance = 0;
        TreeNode *prev = NULL;
        if(!st.empty()) {
            prev = st.top();
            st.pop();
        }
        while(!st.empty()) {
            curDistance++;
            TreeNode *cur = st.top();
            st.pop();
            if(curDistance == k) {
                result.push_back(cur->val);
                break;
            }
            if(cur->left == prev) {
                dfs(cur->right,curDistance+1, k, result);
            }
            else {
                dfs(cur->left,curDistance+1, k, result);
            }
            prev = cur;
        }
        return result;
    }
};