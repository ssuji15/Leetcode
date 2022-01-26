/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {

        queue<Node*> q;
        if(root != NULL) {
            q.push(root);
        }
        
        while(!q.empty()) {
            
            queue<Node*> temp = q;
            q = {};
            Node *prev = NULL;
            while(!temp.empty()) {

                Node *front = temp.front();
                temp.pop();

                if(front->left != NULL) q.push(front->left);
                if(front->right != NULL) q.push(front->right);
                
                if(prev != NULL) {
                    prev->next = front;
                }
                
                prev = front;
            }
        }
        return root;
    }
};