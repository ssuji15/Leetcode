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
    int preOrderIdx;
    TreeNode* buildBinaryTree(vector<int>& preorder,vector<int> nodes) {

        if(nodes.size() == 0) return NULL;
        
        int node = preorder[preOrderIdx];
        int i=0;
        vector<int> left, right;

        while(nodes[i] != node) {
            left.push_back(nodes[i]);
            i++;
        }
        
        i++;
        while(i < nodes.size()) {
            right.push_back(nodes[i]);
            i++;
        }
        
        TreeNode *root = new TreeNode(preorder[preOrderIdx]);
        preOrderIdx++;
        root->left = buildBinaryTree(preorder, left);
        root->right = buildBinaryTree(preorder, right);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preOrderIdx = 0;
        return buildBinaryTree(preorder, inorder);
    }
};