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
        // before x
        ListNode* before_head = new ListNode(0);
        ListNode* before = before_head;
        
        // after x
        ListNode* after_head = new ListNode(0);
        ListNode* after = after_head;
        while(head != NULL)
        {
            // create a before list and a after list
            if(head->val < x)
            {
                before->next = head;
                before = before->next;
            }
            else
            {
                after->next = head;
                after = after->next;
            }
            
            // progress head after
            head = head->next;
        }
        
        // end the after list
        after->next = NULL;
        // before connects to after here, after_head is not directly used because of how it was declared
        before->next = after_head->next;
    
        return before_head->next;
        
    }
};