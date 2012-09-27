/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
*/

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
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!head) return head;

        ListNode dummy(0);

        ListNode *tail = &dummy;
        ListNode *node = head;
        ListNode *next = head -> next;
        bool flag = false;

        while (next) {
            if (node -> val == next -> val) {
                flag = true;
                node -> next = next -> next;
                delete next;
                next = node -> next;
            } else {
                if (flag) {
                    delete node;
                } else {
                    tail -> next = node;
                    tail = tail -> next;
                    tail -> next = NULL;
                }
                node = next;
                next = next -> next;
                flag = false;
            }
        }

        if (!flag) tail -> next = node;

        return dummy.next;
    }
};
