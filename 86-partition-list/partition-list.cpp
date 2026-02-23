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
    ListNode* partition(ListNode* head, int x) {
        ListNode* l1 = new ListNode(); 
        ListNode* l2 = new ListNode();  
        ListNode* l1_curr = l1;        
        ListNode* l2_curr = l2;         
        ListNode* temp = head;

        while (temp) {
            if (temp->val < x) {
                l1_curr->next = new ListNode(temp->val);
                l1_curr = l1_curr->next;  
            } else {
                l2_curr->next = new ListNode(temp->val);
                l2_curr = l2_curr->next;  
            }
            temp = temp->next;
        }

        l1_curr->next = l2->next;
        return l1->next;  
    }
};