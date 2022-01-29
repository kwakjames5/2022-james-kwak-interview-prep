class Solution {
public:
    int minPairSum(vector<int>& nums) {
        // add smallest number and the largest number in the vector and continue until no more numbers left
        sort(nums.begin(), nums.end());
        int result = 0;
        int nums_size = nums.size();
        for(int i = 0; i < nums.size() / 2; i++) {
            result = max(result, nums[i] + nums[nums_size - i - 1]);
        }
        return result;
    }
};