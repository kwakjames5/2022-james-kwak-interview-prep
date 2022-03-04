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
    ListNode* merge(ListNode* l, ListNode* r)
    {
        // return node will be used to return the merged list
        ListNode* return_node = new ListNode(0);
        
        // curr is used to traverse through the merged list as we make it
        ListNode* curr = return_node;
        
        // while both of the lists still have nodes
        while(l != NULL && r != NULL)
        {
            // add to the return_node list by adding the smaller values first to create a sorted list
            if(l->val < r->val)
            {
                curr->next = l;
                l = l->next;
            }
            else
            {
                curr->next = r;
                r = r->next;
            }
            
            curr = curr->next;
        }
        
        if(l != NULL)
        {
            curr->next = l;
            l = l->next;
        }
        
        if(r != NULL)
        {
            curr->next = r;
            r = r->next;
        }
        
        return return_node->next;
    }
    
    ListNode* sortList(ListNode* head) 
    {
        // if the list does not exist or cannot be sorted
        if(head == NULL || head->next == NULL)
        {
            return head;
        }
        
        ListNode* temp = head;
        ListNode* slow = head;
        ListNode* fast = head;
        
        // head is the head of the first half of the list
        // temp is the end of the first half of the list
        // slow is the head of the second half of the list
        // fast is the end of the second half of the list
        while(fast != NULL && fast->next != NULL)
        {
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // since temp is now the end of the first half of the list,
        // it should no longer have a node after it
        
        temp->next = NULL;
        
        ListNode* left = sortList(head);
        ListNode* right = sortList(slow);
        
        return merge(left, right);
    }
};