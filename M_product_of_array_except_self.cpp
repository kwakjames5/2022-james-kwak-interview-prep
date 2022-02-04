class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> return_vec(nums.size());
        return_vec[0] = 1;
        for(int i = 1; i < nums.size(); i++)
        {
            return_vec[i] = nums[i - 1] * return_vec[i - 1];
        }
        
        int right_product = 1;
        for(int j = nums.size() - 1; j >= 0; j--)
        {
            return_vec[j] *= right_product;
            right_product *= nums[j];
        }
        
        return return_vec;
    }
};