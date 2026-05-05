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
    ListNode *merge(ListNode *left,ListNode *right){
	    ListNode dummy(0);
	    ListNode *tail = &dummy;
	    
	    while(left && right){
	        if(left->val <right->val){
	            tail->next = left;
	            left = left->next;
	        }
	        else{
	            tail->next = right;
	            right = right->next;
	        }
	        tail = tail->next;
	    }
	    if(left) tail->next = left;
	    else tail->next = right;
	    
	    return dummy.next;
	}

    ListNode *getMid(ListNode *head){
	    ListNode *slow = head;
	    ListNode *fast = head->next;
	    while(fast && fast->next){
	        slow = slow->next;
	        fast = fast->next->next;
	    }
	    return slow;
	}

    ListNode* sortList(ListNode* head) {
        if(!head || !head->next){
		    return head;
		}
		//find mid
		ListNode *mid = getMid(head);
		
		//split
		ListNode *right = mid->next;
		mid->next = NULL;
		
		ListNode *left = sortList(head);
		right = sortList(right);
		
		//mearge
		return merge(left,right);
    }
};