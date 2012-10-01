/*
  Check if a list is palindrome. For example, 1 2 3 2 1.
  Method 1: use front back split to split the lists into two parts. Reverse the back part and compare it with the first part to see if they are the same.
  Method 2: recursive method, doesn't need to change the content of the original list. Recommended and used in this file.
 */
#include "list_util.h"

bool is_palindrome(ListNode **left, ListNode *right) {
    if (!right)
        return true;
    bool flag = is_palindrome(left, right -> next);

    if (!flag) return false;
    if ((*left) -> value != right -> value) return false;
    *left = (*left) -> next;
    return true;
}

void test() {
	ListNode *a = NULL;

    push(&a, 0);
    push(&a, 1);
    push(&a, 1);
    push(&a, 0);

    head = a;
    print_list(head);
    cout << is_palindrome(&a, a) << endl;
    print_list(head);
}