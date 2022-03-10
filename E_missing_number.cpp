class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int result;
        
        // nums_sum is the total of the ints in nums vector
        int nums_sum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            nums_sum += nums[i];
        }
        
        // since we want to find the missing element, compare_sum is the sum of the
        // nums vector if it were not missing a element. this is achieved by using <= instead of <
        int compare_sum = 0;
        for(int j = 0; j <= nums.size(); j++)
        {
            compare_sum += j;
        }
        
        // compare_sum - nums_sum is the hypothetical sum minus the real sum, leaving behind the missing element
        result = compare_sum - nums_sum;
        
        return result;
        
        /*vector<int> nums_store;
        
        for(int i = 0; i < nums.size(); i++)
        {
            nums_store.push_back(nums[i]);
        }
        
        for(int j = 0; j <= nums_store.size(); j++)
        {
            if(find(nums_store.begin(), nums_store.end(), j) == nums_store.end())
            {
                return j;
            }
        }
        
        return -1;
        */
    }
};