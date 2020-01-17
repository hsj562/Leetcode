class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        /** Note that how to new a struct in C++ **/

        ListNode *head = new ListNode(0);
        ListNode *cur = head;

        int carry = 0;

        /** Note the infinite loop or early break **/

        while( l1 != NULL || l2 != NULL ) {
            int sum = carry;
            if(l1 != NULL) {
                sum += l1->val;
            }
            if(l2 != NULL) {
                sum += l2->val;
            }
            carry = sum / 10;
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
            if(l1 != NULL) {
                l1 = l1->next;
            }
            if(l2 != NULL) {
                l2 = l2->next;
            }
        }
        
        /** Note that the last carry **/

        if(carry > 0) {
            ListNode *new_digit = new ListNode(1);
            cur->next = new_digit;
        }

        /** Note that it should return head->next **/

        return head->next;
    }
};