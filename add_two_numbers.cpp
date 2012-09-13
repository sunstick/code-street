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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode dummy(0);
        ListNode *tail = &dummy;

        int carry = 0;

        while (l1 || l2 || carry) {
            int a = l1 ? l1 -> val : 0;
            int b = l2 ? l2 -> val : 0;

            int bit = a + b + carry;
            carry = bit / 10;
            bit = bit % 10;
            tail -> next = new ListNode(bit);
            tail = tail -> next;
            l1 = l1 ? l1 -> next : l1;
            l2 = l2 ? l2 -> next : l2;
        }

        return dummy.next;
    }
};