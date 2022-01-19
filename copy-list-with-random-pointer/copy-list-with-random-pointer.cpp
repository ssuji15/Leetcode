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
        
        Node *start = head, *prev = head, *result;

        while(start != NULL) {
            Node *tmp = new Node(start->val);
            Node *next = start->next;
            tmp->next = next;
            start->next = tmp;
            start = next;
        }
        
        if(head == NULL) {
            start = NULL;
        } else {
            start = head->next;
        }

        while(start != NULL) {
            
            if(prev->random != NULL) {
                start->random = prev->random->next;
            }
            else {
                start->random = NULL;
            }
            
            if(start->next != NULL) {
                prev = start->next;
                start = prev->next;
            }
            else {
                start = NULL;
            }
        }
        
        if(head == NULL) {
            result = NULL;
        } else {
            result = head->next;
        }

        start = head;
        while(start != NULL) {

            Node *next = start->next->next;
            Node *nextClone = NULL;

            if(next != NULL) {
                nextClone = next->next;
            }

            start->next->next = nextClone;
            start->next = next;
            start = next;            
        }
        
        return result;
    }
};
