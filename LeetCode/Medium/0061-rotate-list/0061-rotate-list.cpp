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
    ListNode* rotateRight(ListNode* head, int k) {
        int count = 1;
        if (!head) {
            return nullptr;
        }
        ListNode* current = head;
        while (current->next != nullptr) {
            count++;
            current = current->next;
        }
        current->next = head;
        k = k % count;
        for (int i = 0; i < count - k; i++) {
            current = current->next;
        }
        head = current -> next;
        current->next = nullptr;
        return head;
    }
};