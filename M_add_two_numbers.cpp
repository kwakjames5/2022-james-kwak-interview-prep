class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result_head = new ListNode(-1);
        ListNode* result_track = result_head;
        int ones, carry, total, val1, val2;
        carry = 0;
        
        while(l1 != NULL || l2 != NULL)
        {
            if(l1 != NULL)
            {
                val1 = l1->val;
                l1 = l1->next;
            }
            else
            {
                val1 = 0;
            }
            
            if(l2 != NULL)
            {
                val2 = l2->val;
                l2 = l2->next;
            }
            else
            {
                val2 = 0;
            }
            
            total = val1 + val2 + carry;
            
            carry = total/10;
            ones = total%10;
            
            ListNode* new_digit = new ListNode(ones);
            result_track->next = new_digit;
            result_track = result_track->next;            
        }
        
        if(carry != 0)
        {
            ListNode* new_digit = new ListNode(carry);
            result_track->next = new_digit;
        }
        
        carry = 0;
        
        return result_head->next;
    }
};