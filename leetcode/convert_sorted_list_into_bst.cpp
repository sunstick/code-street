/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> num;

        while (head) {
            num.push_back(head -> val);
            head = head -> next;
        }

        return sortedArrayToBST(num);
    }

    TreeNode *sortedArrayToBST(vector<int> &num) {
        return bstFromArray(num, 0, num.size() - 1, NULL);
    }

    TreeNode *bstFromArray(vector<int> &array, int left, int right, TreeNode *parent) {
        if (left > right)
            return NULL;
        int mid = (right - left) / 2 + left;

        TreeNode *node = new TreeNode(array[mid]);
        if (parent && parent -> val > node -> val)
            parent -> left = node;
        if (parent && parent -> val < node -> val)
            parent -> right = node;
        bstFromArray(array, left, mid - 1, node);
        bstFromArray(array, mid + 1, right, node);
        return node;
    }
};