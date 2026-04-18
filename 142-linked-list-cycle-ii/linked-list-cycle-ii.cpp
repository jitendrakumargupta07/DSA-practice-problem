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
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) return nullptr; // no cycle if the list is empty or has only one node
        
        ListNode *tortoise = head, *hare = head;
        while (hare && hare->next) {
            tortoise = tortoise->next;
            hare = hare->next->next;
            if (tortoise == hare) { // cycle detected
                hare = head;
                while (tortoise != hare) {
                    tortoise = tortoise->next;
                    hare = hare->next;
                }
                return hare; // found the node where the cycle begins
            }
        }
        return nullptr; // no cycle
    }
};