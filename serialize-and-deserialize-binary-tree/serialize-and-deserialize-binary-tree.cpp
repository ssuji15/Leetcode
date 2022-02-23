/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void serialize(TreeNode *root, string &str) {
        if(root == NULL) {
            str += "#,";
        }
        else {
            str += to_string(root->val) + ",";
            serialize(root->left, str);
            serialize(root->right,str);
        }
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str = "";
        serialize(root, str);
        return str;
    }
    
    TreeNode* deserialize(queue<string> &nums) {
        if(nums.empty()) return NULL;
        string front = nums.front();
        nums.pop();
        if(front.compare("#") == 0) {
            return NULL;
        }
        TreeNode *root = new TreeNode(stoi(front));
        root->left = deserialize(nums);
        root->right = deserialize(nums);
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> nums;
        stringstream datastream(data);
        string temp;
        while(getline(datastream,temp,',')) {
            nums.push(temp);
        }
        return deserialize(nums);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));