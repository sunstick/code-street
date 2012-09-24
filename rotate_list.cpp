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
    ListNode *rotateRight(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!head) return NULL;
        ListNode *node = head;
        ListNode *last;
        int len = 0;

        while (node) {
            len++;
            last = node;
            node = node -> next;
        }
        last -> next = head;

        k = len - k % len - 1;

        node = head;

        for (int i = 0; i < k; i++)
            node = node -> next;

        ListNode *res = node -> next;
        node -> next = NULL;

        return res;
    }
};