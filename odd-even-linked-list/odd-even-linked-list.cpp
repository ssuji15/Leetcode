/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode *evenHead = NULL, *evenPrev, *curr = head, *prev;
        while(curr != NULL) {
            ListNode *next = curr->next;
            
            if(next != NULL) {
                curr->next = next->next;
            }
            
            if(evenHead == NULL) {
                evenHead = next;
                evenPrev = next;
            }
            else {
                evenPrev->next = next;
                evenPrev = next;
            }
            prev = curr;
            curr = curr->next;
        }

        if(prev != NULL) {
            prev->next = evenHead;
        }
        
        return head;
    }
};

// 1 2 3 4 5 6