class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int min_diff = INT_MAX;
        int output;
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < nums.size() - 2; i++)
        {
            int j = i + 1;
            int k = nums.size() - 1;
            while(j < k)
            {
                int sum_target_diff = nums[i] + nums[j] + nums[k] - target;
                if(abs(sum_target_diff) < min_diff)
                {
                    min_diff = abs(sum_target_diff);
                    output = sum_target_diff + target;
                }
                
                if(sum_target_diff < 0)
                {
                    j++;
                }
                
                if(sum_target_diff > 0)
                {
                    k--;
                }
                
                if(sum_target_diff == 0)
                {
                    return target;
                }
            }
        }
        
        return output;
    }
};

// [-1, -4, 3, 5, 1, -9, -10] target = 3
// [-10, -9, -4, -1, 1, 3, 5]
