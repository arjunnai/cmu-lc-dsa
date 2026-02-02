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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* curr = dummy;

        while (curr->next && curr->next->next) {
            if (curr->next->val == curr->next->next->val) {
                int valu = curr->next->val;
                while (curr->next && curr->next->val == valu) {
                    curr->next = curr->next->next;
                }
            }else{
                curr = curr->next;
            }
        }
        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};