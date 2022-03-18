class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // sort(nums.begin(), nums.end());
        // reverse(nums.begin(), nums.end());
        // for(int i = 0; i < nums.size(); i++) {
        //     std::cout << nums[i] << std::endl;
        // }
        
//         int KthLargest;
//         int i = 0;
//         int k_count = 0;
//         int prev;
//         while(i < nums.size()) {
//             if(k_count == k) {
//                 break;
//             }
            
//             if(nums[i] != prev) {
//                 prev = nums[i];
//                 k_count++;
//                 i++;
//             }
//             else if(nums[i] == prev) {
//                 i++;
//             }            
//         }
        
//         return nums[i];
        priority_queue<int, vector<int>, greater<int>> priority_q;
        for (int num : nums) {
            priority_q.push(num);
            if (priority_q.size() > k) {
                priority_q.pop();
            }
        }
        return priority_q.top();
    }
};