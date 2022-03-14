class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int size = nums.size();
        for(int i = 0; i < size; i++) {
            for(int j = i + 1; j < size; j++) {
                int l = j + 1; 
                int r = size - 1;
                int remainder = target - nums[i] - nums[j];
                while(l < r) {
                    if(nums[l] + nums[r] == remainder) {
                        result.push_back(vector<int> {nums[i], nums[j], nums[l], nums[r]});
                        l++;
                        r--;
                        while(l < r && nums[l - 1] == nums[l]) {
                            l++;
                        }
                    } else if (nums[l] + nums[r] > remainder) {
                        --r;
                    } else {
                        ++l;
                    }
                }
                while (j + 1 < size && nums[j] == nums[j + 1]) {
                    j++;
                }
            }
            while (i + 1 < size && nums[i] == nums[i + 1]) {
                i++;
            }
        }
        
        return result;
    }
};