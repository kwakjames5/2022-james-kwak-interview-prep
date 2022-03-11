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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> return_vector;
        
        if(head == NULL)
        {
            return_vector.push_back(NULL);
            return return_vector;
        }
        
        if(head->next == NULL)
        {
            return_vector.push_back(0);
            return return_vector;
        }
        
        while(head != NULL)
        {
            int curr_num = head->val;
            ListNode* head_track = head;
            head_track = head_track->next;
            while(head_track != NULL)
            {
                if(head_track->val > curr_num)
                {
                    head->val = head_track->val;
                    break;
                }
                head_track = head_track->next;
            }
            
            if(head_track == NULL)
            {
                head->val = 0;
            }
            
            return_vector.push_back(head->val);
            
            head = head->next;
        }
        
        return return_vector;
    }
};