class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0)
        {
            return 0;
        }
        
        int length = 0;
        int curr_track = 1;
        
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] != nums[i - 1])
            {
                curr_track = 1;
                length++;
                nums[length] = nums[i];
            }
            else if(nums[i] == nums[i - 1] && curr_track < 2)
            {
                length++;
                curr_track++;
                nums[length] = nums[i];
            }
        }
        
        // + 1 bc the first element was not counted b/c length starts as 0 initially
        return length + 1;
    }
};