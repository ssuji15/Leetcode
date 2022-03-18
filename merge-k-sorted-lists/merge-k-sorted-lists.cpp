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
struct MyCompare {
    public:
    bool operator()(ListNode *a, ListNode *b) {
        return a->val > b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,MyCompare> pq;
        for(int i=0;i<lists.size();i++) {
            if(lists[i] != NULL) {
                pq.push(lists[i]);
            }
        }
        ListNode *head = NULL, *prev = NULL;
        while(!pq.empty()) {
            ListNode *temp = pq.top();
            pq.pop();
            ListNode *next = temp->next;
            if(head == NULL) {
                head = temp;
                prev = temp;
            }
            else {
                prev->next = temp;
                temp->next = NULL;
                prev = temp;
            }
            if(next != NULL) {
                pq.push(next);
            }
        }
        return head;
    }
};