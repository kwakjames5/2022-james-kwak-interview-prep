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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* head_counter = head;
        int list_size = 0;
        
        ListNode* remove_node = head;
        ListNode* temp = NULL;
        
        while(head_counter != NULL)
        {
            list_size++;
            head_counter = head_counter->next;
        }
        
        if(list_size < n)
        {
            return NULL;
        }
        else if(list_size == n)
        {
            return head->next;
        }
        else
        {
            for(int i = 0; i < list_size - n; i++)
            {
                temp = remove_node;
                remove_node = remove_node->next;
            }
            temp->next = remove_node->next;
            return head;
        }
    }
};