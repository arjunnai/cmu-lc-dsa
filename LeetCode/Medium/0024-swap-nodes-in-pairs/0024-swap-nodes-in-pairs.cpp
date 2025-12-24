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
    ListNode* swapPairs(ListNode* head) {
        // iterative
        //  if (head == nullptr || head->next == nullptr) {
        //      return head;
        //  }
        //  ListNode* tempHead = head->next;
        //  head->next = tempHead->next;
        //  tempHead->next = head;

        // while (head->next != nullptr && head->next->next != nullptr) {
        //     ListNode* first = head->next;
        //     ListNode* second = head->next->next;
        //     first->next = second->next;
        //     second->next = first;
        //     head->next = second;
        //     head = first;
        // }
        // return tempHead;

        // recursion
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* second = head->next;
        head->next = swapPairs( second->next );
        second->next = head;
        return second;
    }
};