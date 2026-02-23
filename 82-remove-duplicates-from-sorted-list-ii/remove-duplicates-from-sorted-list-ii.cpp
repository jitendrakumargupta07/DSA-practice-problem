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
        ListNode *ret = nullptr;
        ListNode *ret_current = nullptr;

        for (ListNode *current = head, *prev = nullptr; current; prev = current, current = current->next) {
            if (((prev && current->val != prev->val) || !prev) &&
                ((current->next && current->next->val != current->val) || !current->next)) {
                if (!ret) {
                    ret = new ListNode(current->val);
                    ret_current = ret;
                } else {
                    ret_current->next = new ListNode(current->val);
                    ret_current = ret_current->next;
                }
            }
        }
        
        return ret;
    }
};