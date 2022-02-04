class Solution {
public:
    bool canJump(vector<int>& nums) {
        int vector_size = nums.size();
        int max_index = 0;
        for(int i = 0; i < vector_size; i++)
        {
            if(max_index < i)
            {
                return false;
            }
            int curr_index = i + nums[i];
            max_index = max(curr_index, max_index);
        }
        
        return true;
    }
};