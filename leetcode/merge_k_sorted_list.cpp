/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode dummy(0);
        ListNode *tail = &dummy;
        tail -> next = NULL;

        priority_queue<pair<int, int> > pq;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i])
                pq.push(make_pair(-lists[i] -> val, i));
        }

        while (!pq.empty()) {
            int i = pq.top().second;
            pq.pop();
            tail -> next = lists[i];
            lists[i] = lists[i] -> next;
            tail = tail -> next;
            tail -> next = NULL;
            if (lists[i])
                pq.push(make_pair(-lists[i] -> val, i));
        }

        return dummy.next;
    }
};