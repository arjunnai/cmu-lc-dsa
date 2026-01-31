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
class Solution {
public:
    // merge sort - first do tortoise hare and find midpoint, then cut the
    // linkedlist by using prev pointer
    // then run sortList twice on left half and right half
    // then do 2 sorted list questoin
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode *slow = head, *fast = head;
        ListNode* prev = nullptr;
        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;

            fast = fast->next->next;
        }
        prev->next = nullptr;
        ListNode* leftSort = sortList(head);
        ListNode* rightSort = sortList(slow);
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        while (leftSort && rightSort) {
            if (leftSort->val < rightSort->val) {
                curr->next = leftSort;
                leftSort = leftSort->next;
            } else {
                curr->next = rightSort;
                rightSort = rightSort->next;
            }
            curr = curr->next;
        }
        curr->next = (leftSort != nullptr) ? leftSort : rightSort;
        return dummy->next;
    }
};