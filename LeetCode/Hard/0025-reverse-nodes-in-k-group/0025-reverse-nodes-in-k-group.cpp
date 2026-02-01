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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;
        ListNode* dummy = new ListNode(0, head);
        ListNode* groupPrev = dummy;
        while (true) {
            ListNode* tail = groupPrev;
            for (int i = 0; i < k; i++) {
                tail = tail->next;
                if (!tail)
                    return dummy->next;
            }
            ListNode* currentGroupHead = groupPrev->next;
            groupPrev->next = reverse(currentGroupHead, tail);
            groupPrev = currentGroupHead;
        }
    }
    ListNode* reverse(ListNode* head, ListNode* tail) {
        ListNode* temp = tail->next;
        ListNode* prev = temp;
        ListNode* curr = head;
        
        while (curr != temp) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return tail;
    }
};