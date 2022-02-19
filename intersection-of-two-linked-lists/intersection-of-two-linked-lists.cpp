/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int count1 = 0, count2=0;
        ListNode *temp = headA, *temp2 = headB;
        
        while(temp != NULL) {
            count1++;
            temp = temp->next;
        }
        
        temp = headB;
        while(temp != NULL) {
            count2++;
            temp = temp->next;
        }
        
        temp = headA;
        
        if(count1 > count2) {
            while(count1 != count2) {
                temp = temp->next;
                count1--;
            }
        }
        else {
            while(count1 != count2) {
                temp2 = temp2->next;
                count2--;
            }
        }
        
        while(temp != NULL && temp2 != NULL) {
            if(temp == temp2) return temp;
            temp = temp->next;
            temp2 = temp2->next;
        }
        
        return NULL;
        
    }
};