class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int i = 0;
        while(i < nums.size())
        {
            int curr = i;
            int curr_check = curr + 1;
            while(curr_check < nums.size() && nums[curr_check - 1] == nums[curr_check] - 1)
            {
                curr_check++;
            }
            if(curr_check - 1 == curr)
            {
                res.push_back(to_string(nums[curr]));
            }
            else
            {
                string temp;
                temp += (to_string(nums[curr]) + "->" + to_string(nums[curr_check - 1]));
                res.push_back(temp);
            }
            
            
            i = curr_check;
        }
        
        
        return res;
    }
};