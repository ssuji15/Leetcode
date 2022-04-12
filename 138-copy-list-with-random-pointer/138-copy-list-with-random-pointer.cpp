/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if(head == NULL) return NULL;
        
        Node *temp = head, *newHead = NULL;
        while(temp != NULL) {
            Node *next = temp->next;
            Node *newNode = new Node(temp->val);
            if(newHead == NULL) {
                newHead = newNode;
            }
            temp->next = newNode;
            newNode->next = next;
            temp = next;
        }       
        Node *oldNode = head, *newNode = head->next;
        
        while(oldNode != NULL) {
            if(oldNode->random != NULL) {
                newNode->random = oldNode->random->next;
            }
            else {
                newNode->random = NULL;
            }
            
            if(oldNode->next != NULL) {
                oldNode = oldNode->next->next;
            }
            
            if(newNode->next != NULL) {
                newNode = newNode->next->next;
            }
        }
        
        oldNode = head, newNode = head->next;
        
        while(oldNode != NULL) {
            
            if(newNode != NULL) {
                oldNode->next = newNode->next;
            }
            else {
                oldNode->next = NULL;
            }
            
            oldNode = oldNode->next;
            
            if(oldNode != NULL) {
                newNode->next = oldNode->next;
            }
            else {
                newNode->next = NULL;
            }
            
            newNode = newNode->next;
        }
        
        return newHead;
        
    }
};