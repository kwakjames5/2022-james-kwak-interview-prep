class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> curr;
        
        subset_helper(nums, 0, curr, result);
        
        return result;
    }
    
    void subset_helper(vector<int>& nums, int i, vector<int>& curr, vector<vector<int>>& result) {
        result.push_back(curr);
        for(int j = i; j < nums.size(); j++) {
            curr.push_back(nums[j]);
            subset_helper(nums, j + 1, curr, result);
            curr.pop_back();
        }
    }
};