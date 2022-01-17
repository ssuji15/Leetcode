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
    ListNode* reverse(ListNode *head) {
        ListNode *prev = NULL;
        while(head != NULL) {
            ListNode *next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        l1 = reverse(l1);
        l2 = reverse(l2);
        
        int carry = 0;
        
        ListNode *prev = NULL;

        while(l1 != NULL || l2 != NULL) {
            
            int val1 = 0, val2 = 0;

            if(l1 != NULL) {
                val1 = l1->val;
            }
            
            if(l2 != NULL) {
                val2 = l2->val;
            }
            int sum = val1 + val2 + carry;
            carry = sum / 10;
            sum = sum % 10;
            
            ListNode *tmp = new ListNode(sum);
            tmp->next = prev;
            prev = tmp;
            
            if(l1 != NULL) {
                l1 = l1->next;
            }
            
            if(l2 != NULL) {
                l2 = l2->next;
            }
        }
        
        if(carry > 0) {
            ListNode *tmp = new ListNode(carry);
            tmp->next = prev;
            prev = tmp;
        }
        
        return prev;
        
    }
};