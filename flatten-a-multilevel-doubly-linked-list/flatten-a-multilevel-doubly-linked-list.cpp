/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* myFlatten(Node *head) {
        
        Node *prev = NULL, *curr = head;

        while(curr != NULL) {

            Node *next = curr->next;
            
            if(curr->child != NULL) {
                
                curr->next = curr->child;
                curr->next->prev = curr;
                curr->child = NULL;
                
                Node *lastChild = myFlatten(curr->next);
                lastChild->next = next;

                if(next != NULL) {
                    next->prev = lastChild;
                }
                
                prev = lastChild;
            }
            else {
                prev = curr;
            }
            curr = next;
        }
        
        return prev;
    }
    Node* flatten(Node* head) {
        myFlatten(head);
        return head;
    }
};