class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for(int i = 0; i < nums.size(); i++) {
            if(i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int l = i + 1; 
            int r = nums.size() - 1;
            while(l < r) {
                int temp_sum = nums[i] + nums[l] + nums[r];
                if(temp_sum > 0) {
                    r--;
                } else if(temp_sum < 0) {
                    l++;
                } else {
                    result.push_back(vector<int> {nums[i], nums[l], nums[r]});
                    l++;
                    while (nums[l] == nums[l-1] && l < r) {
                        l++;
                    }
            }
        }
        
        return result;
    }
};