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
        
    if (!head || !head->next || k == 0) return head;

        // Step 1: Compute the length of the list
        ListNode* current = head;
        int n = 1; // At least 1 node exists
        while (current->next) {
            current = current->next;
            n++;
        }

        // Step 2: Make the list circular
        current->next = head;

        // Step 3: Find the new head position
        k = k % n; // Effective rotations
        int stepsToNewHead = n - k;

        // Step 4: Break the circle at the new head
        ListNode* newTail = head;
        for (int i = 1; i < stepsToNewHead; i++) {
            newTail = newTail->next;
        }
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};