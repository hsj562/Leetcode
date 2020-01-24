/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// Solution 1: (reverse linked list)
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
// Solution 2: (hash set)
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode *> s;
        while(head) {
            if(s.find(head) != s.end()) {   // in the set!
                return true;
            } else {
                s.insert(head);
            }
            head = head->next;
        }
        return false;
    }
};
// Solution 3: (two ptr: fast and slow)
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head || !head->next) {return false;}
        ListNode *fast = head, *slow = head;
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow) {return true;}
        }
        return false;
    }
};