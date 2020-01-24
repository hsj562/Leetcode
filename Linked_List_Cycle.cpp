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
    bool hasCycle(ListNode *head) {
        if(!head || !head->next) {
            return false;
        }
        ListNode *cur = head;
        ListNode *prev, *pprev = NULL;
        while(cur->next) {
            prev = cur;
            cur = cur->next;
            prev->next = pprev;
            pprev = prev;
        }
        /** it goes back to head if there's a cycle **/
        if(cur == head) {
            return true;
        }
        return false;
    }
};