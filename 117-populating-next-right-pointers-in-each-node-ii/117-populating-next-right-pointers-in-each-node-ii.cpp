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
    Node *leftMost, *prev;
    void process(Node *root) {
        if(root != NULL) {
            if(prev != NULL) {
                prev->next = root;
            }
            else {
                leftMost = root;
            }
            prev = root;
        }
    }
    Node* connect(Node* root) {
       
        leftMost = root;
        while(leftMost != NULL) {
            Node *curr = leftMost;
            leftMost = NULL;
            prev = NULL;
            
            while(curr != NULL) {
                process(curr->left);
                process(curr->right);
                curr = curr->next;
            }
            
        }
        return root;
    }
};