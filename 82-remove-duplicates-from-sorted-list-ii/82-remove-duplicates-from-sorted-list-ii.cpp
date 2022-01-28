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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *start = head, *prev=NULL, *result = NULL;
        
        while(start != NULL) {
            
            ListNode *next = start->next;
            if(next == NULL || start->val != next->val) {
                if(prev == NULL) {
                    result = start;
                    prev = start;
                }
                else {
                    prev->next = start;
                    prev = start;
                }
                start->next = NULL;
            } 
            
            while(next != NULL && next->val == start->val) {
                next = next->next;
            }

            start = next;
        }
        
        return result;
        
        
    }
};