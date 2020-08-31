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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !(head->next))return head;
        ListNode *odd = head;
        ListNode *even = head->next;
        ListNode * curr_o = odd;
        ListNode * curr_e = even;
        while(curr_e){
        	if(curr_e->next){
        		curr_o->next = curr_e->next;
        	}
        	else{
        		curr_o -> next = even;
        		return odd;
        	}
        	curr_o = curr_o->next;
        	curr_e->next = curr_o ->next;
        	curr_e = curr_e->next;
        }
        curr_o->next = even;
        return odd;
    }
};