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
        // first k remainder size of list gives actual times we need to really
        // torate the list start off by finding size of list. in the same loop
        // set the last element to point to head to make it a circular loop
        // once thats done calculate real k
        // iterate till count - k since thats where the new tail will be and
        // then cut it off so that returned pointer points to the new head of the list

        int count = 1;
        if (!head) {
            return nullptr;
        }
        ListNode* current = head;
        while (current->next != nullptr) {
            count++;
            current = current->next;
        }
        k = k % count;
        if(k == 0){
            return head;
        }
        current->next = head;

        for (int i = 0; i < count - k; i++) {
            current = current->next;
        }
        head = current->next;
        current->next = nullptr;
        return head;
    }
};