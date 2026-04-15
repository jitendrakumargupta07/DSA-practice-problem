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
    bool hasCycle(ListNode* head) {
        if (head == NULL || head->next == NULL) { return false; } // if head is null or head is the only node
        ListNode* by1 = head; // pointer that traverses by 1 node
        ListNode* by2 = head; // pointer that traverses by 2 nodes
        while (by2->next != NULL && by2->next->next != NULL && by1->next != NULL) { // check if any next node is null
            by1 = by1->next; // traverse 1 node
            by2 = by2->next->next; // traverse 2 nodes
            // eventually if there is a cycle, the two pointers should meet 
            if (by1 == by2) { return true; } // if these pointers are pointing at the same node, there is a cycle
        }
        return false; // no cycle
    }
};