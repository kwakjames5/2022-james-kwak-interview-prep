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
    ListNode* swapPairs(ListNode* head) {
        
        ListNode* new_head = new ListNode(0);
        new_head->next = head;
        
        ListNode* list_track = new_head;
    
        while(list_track->next != NULL && list_track->next->next != NULL)
        {
            ListNode* swap_node_1 = list_track->next;
            ListNode* swap_node_2 = list_track->next->next;
            swap_node_1->next = swap_node_2->next;
            list_track->next = swap_node_2;
            list_track->next->next = swap_node_1;
            list_track = list_track->next->next;
        }
        
        return new_head->next;
    }
};