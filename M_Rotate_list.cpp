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
         if(head == nullptr) {
            return head; 
         } 
        
        ListNode* tail = head;
        int list_size = 1;
    
        while(tail->next != nullptr) {
            list_size++;
            tail = tail->next;
        }
        
        int k_real = k % list_size;
        tail->next = head;
        
        if(k_real > 0) {
            for(int i = 0; i < list_size - k_real; i++) {
                tail = tail->next;
            }
        }
        
        ListNode* new_head = tail->next;
        tail->next = nullptr;
        
        return new_head;
    }
};