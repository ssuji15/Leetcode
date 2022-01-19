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
    ListNode *reverse(ListNode *head) {
        ListNode *prev = NULL;
        while(head != NULL) {
            ListNode *next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        int i;
        ListNode *prev = NULL, *start = head;

        for(i=1;i<left;i++) {
            prev = start;
            start = start->next;
        }
        
        for(;i<right;i++) {
            start = start->next;
        }
        
        ListNode *rightEnd = start->next;
        start->next = NULL;
        
        ListNode *reversedHead;

        if(prev == NULL) {
            reversedHead = reverse(head);
            head->next = rightEnd;
            head = reversedHead;
        }
        else {
            reversedHead = reverse(prev->next);
            prev->next->next = rightEnd;
            prev->next = reversedHead;
        }  
        
        return head;
    }
};